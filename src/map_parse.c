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
	cnt = 1;
	map->line = get_next_line(fd);
	while (orient_empty(orient) != -1 && map->line != NULL)
	{
		check_data(orient, map, map->line);
		free(map->line);
		cnt++;
		if (cnt != 1)
			map->line = get_next_line(fd);
	}
	if (orient_empty == 0)
		return (-1);
	return (0);
}

void	parse_map(t_game *game, t_map *map)
{
	

}

// void	map_parse(char *str, t_game *game)
// {
// 	int	fd;
// 	int	i;

// 	i = 0;
// 	fd = open_file(str);
// 	game->line = get_next_line(fd);
// 	if (game->line == NULL)
// 		game_exit(game, "error: file read\n");
// 	while (game->line != NULL)
// 	{
// 		game->n += chr_count(game->line, 'N');
// 		game->s += chr_count(game->line, 'S');
// 		game->e += chr_count(game->line, 'E');
// 		game->w += chr_count(game->line, 'W');
// 		free(game->line);
// 		game->line = get_next_line(fd);
// 	}
// 	free(game->line);
// 	close(fd);
// 	if (facing_chk(game) == -1)
// 		game_exit(game, "error: invalid number of facing(s)\n");
// }
