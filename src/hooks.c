#include "../include/cube3d.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)// W
	{
		printf("W\n");
		py -= 10;
	}
	else if (keycode == 0)// A
	{
		printf("A\n");
		px -= 10;
	}
	else if (keycode == 1)// S
	{
		printf("S\n");
		py += 10;
	}
	else if (keycode == 2)// D
	{
		printf("D\n");
		px += 10;
	}
	mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, HW, HW);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp,
									&mlx -> size_l, &mlx -> endian);
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
							mlx -> img_ptr, 0, 0);
	draw_yellow_square(mlx);
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
