/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_error_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:14:39 by jfrances          #+#    #+#             */
/*   Updated: 2023/10/02 16:14:54 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

void	free_arr2(char **arr1, char **arr2)
{
	free_arr(arr1);
	free_arr(arr2);
}

void	game_exit_error(t_game *game, t_map *map, char *pstr, int flag)
{
	if (map)
		free_map_data(map, flag);
	if (game->fd != 0)
		close(game->fd);
	ft_putstr_fd(pstr, 2);
	exit(1);
}

void	game_exit(t_game *game, t_map *map, char *pstr)
{
	if (map)
		free_map_data(map, 2);
	if (game->fd != 0)
		close(game->fd);
	ft_putstr_fd(pstr, 1);
	exit(0);
}
