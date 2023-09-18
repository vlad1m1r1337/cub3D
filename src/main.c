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

static int	name_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (str[i])
		i++;
	while (str[i] != '.')
		i--;
	while (++j < i)
		str++;
	if (!str || ft_strncmp(str, ".cub", 4) != 0)
		return (-1);
	return (0);
}

void	game_exit_error(t_game *game, t_map *map, char *pstr)
{
	if (!game)
	{
		if (!map)
		{
			ft_putstr_fd(pstr, 2);
			exit(1);
		}
		//free(map);
	}
	//free(game);
	ft_putstr_fd(pstr, 2);
	exit(1);
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
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		game_exit_error(NULL, NULL, "error: game struct malloc error\n");
	if (argc != 2 || (name_check(argv[1]) == -1))
		game_exit_error(NULL, NULL, "error: invalid input\n");
	set_game_set_map(argv, game);
	return (0);
}
