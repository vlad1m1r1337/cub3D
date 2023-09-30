/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:34:19 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/30 18:14:48 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	calc_textures(t_mlx *mlx)
{
	double	wall_x;

	if (mlx->side == 0)
		wall_x = mlx->pos_y + mlx->perp_wall_dist * mlx->ray_dir_y;
	else
		wall_x = mlx->pos_x + mlx->perp_wall_dist * mlx->ray_dir_x;
	wall_x -= floor((wall_x));
	mlx->tex_x = (int)(wall_x * (double)(TEXT_WIDTH));
	if (mlx->side == 0 && mlx->ray_dir_x > 0)
		mlx->tex_x = TEXT_WIDTH - mlx->tex_x - 1;
	if (mlx->side == 1 && mlx->ray_dir_y < 0)
		mlx->tex_x = TEXT_WIDTH - mlx->tex_x - 1;
}

int	choose_textures(t_mlx *mlx)
{
	if (mlx->side && mlx->ray_dir_y > 0)
		return (3);
	else if (mlx->side && mlx->ray_dir_y < 0)
		return (2);
	else if (!mlx->side && mlx->ray_dir_x > 0)
		return (1);
	else if (!mlx->side && mlx->ray_dir_x < 0)
		return (0);
	return (-1);
}

void	put_textures(t_mlx *mlx, int x)
{
	char	*dst;
	int		tex_y;
	double	tex_pos;
	int		i;
	double	step;

	step = 1.0 * TEXT_HEIGHT / mlx->line_height;
	tex_pos = (mlx->draw_start - H / 2 + mlx->line_height / 2) * (step);
	i = choose_textures(mlx);
	while (mlx->draw_start < mlx->draw_end)
	{
		tex_y = (int)tex_pos & (TEXT_HEIGHT - 1);
		tex_pos += step;
		dst = mlx->img_sprites[i].addr + (tex_y * \
			mlx->img_sprites[i].line_length + \
			mlx->tex_x * \
			(mlx->img_sprites[i].bits_per_pixel / 8));
		my_mlx_pixel_put(mlx, x, mlx->draw_start++, *(unsigned int *)dst);
	}
}

void	raycasting(t_mlx *mlx)
{
	int	x;

	x = -1;
	while (++x < W)
	{
		calculate_dist(mlx, x);
		preparing_to_dda(mlx);
		dda(mlx);
		calc_draw_start_end(mlx);
		calc_textures(mlx);
		put_textures(mlx, x);
	}
}
