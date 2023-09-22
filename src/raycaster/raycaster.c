#include "../../includes/cub3d.h"

void	draw_wall_ceil(t_mlx *mlx)
{
	int x;

	x = 0;
	while (x < W)
	{
		int y = 0;
		while (y < H / 2)
		{
			my_pixel_put(mlx, x, y, rgb_to_hex(153, 171, 255));//  небо
			y++;
		}
		while (y < H)
		{
			my_pixel_put(mlx, x, y, rgb_to_hex(53, 52, 50));// пол
			y++;
		}
		x++;
	}
}

void raycasting(t_mlx *mlx)
{
	draw_wall_ceil(mlx);
	for (int x = 0; x < W; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)W - 1; //x-coordinate in camera space
		double rayDirX = mlx->dirX + mlx->planeX * cameraX;
		double rayDirY = mlx->dirY + mlx->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)mlx->posX;
		int mapY = (int)mlx->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (mlx->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - mlx->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (mlx->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - mlx->posY) * deltaDistY;
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
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(H / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + H / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + H / 2;
		if(drawEnd >= H) drawEnd = H - 1;

		int color = rgb_to_hex(0, 0, 255);
		if(side == 1) {color = color / 2;}
		while(++drawStart < drawEnd)
			my_pixel_put(mlx, x, drawStart, color);
	}
}

// void loadImage(void **texture, unsigned long *tw, unsigned long *th, char *filename)
// {
// 	*texture = mlx_xpm_file_to_image(mlx, filename, tw, th);
// }

// void	texture(t_mlx *mlx)
// {
// 	void	*texture[1];
// 	unsigned long tw;
// 	unsigned long th;

// 	loadImage(&texture[0], &tw, &th, "pics/bluestone.xpm");
// }