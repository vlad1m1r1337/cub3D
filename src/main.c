/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:20:39 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/29 17:58:13 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		game_exit_error(NULL, NULL, "error: game struct malloc error\n", 1);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		game_exit_error(game, NULL, "error: map struct malloc error\n", 1);
	parsing(game, argc, argv);
	window_creating(mlx);
	mlx->gg = game;
	initial_game_parametres(mlx);
	mlx_loop_hook(mlx->mlx_ptr, &render, mlx);
	hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
