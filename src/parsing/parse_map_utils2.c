/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:22:18 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/15 14:22:20 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	skip_whitespace(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n') \
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
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

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	dup_cnt(t_map *map, t_game *game)
{
	int	i;

	i = -1;
	while (map->grid[++i] != NULL)
	{
		if (char_chk(map->grid[i]) == -1)
			game_exit_error(game, map, "error: invalid characters in map\n");
		map->n += chr_count(map->grid[i], 'N');
		map->s += chr_count(map->grid[i], 'S');
		map->e += chr_count(map->grid[i], 'E');
		map->w += chr_count(map->grid[i], 'W');
	}
	if (facing_check(map) == -1)
		game_exit_error(game, map, "error: invalid facings\n");
	check_colors(game, map);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}