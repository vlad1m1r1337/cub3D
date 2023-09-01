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

#include "../so_long.h"	

// int	check_data(char *orient, t_map *map, char *line)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	while (line[i])
// 	{
// 		j = 0;
// 		while (orient[j])
// 		{
// 			if (line[i] == ' ')
// 				i++;
// 			else if (line[i] == orient[j])
// 		}
// 	}
// }

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

int	get_colors(char *str, t_map *map)
{
	int		fd;
	char	*orient;

	orient = ft_strdup("NSEWFC");
	fd = open_file(str);
	if (fd == -1)
		return (-1);
	while (orient_empty(orinet) != -1 && line != NULL)
	{
		map->line = get_next_line(fd);
		check_data(orient, map, line);
		free(map->line);
	}
	free(map->line);
	if (map->error == 1)
		return (-1);
	return (0);
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
