#include "../include/cube3d.h"

void	draw_yellow_square(t_mlx *mlx)
{
	for (int y = py; y < py + 10; y++) {
		for (int x = px; x < px + 10; x++) {
			my_mlx_pixel_put(mlx, x, y, 0xFFFF00);
		}
	}
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
							mlx -> img_ptr, 0, 0);
}

int	render_check(t_mlx *mlx)
{
	if (mlx -> win_ptr == NULL)
		return (1);
	mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
	draw_yellow_square(mlx);
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr,
							mlx -> img_ptr, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	px = 300;
	py = 300;
	flag = 1;
	left = 0;
	right = 0;
	straight = 0;
	back = 0;

	t_mlx	*mlx;
	mlx = malloc(sizeof(t_mlx));
	window_creating(mlx);
	draw_yellow_square(mlx);
	hooks(mlx);//mlx_loop_hook(mlx -> mlx_ptr, &render_check, mlx);
	mlx_loop(mlx->mlx_ptr);
	return 0;
}
