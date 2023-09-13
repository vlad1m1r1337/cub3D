#include "../include/cube3d.h"

int	ex(void)
{
	exit(0);
}

int	press_handle(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
	{
		mlx -> w = 1;
		//printf("w_press\n");
	}
	if (keycode == 1)
	{
		mlx -> s = 1;
		//printf("s_press\n");
	}
	if (keycode == 2)
	{
		mlx -> d = 1;
		//printf("d_press\n");
	}
	if (keycode == 0)
	{
		mlx -> a = 1;
		//printf("a_press\n");
	}
	return (0);
}

int	release_handle(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
	{
		mlx -> w = 0;
		//printf("w_release\n");
	}
	if (keycode == 1)
	{
		mlx -> s = 0;
		//printf("s_release\n");
	}
	if (keycode == 2)
	{
		mlx -> d = 0;
		//printf("d_release\n");
	}
	if (keycode == 0)
	{
		mlx -> a = 0;
		//printf("a_release\n");
	}
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
	mlx_hook(mlx -> win_ptr, 2, 1L << 3, press_handle, mlx);
	mlx_hook(mlx -> win_ptr, 3, 1L << 3, release_handle, mlx);
}
