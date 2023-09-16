#include "../include/cube3d.h"

//#define mapWidth 24
//#define mapHeight 24

#define mapWidth 6
#define mapHeight 6

#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
		{
				{1,1,1,1,1,1},
				{1,0,0,0,0,1},
				{1,0,0,0,0,1},
				{1,0,0,0,0,1},
				{1,0,1,0,0,1},
				{1,1,1,1,1,1},
		};

//int worldMap[mapWidth][mapHeight]=
//		{
//				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//		};

void raycasting(t_mlx *mlx)
{
	for (int x = 0; x < W; x++)
	{
		for (int i = 0; i < H / 2; i++)
			my_pixel_put(mlx, x, i, rgb_to_hex(153, 171, 255));//  небо
		for (int i = H / 2; i < H; i++)
			my_pixel_put(mlx, x, i, rgb_to_hex(53, 52, 50));// пол
	}
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

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

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
			if(worldMap[mapX][mapY] > 0) hit = 1;
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

void moving(t_mlx *mlx)
{
	double moveSpeed = 0.1;
	double rotSpeed = 0.03;
	if (mlx -> w)// W
	{
		double tempX;
		double tempY;

		tempX = mlx->posX + mlx->dirX * moveSpeed;
		tempY = mlx->posY + mlx->dirY * moveSpeed;

		if (worldMap[(int)tempX][(int)tempY] == 0)
		{
			mlx->posX = tempX;
			mlx->posY = tempY;
		}
	}
	else if (mlx -> s)// S
	{
		double tempX;
		double tempY;

		tempX = mlx->posX - mlx->dirX * moveSpeed;
		tempY = mlx->posY - mlx->dirY * moveSpeed;

		if (worldMap[(int)tempX][(int)tempY] == 0)
		{
			mlx->posX = tempX;
			mlx->posY = tempY;
		}
	}
	if (mlx -> a)// A
	{
		double oldDirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(rotSpeed) - mlx->dirY * sin(rotSpeed);
		mlx->dirY = oldDirX * sin(rotSpeed) + mlx->dirY * cos(rotSpeed);
		double oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(rotSpeed) - mlx->planeY * sin(rotSpeed);
		mlx->planeY = oldPlaneX * sin(rotSpeed) + mlx->planeY * cos(rotSpeed);
	}
	if (mlx -> d)// D
	{
		double oldDirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(-rotSpeed) - mlx->dirY * sin(-rotSpeed);
		mlx->dirY = oldDirX * sin(-rotSpeed) + mlx->dirY * cos(-rotSpeed);
		double oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(-rotSpeed) - mlx->planeY * sin(-rotSpeed);
		mlx->planeY = oldPlaneX * sin(-rotSpeed) + mlx->planeY * cos(-rotSpeed);
	}
}

int render(t_mlx *mlx)
{
	mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
	raycasting(mlx);
	moving(mlx);
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
							mlx -> img_ptr, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	t_mlx	*mlx;
	mlx = malloc(sizeof(t_mlx));
	mlx->posX = 3;
	mlx->posY = 3;
	mlx->dirX = -1;
	mlx->dirY = 0;
	mlx->planeX = 0;
	mlx->planeY = 0.66;
	window_creating(mlx);
	mlx_loop_hook(mlx->mlx_ptr, &render, mlx);
	hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	return 0;
}
