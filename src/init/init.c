#include "../../includes/cub3d.h"

void	window_creating(t_mlx *mlx)
{
	mlx -> mlx_ptr = mlx_init();
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, H, W, "cube3D");
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, H, W);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp,
									&mlx -> size_l, &mlx -> endian);
}

void initial_game_parametres(t_mlx *mlx)
{
	mlx->moveSpeed = 0.1;
	mlx->rotSpeed = 0.03;
	mlx->posX = 3;
	mlx->posY = 3;
	mlx->dirX = -1;
	mlx->dirY = 0;
	mlx->planeX = 0;
	mlx->planeY = 0.66;
}
