/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_start_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:43:46 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/18 15:43:48 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	orient_check(char *orient)
{
	while (*orient)
	{
		if (*orient != ' ')
			return (1);
		orient++;
	}
	return (0);
}

void	trim_stuff(t_map *map)
{
	char		*save;
	char const	*nl;

	save = map->north;
	nl = ft_strdup("\n");
	map->north = ft_strtrim(map->north, nl);
	free(save);
	save = map->south;
	map->south = ft_strtrim(map->south, nl);
	free(save);
	save = map->west;
	map->west = ft_strtrim(map->west, nl);
	free(save);
	save = map->east;
	map->east = ft_strtrim(map->east, nl);
	free(save);
	save = map->ceiling;
	map->ceiling = ft_strtrim(map->ceiling, nl);
	free(save);
	save = map->floor;
	map->floor = ft_strtrim(map->floor, nl);
	free(save);
	free((void *)nl);
}

void	check_textures(t_game *game, t_map *map)
{
	confirm_textures(map->north, map, game);
	confirm_textures(map->south, map, game);
	confirm_textures(map->east, map, game);
	confirm_textures(map->west, map, game);
}

void	confirm_textures(char *arr, t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == ' ')
			game_exit_error(game, map, "error: error in texture path\n");
		i++;
	}
}
