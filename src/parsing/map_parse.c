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

#include "../so_long.h"	

static void	fill(char **tab, t_parse *pr, int x, int y)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = pr->x;
	tmp_y = pr->y;
	if (tab[x][y] == '1')
		return ;
	else if (tab[x][y] == 'C')
		pr->c -= 1;
	else if (tab[x][y] == 'E')
		pr->e -= 1;
	tab[x][y] = '1';
	fill(tab, pr, x + 1, y);
	fill(tab, pr, x - 1, y);
	fill(tab, pr, x, y + 1);
	fill(tab, pr, x, y - 1);
}

static void	invalid_chars(char **tab, t_parse *pr)
{
	int	chk;
	int	i;
	int	j;

	i = -1;
	chk = 0;
	j = -1;
	while (tab[++i] != NULL)
	{
		if (tab[i] == NULL)
			break ;
		j = -1;
		while (tab[i][++j] != '\0')
		{
			if (tab[i][j] != '1' && tab[i][j] != '0' && tab[i][j] != 'P' && \
			tab[i][j] != 'E' && tab[i][j] != 'C' && tab[i][j] != '\n')
				chk = 1;
		}
	}
	if (chk == 1)
	{
		free_matrix(tab, 0, "");
		free_matrix(pr->map, 1, "Invalid Input");
	}
}

static void	arr2d_cpy(t_parse *pr)
{
	char	**tab;
	int		tmp;

	tmp = 0;
	tab = (char **)malloc(sizeof(char *) * (pr->i + 1));
	if (!tab)
		free_matrix(pr->map, 1, "");
	while (tmp < pr->i)
	{
		tab[tmp] = (char *)malloc(sizeof (char) * (pr->len + 1));
		if (!tab[tmp])
			free_matrix(pr->map, 1, "Invalid Input");
		tmp++;
	}
	tmp = 0;
	while (tmp < pr->i)
	{
		ft_strcpy(tab[tmp], pr->map[tmp]);
		tmp++;
	}
	tab[tmp] = NULL;
	invalid_chars(tab, pr);
	fill(tab, pr, pr->x, pr->y);
	free_matrix(tab, 0, "");
}

int	grid_cpy(t_parse *tptr, char *str)
{
	int	fd;
	int	tmp;

	map_parse(str, tptr);
	fd = open_file(str);
	tptr->map = (char **)malloc(sizeof(char *) * (tptr->i + 1));
	if (!tptr->map)
		return (0);
	tmp = tptr->i + 1;
	while (tmp)
		--tmp;
	while (tmp < tptr->i)
		tptr->map[tmp++] = get_next_line(fd);
	tptr->map[tmp] = NULL;
	tptr->tmp_c = tptr->c;
	check_walls(tptr);
	grab_player(tptr);
	arr2d_cpy(tptr);
	if (tptr->c != 0 || tptr->e != 0)
		free_matrix(tptr->map, 1, "Invalid Input");
	return (1);
}

void	map_parse(char *str, t_parse *tptr)
{
	int	fd;

	fd = open_file(str);
	tptr->line = get_next_line(fd);
	if (tptr->line == NULL)
		game_exit("Read Error");
	tptr->len = ft_strlen(tptr->line) - ft_strchr_num(tptr->line, '\n');
	if (!tptr->line)
		game_exit("Empty Map");
	tptr->i = 0;
	while (tptr->line != '\0')
	{	
		tptr->c += chr_count(tptr->line, 'C');
		tptr->e += chr_count(tptr->line, 'E');
		tptr->p += chr_count(tptr->line, 'P');
		free(tptr->line);
		tptr->line = get_next_line(fd);
		tptr->i += 1;
	}
	free(tptr->line);
	close (fd);
	if (tptr->i >= 18 || tptr->len >= 34)
		game_exit("Map is too large for system's monitor");
	token(tptr->c, tptr->e, tptr->p);
}
