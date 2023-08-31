/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:18 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/10 14:22:59 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	check_columns(t_parse *pr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pr->map[i][j] && pr->map[i][j] != '\n')
		j++;
	while (pr->map[i] != '\0')
	{
		if (pr->map[i][0] != '1' && pr->map[i][j] != \
				pr->map[i][pr->len] && pr->map[i][j] != '1')
			free_matrix(pr->map, 1, "Columns");
		if (ft_strlen(pr->map[i]) - ft_strchr_num(pr->map[i], '\n') != pr->len)
			free_matrix(pr->map, 1, "Columns");
		i++;
	}
}

void	check_walls(t_parse *pr)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (pr->map[0][++i] && pr->map[0][i] != '\n')
	{
		if (pr->map[0][i] != '1')
			free_matrix(pr->map, 1, "Top Wall");
		j++;
	}
	j -= 1;
	i = 0;
	while (pr->map[i] != '\0')
		i++;
	j = -1;
	i -= 1;
	while (pr->map[i][++j] != '\0')
	{
		if (pr->map[i][j] != '1')
			free_matrix(pr->map, 1, "Bottom Wall");
	}
	check_columns(pr);
}

void	grab_player(t_parse *tptr)
{
	int	i;
	int	j;

	i = 0;
	while (tptr->map[i] != '\0')
	{
		j = 0;
		while (tptr->map[i][j] != '\0')
		{
			if (tptr->map[i][j] == 'P')
			{
				tptr->x = i;
				tptr->player.x = i;
				tptr->y = j;
				tptr->player.y = j;
			}
			j++;
		}
		i++;
	}
}

int	token(int c, int e, int p)
{
	if (c <= 0 || e != 1 || p != 1)
	{
		printf("Invalid Number of Starting Tokens\n");
		exit(0);
	}
	return (0);
}
