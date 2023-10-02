/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:26:18 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/20 12:26:21 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	name_check(char *str)
{
	size_t		len;
	size_t		extlen;
	const char	*ext;
	const char	*str_end;

	len = ft_strlen(str);
	ext = ".cub";
	extlen = ft_strlen(ext);
	if (len < extlen)
		return (-1);
	str_end = str + len - extlen;
	if (ft_strncmp(str_end, ext, extlen) == 0)
		return (0);
	else
		return (-1);
	return (0);
}

void	check_map_count(t_game *game, t_map *map)
{
	if (map->cnt == 0)
		game_exit_error(game, map, "error: fatal\n", 1);
}

int	facing_check(t_map *map)
{
	if (map->n == 0 && map->s == 0 && map->e == 0 && map->w == 0)
		return (-1);
	if (map->n > 1 || map->s > 1 || map->e > 1 || map->w > 1)
		return (-1);
	else if (map->n == 1 && (map->s != 0 || map->e != 0 || map->w != 0))
		return (-1);
	else if (map->s == 1 && (map->n != 0 || map->e != 0 || map->w != 0))
		return (-1);
	else if (map->e == 1 && (map->s != 0 || map->n != 0 || map->w != 0))
		return (-1);
	else if (map->w == 1 && (map->s != 0 || map->e != 0 || map->n != 0))
		return (-1);
	if (map->n == 1 && (map->s == 0 || map->e == 0 || map->w == 0))
		map->spawn_orient = 'N';
	else if (map->s == 1 && (map->n == 0 || map->e == 0 || map->w == 0))
		map->spawn_orient = 'S';
	else if (map->e == 1 && (map->s == 0 || map->n == 0 || map->w == 0))
		map->spawn_orient = 'E';
	else if (map->w == 1 && (map->s == 0 || map->n == 0 || map->e == 0))
		map->spawn_orient = 'W';
	return (0);
}

int	chr_count(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

void	parsing(t_game *game, int argc, char **argv)
{
	int		i;
	int		j;
	t_map	*map;

	i = -1;
	j = i;
	if (argc != 2 || (name_check(argv[1]) == -1))
		game_exit_error(game, NULL, "error: invalid input\n", 1);
	map = malloc(sizeof(t_map));
	if (!map)
		game_exit_error(game, NULL, "error: map struct malloc error\n", 1);
	map_init(map);
	get_colors(argv[1], map, game);
	game->data = map;
}
