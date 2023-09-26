/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:20:39 by jfrances          #+#    #+#             */
/*   Updated: 2023/08/31 16:20:41 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		game_exit_error(NULL, NULL, "error: game struct malloc error\n", 1);
	mlx = malloc(sizeof(t_mlx));
	parsing(game, argc, argv);
	initial_game_parametres(mlx);
	char worldMap[mapWidth][mapHeight] = {
			{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
			{'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
			{'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
			{'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};
	//recopy in map
	for (int i = 0; i < mapWidth; i++) 
	{
		for (int j = 0; j < mapHeight; j++) 
		{
			mlx->worldMap[i][j] = worldMap[i][j];
		}
	}
	store_sprites(mlx);
	window_creating(mlx);
	mlx_loop_hook(mlx->mlx_ptr, &render, mlx);
	hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	return 0;
}
