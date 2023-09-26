/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:46:18 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/24 13:46:20 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	store_sprites(t_mlx *mlx)
{
	int		width;
	int		height;
	// void	*window_ptr;

	mlx->static1 = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"src/xpm/gun_static.xpm", &width, &height);
	// game->shoot_a = mlx_xpm_file_to_image(game->mlx, \
	// "src/xpm/gun_shot1.xpm", &width, &height);
	// game->shoot_b = mlx_xpm_file_to_image(game->mlx, \
	// "src/xpm/gun_shot2.xpm", &width, &height);
	// game->shoot_c = mlx_xpm_file_to_image(game->mlx, \
	// "src/xpm/gun_shot3.xpm", &width, &height);
	// if (game->stat_g == NULL || game->shoot_a == NULL \
	// || game->shoot_b == NULL || game->shoot_c == NULL)
		// game_exit_error(game, map, "error: sprites could not be stored\n", 2);
}
