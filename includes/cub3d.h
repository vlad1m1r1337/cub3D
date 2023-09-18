/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:18:18 by jfrances          #+#    #+#             */
/*   Updated: 2023/08/31 16:18:27 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../src/gnl/get_next_line.h"
# include <math.h>

# define A				0
# define S				1
# define D				2
# define W				13
# define RIGHT			124
# define LEFT			123
# define ESC			53
# define WINDOW_W		640
# define WINDOW_H		480
# define TEX_WIDTH		64
# define TEX_HEIGHT		64

typedef struct s_map
{
	int		cnt;
	int		size;
	int		fd;
	char	*line;
	char	**grid;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	s_orient;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	int		players;
	int		max_size;
	double	posx;
	double	posy;
	void	*sprite_north;
	void	*sprite_south;
	void	*sprite_west;
	void	*sprite_east;
	int		height_sprite;
	int		width_sprite;
	int		floor_rgb;
	int		ceiling_rgb;
	t_img	*image;
	t_img	*wallt;
	t_img	*n;
	t_img	*w;
	t_img	*s;
	t_img	*e;
}			t_game;

//src/minilib/ft_split.c
char	**ft_split(char const *s, char c);
//src/minilib/minilib.c
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		new_ft_atoi(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr2(const char *s, int c);
//src/minilib/minilib2.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
size_t	ft_strlcpy2(char *dst, const char *src, size_t dstsize);
//parsing/check_walls_helper.c
int		check_num(char *number);
void	parse_error(char *str);
void	check_positions(char pos, char player, t_game *game, t_map *map);
int		arrsize(char **arr);
//parsing/color_conversion.c
void	init_num_arrs(int **c_nums, int **f_nums);
void	hex_colors(int *c, int *f, t_game *game);
void	make_color_arr(char **rgb_arr, int *color_nums, int arr_size);
void	store_colors(char **ceil, char **flor, t_game *game);
//parsing/map_parse.c
void	new_line(t_map *map, char *str);
void	parse_map(char *str, t_game *game, t_map *map, int i);
int		check_map(char *str, t_map *map, t_game *game);
void	final_check(int fd, t_map *map, t_game *game);
void	check_walls(t_map *map, t_game *game, int i, int j);
//parsing/parse_map_utils.c
void	trim_spaces(char **arr);
void	space_skip(char **str);
void	dup_grid(char **src, char **dest);
void	free_grid(char **free_me);
//parsing/parsing_start_help.c
int		orient_check(char *orient);
void	trim_stuff(t_map *map);
void	check_textures(t_game *game, t_map *map);
void	confirm_textures(char *arr, t_map *map, t_game *game);
//parsing/parsing_start.c
void	set_game_set_map(char **argv, t_game *game);
void	parsing_next(char *str, t_map *map, t_game *game);
void	get_colors(t_game *game, t_map *map);
int		get_info(char *line, char *orient, t_map *map, t_game *game);
int		add_info(char to_remove, t_game *game, char *orient, char *line);
//main.c
void	game_exit_error(t_game *game, t_map *map, char *pstr);
int		facing_check(t_map *map);
int		chr_count(char *str, char c);

#endif