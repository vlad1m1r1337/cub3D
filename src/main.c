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

void	game_exit(char *pstr)
{
	ft_printf("%s\n", pstr);
	exit(0);
}

void	intialize_vars(char *str, t_game *game)
{
	
	if (grid_cpy(game, str) == 0)
		game_exit("ERROR");
}

parser
	...
	parseLine
		parseSemicolon
			if (c != ';')
				throw ParserError();
	try {
		parseLine()
	} catch { }

int	main(int argc, char **argv)
{	
	int		i;
	int		j;
	t_game	game;

	i = -1;
	j = i;
	if (argc != 2 || (ft_strstr(argv[1], ".ber") == 0))
		game_exit("Error: Invalid Input");
	game = malloc(sizeof(t_game));
	if (!game)
		game_exit("Error: Malloc Error");
	intialize_vars(argv[1], game);
	ft_window_initialize(game, i, j);
	return (0);
}
