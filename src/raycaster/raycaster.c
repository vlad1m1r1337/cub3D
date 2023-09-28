/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:26 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/28 14:40:22 by vgribkov         ###   ########.fr       */
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
		double cameraX = 2 * x / (double)W - 1; //x-coordinate in camera space
		double rayDirX = mlx->dir_x + mlx->plane_x * cameraX;
		double rayDirY = mlx->dir_y + mlx->plane_y * cameraX;

		int mapX = (int)(mlx->pos_x);
		int mapY = (int)(mlx->pos_y);

		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (mlx->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - mlx->pos_x) * deltaDistX;
		}
		if(rayDirY < 0)
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
			//jump to next map square, either in x-direction, or in y-direction
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

		//Calculate height of line to draw on screen
		int lineHeight = (int)(H / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + H / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + H / 2;
		if(drawEnd >= H) drawEnd = H - 1;
		
		double wallX; //where exactly the wall was hit
		if(side == 0) wallX = mlx->pos_y + perpWallDist * rayDirY;
		else          wallX = mlx->pos_x + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)(texWidth));
		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
		if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

		double step = 1.0 * texHeight / lineHeight;
		double texPos = (drawStart - H / 2 + lineHeight / 2) * step;

		int	color = rgb_to_hex(0, 0, 255);
		if(side == 1) {color = color / 2;}
		char	*dst;
		while (drawStart < drawEnd)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			dst = mlx->img_sprites[0].addr + (texY * \
				mlx->img_sprites[0].line_length + \
				texX * \
				(mlx->img_sprites[0].bits_per_pixel / 8));
			my_mlx_pixel_put(mlx, x, drawStart++, *(unsigned int *)dst);
		}
	}
}
