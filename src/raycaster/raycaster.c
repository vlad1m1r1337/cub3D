/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:26 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/29 18:34:32 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	preparing_to_dda(t_mlx *mlx)
{
	mlx->hit = 0;
	if(mlx->ray_dir_x < 0)
	{
		mlx->step_x = -1;
		mlx->side_dist_x = (mlx->pos_x - mlx->map_x) * mlx->delta_dist_x;
	}
	else
	{
		mlx->step_x = 1;
		mlx->side_dist_x = (mlx->map_x + 1.0 - mlx->pos_x) * mlx->delta_dist_x;
	}
	if (mlx->ray_dir_y < 0)
	{
		mlx->step_y = -1;
		mlx->side_dist_y = (mlx->pos_y - mlx->map_y) * mlx->delta_dist_y;
	}
	else
	{
		mlx->step_y = 1;
		mlx->side_dist_y = (mlx->map_y + 1.0 - mlx->pos_y) * mlx->delta_dist_y;
	}
}

void	dda(t_mlx *mlx)
{
	while (mlx->hit == 0)
	{
		if (mlx->side_dist_x < mlx->side_dist_y)
		{
			mlx->side_dist_x += mlx->delta_dist_x;
			mlx->map_x += mlx->step_x;
			mlx->side = 0;
		}
		else
		{
			mlx->side_dist_y += mlx->delta_dist_y;
			mlx->map_y += mlx->step_y;
			mlx->side = 1;
		}
		if (mlx->worldMap[mlx->map_x][mlx->map_y] == '1')
			mlx->hit = 1;
	}
}

void	calc_draw_start_end(t_mlx *mlx)
{
	if(mlx->side == 0)
		mlx->perp_wall_dist = (mlx->side_dist_x - mlx->delta_dist_x);
	else
		mlx->perp_wall_dist = (mlx->side_dist_y - mlx->delta_dist_y);

	mlx->line_height = (int)(H / mlx->perp_wall_dist);
	mlx->draw_start = -mlx->line_height / 2 + H / 2;
	
	if(mlx->draw_start < 0)
		mlx->draw_start = 0;
	mlx->draw_end = mlx->line_height / 2 + H / 2;
	if(mlx->draw_end >= H)
		mlx->draw_end = H - 1;
}
