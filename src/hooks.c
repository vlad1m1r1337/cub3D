#include "../include/cube3d.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	double moveSpeed = 0.1;
	(void)mlx;
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)// W
	{
		printf("W\n");
		if(worldMap[(int)(mlx->posX + mlx->dirX * moveSpeed)][(int)(mlx->posY)] == 0)
			mlx->posX += mlx->dirX * moveSpeed;
		if(worldMap[(int)(mlx->posX)][(int)(mlx->posY + mlx->dirY * moveSpeed)] == 0)
			mlx->posY += mlx->dirY * moveSpeed;
	}
	else if (keycode == 1)// S
	{
		printf("S\n");
		if(worldMap[(int)(mlx->posX + mlx->dirX * moveSpeed)][(int)(mlx->posY)] == 0)
			mlx->posX -= mlx->dirX * moveSpeed;
		if(worldMap[(int)(mlx->posX)][(int)(mlx->posY + mlx->dirY * moveSpeed)] == 0)
			mlx->posY -= mlx->dirY * moveSpeed;
	}
	else if (keycode == 0)// A
	{
		printf("A\n");
	}
	else if (keycode == 2)// D
	{
		printf("D\n");
	}
	mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
	return (0);
}

int	ex(void)
{
	exit(0);
}

void	hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx -> win_ptr, key_hook, mlx);
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
}
