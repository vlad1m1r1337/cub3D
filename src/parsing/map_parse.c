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

void	parse_map(char *str, t_game *game, t_map *map, int i)
{
	map->line = get_next_line(map->fd);
	while (*(map->line) == '\n')
	{
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	if (!map->line)
		game_exit_error(game, map, "error: map not detected\n");
	while (check_map(map->line, map, game))
	{
		new_line(map, str);
		map->line = get_next_line(map->fd);
		if (!map->line || (*(map->line) == '\n'))
		{
			final_check(map->fd, map, game);
			break ;
		}
		i++;
	}
	check_walls(map, game, 0, 0);
}

int	check_map(char *str, t_map *map, t_game *game)
{
	char		*save;
	char const	*nl;
	static int	player_flag = 0;

	save = str;
	nl = ft_strdup("\n");
	str = ft_strtrim(str, nl);
	free(save);
	save = str;
	while (*save)
	{
		if ((*save == 'N' || *save == 'S' || *save == 'W' || *save == 'E')
			&& player_flag == 0)
		{
			player_flag = 1;
			map->s_orient = *save;
		}
		else if (*save != '1' && *save != '0' && *save != ' ')
			game_exit_error(game, map, "error: extra chars\n");
		save++;
	}
	free((char *)nl);
	return (1);
}

void	new_line(t_map *map, char *str)
{
	static int	size = 1;
	char		**new_arr;

	new_arr = NULL;
	if (size == 1)
	{
		map->grid = (char **)malloc(sizeof(char *) * (size + 1));
		map->grid[0] = str;
		map->grid[1] = NULL;
		size++;
		return ;
	}
	else
	{
		new_arr = (char **)malloc(sizeof(char *) * (size + 1));
		dup_grid(map->grid, new_arr);
		new_arr[size - 1] = str;
		new_arr[size] = NULL;
		free_grid(map->grid);
		map->grid = new_arr;
		size++;
		return ;
	}
}

void	final_check(int fd, t_map *map, t_game *game)
{
	if (!map->line)
		return ;
	free(map->line);
	map->line = get_next_line(fd);
	while (map->line && *(map->line))
	{
		if (*(map->line) != '\n')
			game_exit_error(game, map, "error: data after map\n");
		free(map->line);
		map->line = get_next_line(fd);
	}
}

void	check_walls(t_map *map, t_game *game, int i, int j)
{
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == map->s_orient)
			{
				game->posx = i + 0.5;
				game->posy = j + 0.5;
				map->grid[i][j] = '0';
			}
			if (map->grid[i][j] == '0')
			{
				if (i == 0 || i == arrsize(map->grid))
					game_exit_error(game, map, "error: map not within walls\n");
				check_positions(map->grid[i - 1][j], map->s_orient, game, map);
				check_positions(map->grid[i + 1][j], map->s_orient, game, map);
				check_positions(map->grid[i][j - 1], map->s_orient, game, map);
				check_positions(map->grid[i][j + 1], map->s_orient, game, map);
			}
			j++;
		}
		i++;
	}
}
