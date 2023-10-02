/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c_and_orient_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:10:28 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/02 15:10:30 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	check_orient(char c, char *orient)
{
	int	i;

	i = 0;
	while (orient[i] && orient[i] != c)
		i++;
	if (orient[i] == c)
	{
		orient[i] = ' ';
		return (0);
	}
	return (-1);
}

int	check(const char *(haystack), const char *(needle), size_t len)
{
	while (*haystack == *needle && *haystack && len--)
	{
		haystack++;
		needle++;
	}
	if (*needle == '\0')
		return (1);
	return (0);
}

void	update_orient(char c, char *orient)
{
	int	i;

	i = 0;
	while (orient[i] != c)
		i++;
	orient[i] = ' ';
}

void	check_f(char *orient, char *line, t_map *map, int *i)
{	
	int	yes;

	yes = 0;
	if (!(line[*i] && line[(*i) + 1] && line[(*i) + 2]))
		return ;
	if (line[*i] == 'F' && line[(*i) + 1] == ' ')
	{
		yes = 1;
		line += 1;
		space_skip(&line);
	}
	if (yes == 1 && check_orient('F', orient) == 0)
		map->floor = ft_strdup(line);
}

void	check_c(char *orient, char *line, t_map *map, int *i)
{
	int	yes;

	yes = 0;
	if (!(line[*i] && line[(*i) + 1] && line[(*i) + 2]))
		return ;
	if (line[*i] == 'C' && line[(*i) + 1] == ' ')
	{
		yes = 1;
		line += 1;
		space_skip(&line);
	}
	if (yes == 1 && check_orient('C', orient) == 0)
		map->ceiling = ft_strdup(line);
}
