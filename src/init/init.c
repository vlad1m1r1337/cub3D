#include "../../includes/cub3d.h"

void	window_creating(t_mlx *mlx)
{
	mlx -> mlx_ptr = mlx_init();
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, H, W, "cube3D");
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, H, W);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp,
									&mlx -> size_l, &mlx -> endian);
}

