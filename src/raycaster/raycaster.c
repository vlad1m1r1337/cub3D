/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:26 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/28 15:57:48 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img.addr + (y * mlx->img.line_length + \
			x * (mlx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_wall_ceil(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H / 2)
		{
			my_mlx_pixel_put(mlx, x, y, rgb_to_hex(153, 171, 255));
			y++;
		}
		while (y < H)
		{
			my_mlx_pixel_put(mlx, x, y, rgb_to_hex(53, 52, 50));
			y++;
		}
		x++;
	}
}

void	calculate_dist(t_mlx *mlx, int x)
{
	double cameraX = 2 * x / (double)W - 1; //x-coordinate in camera space
	
	mlx->ray_dir_x = mlx->dir_x + mlx->plane_x * cameraX;
	mlx->ray_dir_y = mlx->dir_y + mlx->plane_y * cameraX;
	
	mlx->map_x = (int)(mlx->pos_x);
	mlx->map_y = (int)(mlx->pos_y);

	mlx->delta_dist_x = (mlx->ray_dir_x == 0) ? 1e30 : fabs(1 / mlx->ray_dir_x);
	mlx->delta_dist_y = (mlx->ray_dir_y == 0) ? 1e30 : fabs(1 / mlx->ray_dir_y);
}

// void	preparing_to_dda(t_mlx *mlx)
// {
	
// }

void raycasting(t_mlx *mlx)
{
	for (int x = 0; x < W; x++)
	{
		calculate_dist(mlx, x);

		int step_x;
		int step_y;

		int hit = 0;
		int side;

		if(mlx->ray_dir_x < 0)
		{
			step_x = -1;
			mlx->side_dist_x = (mlx->pos_x - mlx->map_x) * mlx->delta_dist_x;
		}
		else
		{
			step_x = 1;
			mlx->side_dist_x = (mlx->map_x + 1.0 - mlx->pos_x) * mlx->delta_dist_x;
		}
		if (mlx->ray_dir_y < 0)
		{
			step_y = -1;
			mlx->side_dist_y = (mlx->pos_y - mlx->map_y) * mlx->delta_dist_y;
		}
		else
		{
			step_y = 1;
			mlx->side_dist_y = (mlx->map_y + 1.0 - mlx->pos_y) * mlx->delta_dist_y;
		}

		while (hit == 0)
		{
			if(mlx->side_dist_x < mlx->side_dist_y)
			{
				mlx->side_dist_x += mlx->delta_dist_x;
				mlx->map_x += step_x;
				side = 0;
			}
			else
			{
				mlx->side_dist_y += mlx->delta_dist_y;
				mlx->map_y += step_y;
				side = 1;
			}
			if(mlx->worldMap[mlx->map_x][mlx->map_y] == '1') hit = 1;
		}

		if(side == 0) mlx->perp_wall_dist = (mlx->side_dist_x - mlx->delta_dist_x);
		else          mlx->perp_wall_dist = (mlx->side_dist_y - mlx->delta_dist_y);

		//Calculate height of line to draw on screen
		int line_height = (int)(H / mlx->perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int draw_start = -line_height / 2 + H / 2;
		if(draw_start < 0) draw_start = 0;
		int draw_end = line_height / 2 + H / 2;
		if(draw_end >= H) draw_end = H - 1;
		
		
		double wallX; //where exactly the wall was hit
		if(side == 0) wallX = mlx->pos_y + mlx->perp_wall_dist * mlx->ray_dir_y;
		else          wallX = mlx->pos_x + mlx->perp_wall_dist * mlx->ray_dir_x;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)(texWidth));
		if(side == 0 && mlx->ray_dir_x > 0) texX = texWidth - texX - 1;
		if(side == 1 && mlx->ray_dir_y < 0) texX = texWidth - texX - 1;

		double step = 1.0 * texHeight / line_height;
		double texPos = (draw_start - H / 2 + line_height / 2) * step;

		char	*dst;
		while (draw_start < draw_end)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			dst = mlx->img_sprites[1].addr + (texY * \
				mlx->img_sprites[1].line_length + \
				texX * \
				(mlx->img_sprites[1].bits_per_pixel / 8));
			my_mlx_pixel_put(mlx, x, draw_start++, *(unsigned int *)dst);
		}
	}
}
