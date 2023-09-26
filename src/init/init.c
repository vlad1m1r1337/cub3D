#include "../../includes/cub3d.h"

void	window_creating(t_mlx *mlx)
{
	mlx -> mlx_ptr = mlx_init();
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, H, W, "cube3D");
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, H, W);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp,
									&mlx -> size_l, &mlx -> endian);
}

void	initial_game_parametres(t_mlx *mlx)
{
	mlx->moveSpeed = 0.1;
	mlx->rotSpeed = 0.03;
	mlx->pos_x = 2;
	mlx->pos_y = 2;
	mlx->dir_x = -1;
	mlx->dir_y = 0;
	mlx->plane_x = 0;
	mlx->plane_y = 0.66;

	mlx->w = 0;
	mlx->a = 0;
	mlx->s = 0;
	mlx->d = 0;
	mlx->arrow_right = 0;
	mlx->arrow_left = 0;

	mlx->image_n = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/colorstone.xpm", &mlx->img_sprites[0].width, &mlx->img_sprites[0].height);puts("1");
	mlx->image_s = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/bluestone.xpm", &mlx->img_sprites[1].width, &mlx->img_sprites[1].height);

	mlx->img_sprites[0].addr = mlx_get_data_addr(mlx->image_n, &mlx->img_sprites[0].bits_per_pixel, &mlx->img_sprites[0].line_length, &mlx->img_sprites[0].endian);
	mlx->img_sprites[1].addr = mlx_get_data_addr(mlx->image_s, &mlx->img_sprites[1].bits_per_pixel, &mlx->img_sprites[1].line_length, &mlx->img_sprites[1].endian);
}
