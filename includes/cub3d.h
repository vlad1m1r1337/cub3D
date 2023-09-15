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
	int		n;
	int		s;
	int		e;
	int		w;
	char	*line;
	char	**grid;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	spawn_orient;
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
	t_map	*data;
	int		players;
	int		max_size;
	double	pos_player_x;
	double	pos_player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		hit;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		map_x;
	int		map_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	move_speed;
	double	turn_speed;
	double	wall_x;
	double	texture_x;
	double	texture_y;
	void	*sprite_north;
	void	*sprite_south;
	void	*sprite_west;
	void	*sprite_east;
	int		height_sprite;
	int		width_sprite;
	int		flc1;
	int		flc2;
	int		flc3;
	int		clc1;
	int		clc2;
	int		clc3;
	t_img	img;
	t_img	img_sprites[4];
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
size_t	ft_strlcpy2(char *dst, const char *src, size_t dstsize);
//parsing/check_file_head.c
void	space_skip(char **str);
void	check_no(char *orient, char *line, t_map *map, int *i);
void	check_so(char *orient, char *line, t_map *map, int *i);
void	check_ea(char *orient, char *line, t_map *map, int *i);
void	check_we(char *orient, char *line, t_map *map, int *i);
//parsing/check_walls.c
void	fill_colors(t_game *game, t_map *map, char **floor, char **ceiling);
void	free_arr(char **arr1, char **arr2);
void	check_posit(t_game *game, t_map *map, char pos, char player);
void	check_walls(t_game *game, t_map *map, int x, int j);
int		map_size(char **map);
//parsing/f_c_and_orient.c
void	check_c(char *orient, char *line, t_map *map, int *i);
void	check_f(char *orient, char *line, t_map *map, int *i);
void	update_orient(char c, char *orient);
int		check(const char *(haystack), const char *(needle), size_t len);
int		check_orient(char c, char *orient);
//parsing/map_parse.c
void	get_colors(char *str, t_map *map, t_game *game);
void	parse_map(char *str, t_game *game, t_map *map, int fd);
void	parsing_magic(char *str, t_game *game, t_map *map);
void	check_data(char *orient, t_map *map, char *line);
void	check_colors(t_game *game, t_map *map);
//parsing/parse_map_utils.c
void	store_grid(t_game *game, t_map *map, int fd);
void	alloc_grid(t_map *map, t_game *game);
void	trim_grid(t_map *map);
void	set_count(t_map *map);
int		char_chk(char *str);
//parsing/parse_map_utils2.c
void	dup_cnt(t_map *map, t_game *game);
void	skip_whitespace(char *line, int *i);
int		orient_empty(char *orient);
int		arr_size(char **arr);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
//main.c
int		chr_count(char *str, char c);
int		facing_check(t_map *map);
void	game_exit_error(t_game *game, t_map *map, char *pstr);
#endif