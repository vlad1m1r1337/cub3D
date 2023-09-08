#include "../include/cube3d.h"

//void	draw_yellow_square(t_mlx *mlx)
//{
//	for (int y = py; y < py + 10; y++) {
//		for (int x = px; x < px + 10; x++) {
//			my_pixel_put(mlx, x, y, 0xFFFF00);
//		}
//	}
//	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
//							mlx -> img_ptr, 0, 0);
//}

int	render_check(t_mlx *mlx)
{
	if (mlx -> win_ptr == NULL)
		return (1);
	mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
	mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, H, W);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp,
									&mlx -> size_l, &mlx -> endian);
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
							mlx -> img_ptr, 0, 0);
	return (0);
}

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

void raycasting(t_mlx *mlx)
{
	double planeX = 0, planeY = 0.66;

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame


	for (int x = 0; x < W; x++)
	{
		for (int i = 0; i < H / 2; i++)
			my_pixel_put(mlx, x, i, 0x0000FF);
		for (int i = H / 2; i < H; i++)
			my_pixel_put(mlx, x, i, 0x00FF00);
		double cameraX = 2 * x / (double)W - 1; //x-coordinate in camera space
		double rayDirX = mlx->dirX + planeX * cameraX;
		double rayDirY = mlx->dirY + planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)mlx->posX;
		int mapY = (int)mlx->posY;

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
			if (sideDistX < sideDistY)
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
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(H / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + H / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + H / 2;
		if (drawEnd >= H) drawEnd = H - 1;

		int i = -1;
		while (++i < drawEnd)
		{
			my_pixel_put(mlx, x, i, 0xFF0000);
		}
		mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
								mlx -> img_ptr, 0, 0);
	}
}

int render(t_mlx *mlx)
{
	raycasting(mlx);
	return (0);
}

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	t_mlx	*mlx;
	mlx = malloc(sizeof(t_mlx));
	mlx->posX = 22;
	mlx->posY = 12;
	mlx->dirX = -1;
	mlx->dirY = 0;
	window_creating(mlx);
	mlx_loop_hook(mlx->mlx_ptr, &render, mlx);
	hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	return 0;
}
