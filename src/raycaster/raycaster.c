/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:26 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/28 12:08:58 by vgribkov         ###   ########.fr       */
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

void raycasting(t_mlx *mlx)
{
	for (int x = 0; x < W; x++)
	{
		double cameraX = 2 * x / (double)W - 1;
		double raydir_x = mlx->dir_x + mlx->plane_x * cameraX;
		double raydir_y = mlx->dir_y + mlx->plane_y * cameraX;
		
		int mapX = (int)mlx->pos_x;
		int mapY = (int)mlx->pos_y;

		double sideDistX;
		double sideDistY;

		double deltaDistX = (raydir_x == 0) ? 1e30 : ft_abs(1 / raydir_x);
		double deltaDistY = (raydir_y == 0) ? 1e30 : ft_abs(1 / raydir_y);

		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;
		
		if(raydir_x < 0)
		{
			stepX = -1;
			sideDistX = (mlx->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - mlx->pos_x) * deltaDistX;
		}
		if(raydir_y < 0)
		{
			stepY = -1;
			sideDistY = (mlx->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - mlx->pos_y) * deltaDistY;
		}
		
		while(hit == 0)
		{
			
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}

			if(mlx->worldMap[mapX][mapY] == '1') hit = 1;
		}
		
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = (int)(H / (perpWallDist));

		int drawStart = -lineHeight / 2 + H / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + H / 2;
		if(drawEnd >= H) drawEnd = H - 1;

		int color = rgb_to_hex(0, 0, 255);
		if(side == 1) {color = color / 2;}

		double wallX;
		if (side == 0)
			wallX = mlx->pos_y + perpWallDist * raydir_y;
		else
			wallX = mlx->pos_x + perpWallDist * raydir_x;
		wallX -= floor(wallX);

		int tex_x = (int)(wallX * (double)texWidth);
		if (side == 0 && raydir_x > 0)
			tex_x = texWidth - tex_x - 1;
		if (side == 1 && raydir_y < 0)
			tex_x = texWidth - tex_x - 1;

		int step = texHeight / lineHeight;
		double texPos = (drawStart - H / 2 + lineHeight / 2) * step;
		char *dst;

		while (++drawStart < drawEnd)
		{
			int tex_y = (int)texPos & (texHeight - 1);
			texPos += step;
			dst = mlx->img_sprites[0].addr + (tex_y * mlx->img_sprites[0].line_length + tex_x * (mlx->img_sprites[0].bits_per_pixel / 8));
			my_mlx_pixel_put(mlx, x, drawStart, *(unsigned int *)dst);
		}
	}
}
