/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:54:36 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/05 20:04:36 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"	

void	check_colors(t_game *game, t_map *map)
{
	char	**tmp_floor;
	char	**tmp_ceiling;
	int		flag;

	flag = 0;
	map->floor = ft_strtrim(map->floor, " ");
	map->ceiling = ft_strtrim(map->ceiling, " ");
	map->floor = ft_strtrim(map->floor, "\n");
	map->ceiling = ft_strtrim(map->ceiling, "\n");
	if (fc_garbage(map->floor, map->ceiling) == -1)
		game_exit_error(game, map, "error: bad values in map head\n", 1);
	tmp_floor = ft_split(map->floor, ',');
	tmp_ceiling = ft_split(map->ceiling, ',');
	if (arr_size(tmp_floor) != 3 || arr_size(tmp_ceiling) != 3)
	{
		free_arr(tmp_floor);
		free_arr(tmp_ceiling);
		flag = 1;
	}
	if (flag == 1)
		game_exit_error(game, map, \
		"error: invalid number of RGB arguments\n", 1);
	fill_colors(game, map, tmp_floor, tmp_ceiling);
	if (flag == 0)
		free_arr2(tmp_floor, tmp_ceiling);
}

void	check_data(char *orient, t_map *map, char *line)
{
	int	i;

	i = 0;
	skip_whitespace(line, &i);
	check_no(orient, line, map, &i);
	check_so(orient, line, map, &i);
	check_ea(orient, line, map, &i);
	check_we(orient, line, map, &i);
	check_f(orient, line, map, &i);
	check_c(orient, line, map, &i);
}

void	parsing_magic(char *str, t_game *game, t_map *map)
{
	game->fd = open(str, O_RDONLY);
	check_map_count(game, map);
	while (map->cnt != 0)
	{
		map->line = get_next_line(game->fd);
		free(map->line);
		map->cnt--;
	}
	alloc_grid(map, game);
	map->line = get_next_line(game->fd);
	while (map->line != NULL && map->line[0] == '\n')
	{
		free(map->line);
		map->line = get_next_line(game->fd);
	}
	if (map->line != NULL)
	{
		map->grid[0] = ft_strdup(map->line);
		free(map->line);
	}
	store_grid(game, map);
	close (game->fd);
	check_walls(game, map, 0, 0);
}

void	parse_map(char *str, t_game *game, t_map *map)
{
	map->line = get_next_line(game->fd);
	while (map->line != NULL && map->line[0] == '\n')
	{
		free(map->line);
		map->line = get_next_line(game->fd);
	}
	map->size = 1;
	if (map->line != NULL)
	{
		while (map->line != NULL)
		{
			free(map->line);
			map->line = get_next_line(game->fd);
			map->size++;
		}
	}
	if (map->size == 1)
		game_exit_error(game, map, "error: invalid map size\n", 1);
	close(game->fd);
	garbage_check(game, map, game->fd, str);
	set_count(map);
	parsing_magic(str, game, map);
}

void	get_colors(char *str, t_map *map, t_game *game)
{
	char	*orient;

	orient = ft_strdup("NSEWFC");
	game->fd = open(str, O_RDONLY);
	if (game->fd == -1)
		game_exit_error(game, map, "error: file cannot open\n", 1);
	map->cnt = 1;
	map->line = get_next_line(game->fd);
	while (orient_empty(orient) != -1 && map->line != NULL)
	{
		check_data(orient, map, map->line);
		free(map->line);
		map->cnt++;
		if (map->cnt != 1)
			map->line = get_next_line(game->fd);
	}
	if (orient_empty(orient) == 0)
	{
		close(game->fd);
		game_exit_error(game, map, "error: invalid descriptors\n", 1);
	}
	free(orient);
	free(map->line);
	parse_map(str, game, map);
}
