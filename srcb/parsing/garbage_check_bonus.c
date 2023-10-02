/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:14:11 by jfrances          #+#    #+#             */
/*   Updated: 2023/10/02 16:14:12 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	basura(char *s, int i)
{
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

static int	nosoeawe(t_helper *h, char *s, int i)
{
	if (s[i] == 'N' && s[i + 1] && s[i + 2] \
	&& s[i + 1] == 'O' && s[i + 2] == ' ')
		return (norm_cnt(h, 1));
	else if (s[i] == 'S' && s[i + 1] && s[i + 2] \
	&& s[i + 1] == 'O' && s[i + 2] == ' ')
		return (norm_cnt(h, 2));
	else if (s[i] == 'E' && s[i + 1] && s[i + 2] \
	&& s[i + 1] == 'A' && s[i + 2] == ' ')
		return (norm_cnt(h, 3));
	else if (s[i] == 'W' && s[i + 1] && s[i + 2] \
	&& s[i + 1] == 'E' && s[i + 2] == ' ')
		return (norm_cnt(h, 4));
	else if (s[i] == 'F' && s[i + 1] && s[i + 1] == ' ')
		return (norm_cnt(h, 5));
	else if (s[i] == 'C' && s[i + 1] && s[i + 1] == ' ')
		return (norm_cnt(h, 6));
	return (1);
}

static void	initialize_helper(t_helper *help)
{
	help->i = 0;
	help->n_cnt = 0;
	help->e_cnt = 0;
	help->s_cnt = 0;
	help->w_cnt = 0;
	help->f_cnt = 0;
	help->c_cnt = 0;
	help->line = NULL;
}

static int	es_basura(t_helper *h, char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (!nosoeawe(h, s, i))
		return (0);
	else if (basura(s, i) == -1)
		return (-1);
	return (0);
}

void	garbage_check(t_game *game, t_map *map, int fd, char *str)
{
	t_helper	h;

	initialize_helper(&h);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		game_exit_error(game, map, "error: file does not open\n", 1);
	while (h.i < map->cnt)
	{
		h.line = get_next_line(fd);
		if (es_basura(&h, h.line) == -1)
		{
			free(h.line);
			close(fd);
			game_exit_error(game, map, "error: bad values in head\n", 1);
		}
		free(h.line);
		h.i++;
	}
	close(fd);
	if (h.n_cnt > 1 || h.s_cnt > 1 \
	|| h.e_cnt > 1 || h.w_cnt > 1 || h.f_cnt > 1 || h.c_cnt > 1)
		game_exit_error(game, map, "error: duplicate paths\n", 1);
}
