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

#include "../includes/cub3d.h"	


void	skip_whitespace(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n') \
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
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

int	orient_empty(char *orient)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (orient[i])
	{
		if (orient[i] == 'N' || orient[i] == 'S' || \
		orient[i] == 'E' || orient[i] == 'W' \
		|| orient[i] == 'F' || orient[i] == 'C')
			count++;
		i++;
	}
	if (count == 0)
		return (-1);
	return (0);
}

int	get_colors(char *str, t_map *map, t_game *game)
{
	int		fd;
	char	*orient;
	int		cnt;

	orient = ft_strdup("NSEWFC");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	map->cnt = 1;
	map->line = get_next_line(fd);
	while (orient_empty(orient) != -1 && map->line != NULL)
	{
		check_data(orient, map, map->line);
		free(map->line);
		map->cnt++;
		if (cnt != 1)
			map->line = get_next_line(fd);
	}
	if (orient_empty(orient) == 0)
	{
		close(fd);
		return (-1);
	}
	parse_map(str, game, map, fd);
	return (0);
}

void	parse_map(char *str, t_game *game, t_map *map, int fd)
{
	map->line = get_next_line(fd);
	while (map->line != NULL && map->line[0] == '\n')
	{
		free(map->line);
		map->line = get_next_line(fd);
	}
	if (map->line != NULL)
	{
		map->size = 1;
		while (map->line != NULL && map->line[0] != '\n')
		{
			free(map->line);
			map->line = get_next_line(fd);
			map->size++;
		}
	}
	close(fd);
	parsing_magic(str, game, map);
}

void	alloc_grid(t_map *map, t_game *game)
{
	map->grid = (char **)malloc(sizeof(char *) * map->size + 1);
	if (!map->grid)
		game_exit_error(game, map, "fucking error or something");
	map->grid[map->size + 1] = NULL;
}

void	store_grid(t_game *game, t_map *map, int fd)
{
	int	i;

	i = 1;
	while (i < map->size)
	{
		map->grid[i] = get_next_line(fd);
		i++;
	}
}

void	trim_grid(t_map *map, t_game *game)
{
	int	i;

	i = -1;
	while (map->grid[++i] != NULL)
		map->grid[i] = ft_strtrim(map->grid[i], "\n");
}

void	parsing_magic(char *str, t_game *game, t_map *map)
{
	int	fd;

	fd = open(str, O_RDONLY);
	while (map->cnt != 0)
	{
		map->line = get_next_line(fd);
		free(map->line);
		map->cnt--;
	}
	alloc_grid(map, game);
	map->line = get_next_line(fd);
	while (map->line != NULL && map->line[0] == '\n')
	{
		free(map->line);
		map->line = get_next_line(fd);
	}
	if (map->line != NULL)
	{
		map->grid[0] = ft_strdup(map->line);
		free(map->line);
	}
	store_grid(game, map, fd);
	close (fd);
	trim_grid(map, game);
}