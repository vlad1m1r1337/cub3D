/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:39:35 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/29 17:55:12 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	window_creating(t_mlx *mlx)
{
	mlx -> mlx_ptr = mlx_init();
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, H, W, "cube3D");
	mlx -> img_ptr = mlx_new_image(mlx -> mlx_ptr, H, W);
	mlx -> data = mlx_get_data_addr(mlx -> img_ptr, &mlx -> bpp, \
		&mlx -> size_l, &mlx -> endian);
}

void	var_init(t_mlx *mlx)
{
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
	mlx->move_speed = 0.1;
	mlx->rot_speed = 0.05;
}

void	error_handle(void)
{
	printf("Error\n");
	exit(0);
}

void	init_sprites(t_mlx *mlx)
{
	mlx->image_n = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/colorstone.xpm", \
		&mlx->img_sprites[0].width, &mlx->img_sprites[0].height);
	mlx->image_s = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/bluestone.xpm", \
		&mlx->img_sprites[1].width, &mlx->img_sprites[1].height);
	mlx->image_w = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/greenlight.xpm", \
		&mlx->img_sprites[1].width, &mlx->img_sprites[1].height);
	mlx->image_e = mlx_xpm_file_to_image(mlx->mlx_ptr, "pics/greystone.xpm", \
		&mlx->img_sprites[1].width, &mlx->img_sprites[1].height);
	if (mlx->image_n == NULL || mlx->image_s == NULL \
		|| mlx->image_w == NULL || mlx->image_e == NULL)
		error_handle();
	mlx->img_sprites[0].addr = mlx_get_data_addr(mlx->image_n, \
		&mlx->img_sprites[0].bits_per_pixel, \
			&mlx->img_sprites[0].line_length, &mlx->img_sprites[0].endian);
	mlx->img_sprites[1].addr = mlx_get_data_addr(mlx->image_s, \
		&mlx->img_sprites[1].bits_per_pixel, \
			&mlx->img_sprites[1].line_length, &mlx->img_sprites[1].endian);
	mlx->img_sprites[2].addr = mlx_get_data_addr(mlx->image_w, \
		&mlx->img_sprites[2].bits_per_pixel, \
			&mlx->img_sprites[2].line_length, &mlx->img_sprites[2].endian);
	mlx->img_sprites[3].addr = mlx_get_data_addr(mlx->image_e, \
		&mlx->img_sprites[3].bits_per_pixel, \
			&mlx->img_sprites[3].line_length, &mlx->img_sprites[3].endian);
}

void	initial_game_parametres(t_mlx *mlx)
{
	var_init(mlx);
	init_sprites(mlx);
}
