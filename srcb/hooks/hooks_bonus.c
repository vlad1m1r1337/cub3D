/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:27:07 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/30 18:13:27 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	press_handle(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		system("killall afplay");
		game_exit(mlx->gg, mlx->gg->data, "Thanks for Playing\n");
	}
	if (keycode == W_KEY)
		mlx -> w = 1;
	if (keycode == S_KEY)
		mlx -> s = 1;
	if (keycode == D_KEY)
		mlx -> d = 1;
	if (keycode == A_KEY)
		mlx -> a = 1;
	if (keycode == 123)
		mlx->arrow_left = 1;
	if (keycode == 124)
		mlx->arrow_right = 1;
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
	if (keycode == 123)
		mlx->arrow_left = 0;
	if (keycode == 124)
		mlx->arrow_right = 0;
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	(void)y;
	mlx_mouse_hide();
	if (x < W / 2)
		spin_left(mlx);
	if (x > W / 2)
		spin_right(mlx);
	mlx_mouse_move(mlx->win_ptr, W / 2, H / 2);
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_hook(mlx -> win_ptr, 17, 1L << 2, ex, mlx);
	mlx_hook(mlx -> win_ptr, 2, 1L << 3, press_handle, mlx);
	mlx_hook(mlx -> win_ptr, 6, 1L << 6, mouse_move, mlx);
	mlx_hook(mlx -> win_ptr, 3, 1L << 3, release_handle, mlx);
}

int	render(t_mlx *mlx)
{
	static int	current_frame = 0;
	static int	count = 0;
	int			frame_pos[4];

	init_frame_pos(frame_pos);
	mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, W, H);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, \
			&mlx->img.bits_per_pixel, &mlx->img.line_length, \
			&mlx->img.endian);
	draw_wall_ceil(mlx);
	raycasting(mlx);
	moving(mlx);
	mlx_put_image_to_window(mlx -> mlx_ptr, mlx -> win_ptr, \
		mlx -> img.img, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	mlx->gg->img_sprites[current_frame].img, frame_pos[current_frame], 650);
	if (count > 8)
	{
		count = 0;
		current_frame = (current_frame + 1) % 4;
	}
	count++;
	musik();
	return (0);
}
