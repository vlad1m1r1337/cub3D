/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:18:27 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/22 13:18:28 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_map_data(t_map *map, int flag)
{
	int	i;

	i = -1;
	if (map->floor)
		free(map->floor);
	if (map->ceiling)
		free(map->ceiling);
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->east)
		free(map->east);
	if (map->west)
		free(map->west);
	if (map->grid && flag == 2)
	{
		while (map->grid[++i])
			free(map->grid[i]);
	}
	free(map->grid);
	free(map);
}

void	game_exit_error(t_game *game, t_map *map, char *pstr, int flag)
{
	if (map)
		free_map_data(map, flag);
	game->flc1 = 1;
	ft_putstr_fd(pstr, 2);
	exit(1);
}

void	game_exit(t_game *game, t_map *map, char *pstr)
{
	if (map)
		free_map_data(map, 2);
	game->flc1 = 1;
	ft_putstr_fd(pstr, 1);
	exit(0);
}