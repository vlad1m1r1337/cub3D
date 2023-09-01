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

void	game_exit_error(t_game *game, t_map *map, char *pstr)
{
	if (game)
		free(game);
	ft_putstr_fd(pstr, 2);
	exit(1);
}

int	facing_check(t_game *game)
{
	if (game->n == 0 && game->s == 0 && game->e == 0 && game->w == 0)
		return (-1);
	if (game->n > 1 || game->s > 1 || game->e > 1 || game->w > 1)
		return (-1);
	else if (game->n == 1 && game->s != 0 && game->e != 0 && game->w != 0)
		return (-1);
	else if (game->s == 1 && game->n != 0 && game->e != 0 && game->w != 0)
		return (-1);
	else if (game->e == 1 && game->s != 0 && game->n != 0 && game->w != 0)
		return (-1);
	else if (game->w == 1 && game->s != 0 && game->e != 0 && game->n != 0)
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
	if (argc != 2 || (ft_strstr(argv[1], ".cub") == 0))
		game_exit(NULL, NULL, "error: invalid input\n");
	game = malloc(sizeof(t_game));
	if (!game)
		game_exit(NULL, NULL, "error: game struct malloc error\n");
	map = malloc(sizeof(t_map));
	if (!map)
		game_exit(game, NULL, "error: map struct malloc error\n");
	if (get_colors(argv[1], map) == -1)
		game_exit_error(game, map, "error: cannot open file\n");
	return (0);
}
