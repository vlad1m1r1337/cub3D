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

#include "../includes/cub3d.h"	

void	check_posit(t_game *game, t_map *map, char pos, char player)
{
	if (pos != '1' && pos != '0' && pos != player)
		game_exit_error(game, map, "error: map not enclosed in WALLS\n");
}

int	map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i - 1);
}

void	check_walls(t_game *game, t_map *map, int x, int j)
{
	while (map->grid[x])
	{
		j = 0;
		while (map->grid[x][j])
		{
			if (map->grid[x][j] == map->spawn_orient)
			{
				game->pos_player_y = x + 0.5;
				game->pos_player_x = j + 0.5;
				map->grid[x][j] = '0';
			}
			if (map->grid[x][j] == '0')
			{
				if (x == 0 || x == map_size(map->grid))
					game_exit_error(game, map, "error: not enclosed in walls\n");
				check_posit(game, map, map->grid[x - 1][j], map->spawn_orient);
				check_posit(game, map, map->grid[x + 1][j], map->spawn_orient);
				check_posit(game, map, map->grid[x][j - 1], map->spawn_orient);
				check_posit(game, map, map->grid[x][j + 1], map->spawn_orient);
			}
			j++;
		}
		x++;
	}
}

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

static char	*ft_putword(const char *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	word = malloc(sizeof(char) * (j + 1));
	if (!word)
		return (0);
	i -= j;
	j = 0;
	while (s[i] && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

static void	ft_free(int i, char **new)
{
	while (i > 0)
	{
		free(new[i - 1]);
		i--;
	}
	free(new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		wc;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = -1;
	j = 0;
	wc = ft_wordcount(s, c);
	new = malloc(sizeof(char *) * wc + 1);
	if (!new)
		return (new);
	while (++i < wc)
	{
		while (s[j] && s[j] == c)
			j++;
		new[i] = ft_putword(&s[j], c);
		if (!new[i])
			ft_free(i, new);
		while (s[j] && s[j] != c)
			j++;
	}
	new[i] = 0;
	return (new);
}

int	new_ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
	}
	return (result);
}

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr1, char **arr2)
{
	int	i;

	i = 0;
	while (arr1[i])
	{
		free(arr1[i]);
		i++;
	}
	free(arr1);
	i = 0;
	while (arr2[i])
	{
		free(arr2[i]);
		i++;
	}
	free(arr2);
}

void	fill_colors(t_game *game, t_map *map, char **floor, char **ceiling)
{
	game->flc1 = new_ft_atoi(floor[0]);
	game->flc2 = new_ft_atoi(floor[1]);
	game->flc3 = new_ft_atoi(floor[2]);
	game->clc1 = new_ft_atoi(ceiling[0]);
	game->clc2 = new_ft_atoi(ceiling[1]);
	game->clc3 = new_ft_atoi(ceiling[2]);
	if (game->flc1 < 0 || game->flc2 < 0 || game->flc3 < 0 \
	|| game->clc1 < 0 || game->clc2 < 0 || game->clc3 < 0)
	{
		free_arr(floor, ceiling);
		game_exit_error(game, map, "error: RGB values incorrect\n");
	}
}

void	check_colors(t_game *game, t_map *map)
{
	char	**tmp_floor;
	char	**tmp_ceiling;
	int		flag;

	flag = 0;
	map->floor = ft_strtrim(map->floor, " ");
	map->ceiling = ft_strtrim(map->ceiling, " ");
	map->floor = ft_strtrim(map->floor, "\n");
	map->ceiling = ft_strtrim(map->ceiling, "\n");
	tmp_floor = ft_split(map->floor, ',');
	tmp_ceiling = ft_split(map->ceiling, ',');
	if (arr_size(tmp_floor) != 3 && arr_size(tmp_ceiling) != 3)
	{
		free_arr(tmp_floor, tmp_ceiling);
		flag = 1;
	}
	fill_colors(game, map, tmp_floor, tmp_ceiling);
	if (flag == 0)
		free_arr(tmp_floor, tmp_ceiling);
}

void	set_count(t_map *map)
{
	map->n = 0;
	map->s = 0;
	map->e = 0;
	map->w = 0;
}

void	skip_whitespace(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n') \
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
}

void	check_data(char *orient, t_map *map, char *line)
{
	int	i;

	i = 0;
	skip_whitespace(line, &i);
	check_no(orient, line, map, &i);
	check_so(orient, line, map, &i);
	check_ea(orient, line, map, &i);
	check_we(orient, line, map, &i);
	check_f(orient, line, map, &i);
	check_c(orient, line, map, &i);
}

int	orient_empty(char *orient)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (orient[i])
	{
		if (orient[i] == 'N' || orient[i] == 'S' || \
		orient[i] == 'E' || orient[i] == 'W' \
		|| orient[i] == 'F' || orient[i] == 'C')
			count++;
		i++;
	}
	if (count == 0)
		return (-1);
	return (0);
}

void	get_colors(char *str, t_map *map, t_game *game)
{
	int		fd;
	char	*orient;
	int		cnt;

	orient = ft_strdup("NSEWFC");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		game_exit_error(game, map, "error: file cannot open\n");
	map->cnt = 1;
	map->line = get_next_line(fd);
	while (orient_empty(orient) != -1 && map->line != NULL)
	{
		check_data(orient, map, map->line);
		free(map->line);
		map->cnt++;
		if (cnt != 1)
			map->line = get_next_line(fd);
	}
	if (orient_empty(orient) == 0)
	{
		close(fd);
		game_exit_error(game, map, "error: invalid descriptors\n");
	}
	parse_map(str, game, map, fd);
}

void	parse_map(char *str, t_game *game, t_map *map, int fd)
{
	map->line = get_next_line(fd);
	while (map->line != NULL && map->line[0] == '\n')
	{
		free(map->line);
		map->line = get_next_line(fd);
	}
	if (map->line != NULL)
	{
		map->size = 1;
		while (map->line != NULL && map->line[0] != '\n')
		{
			free(map->line);
			map->line = get_next_line(fd);
			map->size++;
		}
	}
	close(fd);
	set_count(map);
	parsing_magic(str, game, map);
}

void	alloc_grid(t_map *map, t_game *game)
{
	map->grid = (char **)malloc(sizeof(char *) * map->size + 1);
	if (!map->grid)
		game_exit_error(game, map, "error: malloc: fatal\n");
	map->grid[map->size + 1] = NULL;
}

void	dup_cnt(t_map *map, t_game *game)
{
	int	i;

	i = -1;
	while (map->grid[++i] != NULL)
	{
		if (char_chk(map->grid[i]) == -1)
			game_exit_error(game, map, "error: invalid characters in map\n");
		map->n += chr_count(map->grid[i], 'N');
		map->s += chr_count(map->grid[i], 'S');
		map->e += chr_count(map->grid[i], 'E');
		map->w += chr_count(map->grid[i], 'W');
	}
	if (facing_check(map) == -1)
		game_exit_error(game, map, "error: invalid facings\n");
	check_colors(game, map);
}

void	store_grid(t_game *game, t_map *map, int fd)
{
	int	i;

	i = 1;
	while (i < map->size)
	{
		map->grid[i] = get_next_line(fd);
		i++;
	}
	trim_grid(map, game);
	dup_cnt(map, game);
}

void	parsing_magic(char *str, t_game *game, t_map *map)
{
	int	fd;
	int	i;

	fd = open(str, O_RDONLY);
	while (map->cnt != 0)
	{
		map->line = get_next_line(fd);
		free(map->line);
		map->cnt--;
	}
	alloc_grid(map, game);
	map->line = get_next_line(fd);
	while (map->line != NULL && map->line[0] == '\n')
	{
		free(map->line);
		map->line = get_next_line(fd);
	}
	if (map->line != NULL)
	{
		map->grid[0] = ft_strdup(map->line);
		free(map->line);
	}
	store_grid(game, map, fd);
	close (fd);
	check_walls(game, map, 0, 0);
}

void	trim_grid(t_map *map, t_game *game)
{
	int	i;

	i = -1;
	while (map->grid[++i] != NULL)
		map->grid[i] = ft_strtrim(map->grid[i], "\n");
}

int	char_chk(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'N' && str[i] != '0' && str[i] != '1' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}
