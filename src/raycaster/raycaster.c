/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:26 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/26 18:58:10 by vgribkov         ###   ########.fr       */
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
		//calculate ray position and direction
		double cameraX = 2 * x / (double)W - 1; //x-coordinate in camera space
		double raydir_x = mlx->dir_x + mlx->plane_x * cameraX;
		double raydir_y = mlx->dir_y + mlx->plane_y * cameraX;
		//which box of the map we're in
		int mapX = (int)mlx->pos_x;
		int mapY = (int)mlx->pos_y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		double deltaDistX = (raydir_x == 0) ? 1e30 : ft_abs(1 / raydir_x);
		double deltaDistY = (raydir_y == 0) ? 1e30 : ft_abs(1 / raydir_y);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
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
		//perform DDA
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
			//Check if ray has hit a wall
			if(mlx->worldMap[mapX][mapY] == '1') hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - pos_x + (1 - stepX) / 2) / raydir_x for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(H / (perpWallDist));

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + H / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + H / 2;
		if(drawEnd >= H) drawEnd = H - 1;

		int color = rgb_to_hex(0, 0, 255);
		if(side == 1) {color = color / 2;}

		double wallX; //where exactly the wall was hit
		if(side == 0)
			wallX = mlx->pos_y + perpWallDist * raydir_y;
		else
			wallX = mlx->pos_x + perpWallDist * raydir_x;
		wallX -= floor(wallX);

		int tex_x = (int)(wallX * (double)texWidth);
		if(side == 0 && raydir_x > 0) tex_x = texWidth - tex_x - 1;
		if(side == 1 && raydir_y < 0) tex_x = texWidth - tex_x - 1;

		int step =  1.0 * texHeight / lineHeight;
		double texPos = (drawStart - H / 2 + lineHeight / 2) * step;
		char	*dst;

		while(++drawStart < drawEnd)
		{
			int tex_y = (int)texPos & (texHeight - 1);
			texPos += step;
			dst = mlx->img_sprites[0].addr + (tex_y * mlx->img_sprites[0].line_length + tex_x * (mlx->img_sprites[0].bits_per_pixel / 8));
			my_mlx_pixel_put(mlx, x, drawStart, *(unsigned int *)dst);
		}
	}
}
