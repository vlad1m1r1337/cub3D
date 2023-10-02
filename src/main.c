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

static void	game_init(t_game *game)
{
	game->fd = 0;
	game->pos_player_x = 0;
	game->pos_player_y = 0;
	game->flc1 = 0;
	game->flc2 = 0;
	game->flc3 = 0;
	game->clc1 = 0;
	game->clc2 = 0;
	game->clc3 = 0;
}

void	map_init(t_map *map)
{
	map->cnt = 0;
	map->size = 0;
	map->n = 0;
	map->s = 0;
	map->e = 0;
	map->w = 0;
	map->line = NULL;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->grid = NULL;
}

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
	game_init(game);
	parsing(game, argc, argv);
	window_creating(mlx);
	mlx->gg = game;
	initial_game_parametres(mlx);
	mlx_loop_hook(mlx->mlx_ptr, &render, mlx);
	hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
