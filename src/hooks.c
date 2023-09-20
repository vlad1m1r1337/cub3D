#include "../include/cube3d.h"

int	ex(void)
{
	exit(0);
}

int	press_handle(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W_KEY)
		mlx -> w = 1;
	if (keycode == S_KEY)
		mlx -> s = 1;
	if (keycode == D_KEY)
		mlx -> d = 1;
	if (keycode == A_KEY)
		mlx -> a = 1;
	return (0);
}

int	release_handle(int keycode, t_mlx *mlx)
{
	if (keycode == W_KEY)
		mlx -> w = 0;
	if (keycode == S_KEY)
		mlx -> s = 0;
	if (keycode == D_KEY)
		mlx -> d = 0;
	if (keycode == A_KEY)
		mlx -> a = 0;
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
	mlx_hook(mlx -> win_ptr, 2, 1L << 3, press_handle, mlx);
	mlx_hook(mlx -> win_ptr, 3, 1L << 3, release_handle, mlx);
}
