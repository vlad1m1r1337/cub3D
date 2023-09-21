#include "../../includes/cub3d.h"

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

		if (mlx->worldMap[(int)tempX][(int)tempY] != '1')
		{
			mlx->posX = tempX;
			mlx->posY = tempY;
		}
	}
	if (mlx -> s)// S
	{
		double tempX;
		double tempY;

		tempX = mlx->posX - mlx->dirX * moveSpeed;
		tempY = mlx->posY - mlx->dirY * moveSpeed;

		if (mlx->worldMap[(int)tempX][(int)tempY] != '1')
		{
			mlx->posX = tempX;
			mlx->posY = tempY;
		}
	}
	if (mlx -> d)// D
	{
		double tempX;
		double tempY;

		tempX = mlx->posX + mlx->planeX * moveSpeed;
		tempY = mlx->posY;

		if (mlx->worldMap[(int)tempX][(int)tempY] != '1')
		{
			mlx->posX = tempX;
			mlx->posY = tempY;
		}
	}
	if (mlx -> a)// A
	{
		double tempX;
		double tempY;

		tempX = mlx->posX - mlx->planeX * moveSpeed;
		tempY = mlx->posY;

		if (mlx->worldMap[(int)tempX][(int)tempY] != '1')
		{
			mlx->posX = tempX;
			mlx->posY = tempY;
		}
	}
	if (mlx->arrow_left)
	{
		double oldDirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(rotSpeed) - mlx->dirY * sin(rotSpeed);
		mlx->dirY = oldDirX * sin(rotSpeed) + mlx->dirY * cos(rotSpeed);
		double oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(rotSpeed) - mlx->planeY * sin(rotSpeed);
		mlx->planeY = oldPlaneX * sin(rotSpeed) + mlx->planeY * cos(rotSpeed);
	}
	if (mlx->arrow_right)
	{
		double oldDirX = mlx->dirX;
		mlx->dirX = mlx->dirX * cos(-rotSpeed) - mlx->dirY * sin(-rotSpeed);
		mlx->dirY = oldDirX * sin(-rotSpeed) + mlx->dirY * cos(-rotSpeed);
		double oldPlaneX = mlx->planeX;
		mlx->planeX = mlx->planeX * cos(-rotSpeed) - mlx->planeY * sin(-rotSpeed);
		mlx->planeY = oldPlaneX * sin(-rotSpeed) + mlx->planeY * cos(-rotSpeed);
	}
}
