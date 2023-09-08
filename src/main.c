/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:20:39 by jfrances          #+#    #+#             */
/*   Updated: 2023/08/31 16:20:41 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	game_exit_error(t_game *game, t_map *map, char *pstr)
{
	if (!game)
	{
		if (!map)
		{
			ft_putstr_fd(pstr, 2);
			exit(1);
		}
		free(map);
	}
	free(game);
	ft_putstr_fd(pstr, 2);
	exit(1);
}

int	facing_check(t_map *map)
{
	if (map->n == 0 && map->s == 0 && map->e == 0 && map->w == 0)
		return (-1);
	if (map->n > 1 || map->s > 1 || map->e > 1 || map->w > 1)
		return (-1);
	else if (map->n == 1 && (map->s != 0 || map->e != 0 || map->w != 0))
		return (-1);
	else if (map->s == 1 && (map->n != 0 || map->e != 0 || map->w != 0))
		return (-1);
	else if (map->e == 1 && (map->s != 0 || map->n != 0 || map->w != 0))
		return (-1);
	else if (map->w == 1 && (map->s != 0 || map->e != 0 || map->n != 0))
		return (-1);
	return (0);
}

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

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_game	*game;
	t_map	*map;

	i = -1;
	j = i;
	if (argc != 2 || (ft_strnstr(argv[1], ".cub", 4) != 0))
		game_exit_error(NULL, NULL, "error: invalid input\n");
	game = malloc(sizeof(t_game));
	if (!game)
		game_exit_error(NULL, NULL, "error: game struct malloc error\n");
	map = malloc(sizeof(t_map));
	if (!map)
		game_exit_error(game, NULL, "error: map struct malloc error\n");
	if (get_colors(argv[1], map, game) == -1)
		game_exit_error(game, map, "error: cannot open file\n");
	return (0);
}
