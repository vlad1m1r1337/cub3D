#include "../include/cube3d.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	double moveSpeed = 0.1;
	(void)mlx;
	if (keycode == 53)
		exit(0);
	else if (mlx -> w)// W
	{
		printf("W\n");
		if(worldMap[(int)(mlx->posX + mlx->dirX * moveSpeed)][(int)(mlx->posY)] == 0)
			mlx->posX += mlx->dirX * moveSpeed;
		if(worldMap[(int)(mlx->posX)][(int)(mlx->posY + mlx->dirY * moveSpeed)] == 0)
			mlx->posY += mlx->dirY * moveSpeed;
	}
	else if (mlx -> s)// S
	{
		printf("S\n");
		if(worldMap[(int)(mlx->posX + mlx->dirX * moveSpeed)][(int)(mlx->posY)] == 0)
			mlx->posX -= mlx->dirX * moveSpeed;
		if(worldMap[(int)(mlx->posX)][(int)(mlx->posY + mlx->dirY * moveSpeed)] == 0)
			mlx->posY -= mlx->dirY * moveSpeed;
	}
	else if (mlx -> a)// A
	{
		printf("A\n");

		double rotSpeed = 0.1;
		double oldDirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(rotSpeed) - mlx->dirY * sin(rotSpeed);
		mlx->dirY = oldDirX * sin(rotSpeed) + mlx->dirY * cos(rotSpeed);
		double oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(rotSpeed) - mlx->planeY * sin(rotSpeed);
		mlx->planeY = oldPlaneX * sin(rotSpeed) + mlx->planeY * cos(rotSpeed);
	}
	else if (mlx -> d)// D
	{
		printf("D\n");

		double rotSpeed = 0.1;
		double oldDirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(-rotSpeed) - mlx->dirY * sin(-rotSpeed);
		mlx->dirY = oldDirX * sin(-rotSpeed) + mlx->dirY * cos(-rotSpeed);
		double oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(-rotSpeed) - mlx->planeY * sin(-rotSpeed);
		mlx->planeY = oldPlaneX * sin(-rotSpeed) + mlx->planeY * cos(-rotSpeed);
	}
	return (0);
}

int	ex(void)
{
	exit(0);
}

int	press_handle(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
	{
		mlx -> w = 1;
		printf("w_press\n");
	}
	if (keycode == 1)
	{
		mlx -> s = 1;
		printf("s_press\n");
	}
	if (keycode == 2)
	{
		mlx -> d = 1;
		printf("d_press\n");
	}
	if (keycode == 0)
	{
		mlx -> a = 1;
		printf("a_press\n");
	}
	return (0);
}

int	release_handle(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
	{
		mlx -> w = 0;
		printf("w_release\n");
	}
	if (keycode == 1)
	{
		mlx -> s = 0;
		printf("s_release\n");
	}
	if (keycode == 2)
	{
		mlx -> d = 0;
		printf("d_release\n");
	}
	if (keycode == 0)
	{
		mlx -> a = 0;
		printf("a_release\n");
	}
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx -> win_ptr, key_hook, mlx);
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
	mlx_hook(mlx -> win_ptr, 2, 1L << 3, press_handle, mlx);
	mlx_hook(mlx -> win_ptr, 3, 1L << 3, release_handle, mlx);
}
