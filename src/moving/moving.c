#include "../../includes/cub3d.h"

void moving_forward(t_mlx *mlx)
{
	double tempX;
	double tempY;

	tempX = mlx->posX + mlx->dirX * mlx->moveSpeed;
	tempY = mlx->posY + mlx->dirY * mlx->moveSpeed;

	if (mlx->worldMap[(int)tempX][(int)tempY] != '1')
	{
		mlx->posX = tempX;
		mlx->posY = tempY;
	}
}

void	moving_back(t_mlx *mlx)
{
	double tempX;
	double tempY;

	tempX = mlx->posX - mlx->dirX * mlx->moveSpeed;
	tempY = mlx->posY - mlx->dirY * mlx->moveSpeed;

	if (mlx->worldMap[(int)tempX][(int)tempY] != '1')
	{
		mlx->posX = tempX;
		mlx->posY = tempY;
	}
}

void	moving_right(t_mlx *mlx)
{
	double tempX;
	double tempY;

	tempX = mlx->posX + mlx->planeX * mlx->moveSpeed;
	tempY = mlx->posY;

	if (mlx->worldMap[(int)tempX][(int)tempY] != '1')
	{
		mlx->posX = tempX;
		mlx->posY = tempY;
	}
}

void moving_left(t_mlx *mlx)
{
	double tempX;
	double tempY;

	tempX = mlx->posX - mlx->planeX * mlx->moveSpeed;
	tempY = mlx->posY;

	if (mlx->worldMap[(int)tempX][(int)tempY] != '1')
	{
		mlx->posX = tempX;
		mlx->posY = tempY;
	}
}

void spin_left(t_mlx *mlx)
{
	double oldDirX = mlx->dirX;
	mlx->dirX = mlx->dirX * cos(mlx->rotSpeed) - mlx->dirY * sin(mlx->rotSpeed);
	mlx->dirY = oldDirX * sin(mlx->rotSpeed) + mlx->dirY * cos(mlx->rotSpeed);
	double oldPlaneX = mlx->planeX;
	mlx->planeX = mlx->planeX * cos(mlx->rotSpeed) - mlx->planeY * sin(mlx->rotSpeed);
	mlx->planeY = oldPlaneX * sin(mlx->rotSpeed) + mlx->planeY * cos(mlx->rotSpeed);
}

void spin_right(t_mlx *mlx)
{
	double oldDirX = mlx->dirX;
	mlx->dirX = mlx->dirX * cos(-(mlx->rotSpeed)) - mlx->dirY * sin(-(mlx->rotSpeed));
	mlx->dirY = oldDirX * sin(-(mlx->rotSpeed)) + mlx->dirY * cos(-(mlx->rotSpeed));
	double oldPlaneX = mlx->planeX;
	mlx->planeX = mlx->planeX * cos(-(mlx->rotSpeed)) - mlx->planeY * sin(-(mlx->rotSpeed));
	mlx->planeY = oldPlaneX * sin(-(mlx->rotSpeed)) + mlx->planeY * cos(-(mlx->rotSpeed));
}

void moving(t_mlx *mlx)
{
	if (mlx -> w)// W
		moving_forward(mlx);
	if (mlx -> s)// S
		moving_back(mlx);
	if (mlx -> d)// D
		moving_right(mlx);
	if (mlx -> a)// A
		moving_left(mlx);
	if (mlx->arrow_left)
		spin_left(mlx);
	if (mlx->arrow_right)
		spin_right(mlx);
}
