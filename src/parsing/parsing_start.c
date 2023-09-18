/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:43:37 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/18 15:43:39 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_game_set_map(char **argv, t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		game_exit_error(game, NULL, "error: map struct malloc error\n");
	parsing_next(argv[1], game->map, game);
}

void	parsing_next(char *str, t_map *map, t_game *game)
{
	map->fd = open(str, O_RDONLY);
	if (map->fd == -1)
		game_exit_error(game, map, "error: file cannot open\n");
	get_colors(game, map);
	check_textures(game, map);
	store_colors(ft_split(map->ceiling, ','), ft_split(map->floor, ','), game);
	parse_map(str, game, map, map->fd);
}

void	get_colors(t_game *game, t_map *map)
{
	char	*orient;

	orient = ft_strdup("NSEWFC");
	map->line = get_next_line(map->fd);
	if (!map->line)
		game_exit_error(game, map, "error: empty file\n");
	while (get_info(map->line, orient, map, game) == 1 \
	&& orient_check(orient) == 1)
	{
		free(map->line);
		map->line = get_next_line(map->fd);
		if (!map->line)
			game_exit_error(game, map, "error: empty file\n");
	}
	trim_stuff(map);
	free(orient);
}

int	get_info(char *line, char *orient, t_map *map, t_game *game)
{
	if (*line == '\n')
		return (1);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (add_info('N', game, orient, line + 2));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (add_info('S', game, orient, line + 2));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (add_info('W', game, orient, line + 2));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (add_info('E', game, orient, line + 2));
	else if (line[0] == 'F' && line[1] == ' ')
		return (add_info('F', game, orient, line + 1));
	else if (line[0] == 'C' && line[1] == ' ')
		return (add_info('C', game, orient, line + 1));
	else
		game_exit_error(game, map, "error: invalid identifier\n");
	return (0);
}

int	add_info(char to_remove, t_game *game, char *orient, char *line)
{
	while (*orient != to_remove && *orient)
		orient++;
	if (!*orient)
		game_exit_error(game, game->map, "error: duplicate IDs\n");
	*orient = ' ';
	space_skip(&line);
	if (*line == '\0' || *line == '\n')
		game_exit_error(game, game->map, "error: no data after identifier\n");
	if (to_remove == 'N')
		game->map->north = ft_strdup(line);
	else if (to_remove == 'S')
		game->map->south = ft_strdup(line);
	else if (to_remove == 'W')
		game->map->west = ft_strdup(line);
	else if (to_remove == 'E')
		game->map->east = ft_strdup(line);
	else if (to_remove == 'C')
		game->map->ceiling = ft_strdup(line);
	else if (to_remove == 'F')
		game->map->floor = ft_strdup(line);
	return (1);
}
