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
	mlx->pos_x = 3;
	mlx->pos_y = 3;
	mlx->dir_x = -1;
	mlx->dir_y = 0;
	mlx->plane_x = 0;
	mlx->plane_y = 0.66;
}
