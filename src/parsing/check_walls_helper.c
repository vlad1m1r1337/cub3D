/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:06 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/18 15:44:08 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_num(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '0' && ft_strlen(number) != 1)
		parse_error("error: number starting with 0\n");
	else if (number[0] == '0' && ft_strlen(number) == 1)
		return (0);
	while (number[i])
	{
		if (number[i] > '9' || number[i] < '0')
			parse_error("error: numeric characters only\n");
		if (i >= 3)
			parse_error("error: RGB range = 0-255\n");
		i++;
	}
	i = ft_atoi(number);
	if (i < 0 || i > 255)
		parse_error("error: RGB range = 0-255\n");
	return (i);
}

void	parse_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	check_positions(char pos, char player, t_game *game, t_map *map)
{
	if (pos != '1' && pos != '0' && pos != player)
		game_exit_error(game, map, "error: map not enclosed in walls\n");
}

int	arrsize(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i - 1);
}
