/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:18 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/10 14:22:59 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	set_count(t_map *map)
{
	map->n = 0;
	map->s = 0;
	map->e = 0;
	map->w = 0;
}

int	char_chk(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'N' && str[i] != '0' \
		&& str[i] != '1' && str[i] != 'S' && str[i] != 'E' \
		&& str[i] != 'W' && str[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

void	trim_grid(t_map *map)
{
	int	i;

	i = -1;
	while (map->grid[++i] != NULL)
		map->grid[i] = ft_strtrim(map->grid[i], "\n");
}

void	alloc_grid(t_map *map, t_game *game)
{
	map->grid = (char **)malloc(sizeof(char *) * (map->size + 1));
	if (!map->grid)
		game_exit_error(game, map, "error: malloc: fatal\n", 2);
	map->grid[map->size] = NULL;
}

void	store_grid(t_game *game, t_map *map)
{
	int	i;

	i = 1;
	while (i < map->size)
	{
		map->grid[i] = get_next_line(game->fd);
		i++;
	}
	after_map(game, map);
	trim_grid(map);
	dup_cnt(map, game);
}
