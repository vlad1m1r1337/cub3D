/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:21:37 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/30 14:15:55 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_colors(t_game *game, t_map *map, char **floor, char **ceiling)
{
	game->flc1 = new_ft_atoi(floor[0]);
	game->flc2 = new_ft_atoi(floor[1]);
	game->flc3 = new_ft_atoi(floor[2]);
	game->clc1 = new_ft_atoi(ceiling[0]);
	game->clc2 = new_ft_atoi(ceiling[1]);
	game->clc3 = new_ft_atoi(ceiling[2]);
	if (game->flc1 < 0 || game->flc2 < 0 || game->flc3 < 0 \
	|| game->clc1 < 0 || game->clc2 < 0 || game->clc3 < 0 || \
	game->flc1 > 255 || game->flc2 > 255 || game->flc3 > 255 \
	|| game->clc1 > 255 || game->clc2 > 255 || game->clc3 > 255)
	{
		free_arr(floor);
		free_arr(ceiling);
		game_exit_error(game, map, "error: RGB values incorrect\n", 2);
	}
}

void	free_arr(char **arr1)
{
	int	i;

	i = 0;
	while (arr1[i])
	{
		free(arr1[i]);
		i++;
	}
	free(arr1);
}

void	check_posit(t_game *game, t_map *map, char pos, char player)
{
	if (pos != '1' && pos != '0' && pos != player)
		game_exit_error(game, map, "error: map not enclosed in walls\n", 2);
}

int	map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i - 1);
}

void	check_walls(t_game *game, t_map *map, int x, int j)
{
	while (map->grid[x])
	{
		j = 0;
		while (map->grid[x][j])
		{
			if (map->grid[x][j] == map->spawn_orient)
			{
				game->pos_player_y = x + 0.5;
				game->pos_player_x = j + 0.5;
				game->facing = map->spawn_orient;
				map->grid[x][j] = '0';
			}
			if (map->grid[x][j] == '0')
			{
				if (x == 0 || x == map_size(map->grid))
					game_exit_error(game, map, "error: not in walls\n", 2);
				check_posit(game, map, map->grid[x - 1][j], map->spawn_orient);
				check_posit(game, map, map->grid[x + 1][j], map->spawn_orient);
				check_posit(game, map, map->grid[x][j - 1], map->spawn_orient);
				check_posit(game, map, map->grid[x][j + 1], map->spawn_orient);
			}
			j++;
		}
		x++;
	}
}
