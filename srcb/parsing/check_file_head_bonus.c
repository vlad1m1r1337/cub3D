/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:56:28 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/02 14:56:30 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	space_skip(char **str)
{
	while (**str == ' ')
		(*str)++;
}

void	check_no(char *orient, char *line, t_map *map, int *i)
{
	int	yes;

	yes = 0;
	if (!(line[*i] && line[(*i) + 1] && line[(*i) + 2]))
		return ;
	if (line[*i] == 'N' && line[(*i) + 1] == 'O' && line[(*i) + 2] == ' ')
	{
		yes = 1;
		line += 2;
		space_skip(&line);
	}
	if (yes == 1 && check_orient('N', orient) == 0)
		map->north = ft_strtrim(ft_strdup(line), "\n");
}

void	check_so(char *orient, char *line, t_map *map, int *i)
{
	int	yes;

	yes = 0;
	if (!(line[*i] && line[(*i) + 1] && line[(*i) + 2]))
		return ;
	if (line[*i] == 'S' && line[(*i) + 1] == 'O' && line[(*i) + 2] == ' ')
	{
		yes = 1;
		line += 2;
		space_skip(&line);
	}
	if (yes == 1 && check_orient('S', orient) == 0)
		map->south = ft_strtrim(ft_strdup(line), "\n");
}

void	check_ea(char *orient, char *line, t_map *map, int *i)
{
	int	yes;

	yes = 0;
	if (!(line[*i] && line[(*i) + 1] && line[(*i) + 2]))
		return ;
	if (line[*i] == 'E' && line[(*i) + 1] == 'A' && line[(*i) + 2] == ' ')
	{
		yes = 1;
		line += 2;
		space_skip(&line);
	}
	if (yes == 1 && check_orient('E', orient) == 0)
		map->east = ft_strtrim(ft_strdup(line), "\n");
}

void	check_we(char *orient, char *line, t_map *map, int *i)
{
	int	yes;

	yes = 0;
	if (!(line[*i] && line[(*i) + 1] && line[(*i) + 2]))
		return ;
	if (line[*i] == 'W' && line[(*i) + 1] == 'E' && line[(*i) + 2] == ' ')
	{
		yes = 1;
		line += 2;
		space_skip(&line);
	}
	if (yes == 1 && check_orient('W', orient) == 0)
		map->west = ft_strtrim(ft_strdup(line), "\n");
}
