/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:18:54 by jfrances          #+#    #+#             */
/*   Updated: 2023/10/02 16:18:56 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../srcb/gnl/get_next_line_bonus.h"
# include <math.h>

# define H  800
# define W  800
# define TEXT_WIDTH 64
# define TEXT_HEIGHT 64
# define DELAY 800000000
# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125

typedef struct s_helper {
	int		i;
	int		n_cnt;
	int		s_cnt;
	int		e_cnt;
	int		w_cnt;
	int		f_cnt;
	int		c_cnt;
	char	*line;
}			t_helper;

typedef struct s_rayimg {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_rayimg;

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

typedef struct s_game
{
	t_map		*data;
	char		facing;
	double		pos_player_x;
	double		pos_player_y;
	t_rayimg	img_sprites[4];
	t_rayimg	img;
	void		*anim1;
	void		*anim2;
	void		*anim3;
	void		*anim4;
	int			flc1;
	int			flc2;
	int			flc3;
	int			clc1;
	int			clc2;
	int			clc3;
	int			fd;
}			t_game;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			endian;
	int			scale;
	int			x;
	int			y;
	int			size_l;
	t_game		*gg;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			w;
	int			a;
	int			s;
	int			d;
	int			arrow_left;
	int			arrow_right;
	double		move_speed;
	double		rot_speed;
	t_rayimg	img_sprites[4];
	t_rayimg	img;
	void		*image_n;
	void		*image_s;
	void		*image_w;
	void		*image_e;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			hit;
	int			draw_start;
	int			draw_end;
	int			line_height;
	int			tex_x;
	double		tex_pos;
	double		step;
	FILE		*pipe;
}			t_mlx;

//vova one weird function
unsigned int	rgb_to_hex(int r, int g, int b);
//src/minilib/ft_split.c
char			**ft_split(char const *s, char c);
//src/minilib/minilib.c
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
int				new_ft_atoi(const char *str);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strchr2(const char *s, int c);
//src/minilib/minilib2.c
size_t			ft_strlcpy2(char *dst, const char *src, size_t dstsize);
//parsing/check_file_head.c
void			space_skip(char **str);
void			check_no(char *orient, char *line, t_map *map, int *i);
void			check_so(char *orient, char *line, t_map *map, int *i);
void			check_ea(char *orient, char *line, t_map *map, int *i);
void			check_we(char *orient, char *line, t_map *map, int *i);
//parsing/check_walls.c
void			fill_colors(t_game *game, t_map *map, \
char **floor, char **ceiling);
void			free_arr(char **arr1);
void			check_posit(t_game *game, t_map *map, char pos, char player);
void			check_walls(t_game *game, t_map *map, int x, int j);
int				map_size(char **map);
//parsing/f_c_and_orient.c
void			check_c(char *orient, char *line, t_map *map, int *i);
void			check_f(char *orient, char *line, t_map *map, int *i);
void			update_orient(char c, char *orient);
int				check(const char *(haystack), const char *(needle), size_t len);
int				check_orient(char c, char *orient);
//parsing/map_parse.c
void			get_colors(char *str, t_map *map, t_game *game);
void			parse_map(char *str, t_game *game, t_map *map);
void			parsing_magic(char *str, t_game *game, t_map *map);
void			check_data(char *orient, t_map *map, char *line);
void			check_colors(t_game *game, t_map *map);
//parsing/parse_map_utils.c
void			store_grid(t_game *game, t_map *map);
void			alloc_grid(t_map *map, t_game *game);
void			trim_grid(t_map *map);
void			set_count(t_map *map);
int				char_chk(char *str);
//parsing/parse_map_utils2.c
void			dup_cnt(t_map *map, t_game *game);
void			skip_whitespace(char *line, int *i);
int				orient_empty(char *orient);
int				arr_size(char **arr);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
//main.c
int				chr_count(char *str, char c);
int				facing_check(t_map *map);
void			game_exit_error(t_game *game, t_map *map, char *pstr, int flag);
//misc
void			after_map(t_game *game, t_map *map);
void			create_int_array(t_game *game, t_map *map);
void			parsing(t_game *game, int argc, char **argv);
void			game_exit(t_game *game, t_map *map, char *pstr);
void			check_map_count(t_game *game, t_map *map);
void			bruno_textures(t_mlx *mlx);
void			init_frame_pos(int *frame_pos);
int				fc_garbage(char *floor, char *ceil);
void			garbage_check(t_game *game, t_map *map, int fd, char *str);
void			map_init(t_map *map);
void			free_arr2(char **arr1, char **arr2);
int				norm_cnt(t_helper *h, int flg);
//vova
void			hooks(t_mlx *mlx);
void			my_pixel_put(t_mlx *mlx, int x, int y, int color);
void			window_creating(t_mlx *mlx);
void			draw_yellow_square(t_mlx *mlx);
int				ex(void);
void			moving(t_mlx *mlx);
void			draw_wall_ceil(t_mlx *mlx);
void			raycasting(t_mlx *mlx);
int				render(t_mlx *mlx);
float			ft_abs(float num);
void			initial_game_parametres(t_mlx *mlx);
void			spin_left(t_mlx *mlx);
void			spin_right(t_mlx *mlx);
void			draw_wall_ceil(t_mlx *mlx);
void			moving_forward(t_mlx *mlx);
void			moving_back(t_mlx *mlx);
void			moving_right(t_mlx *mlx);
void			moving_left(t_mlx *mlx);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			calculate_dist(t_mlx *mlx, int x);
void			preparing_to_dda(t_mlx *mlx);
void			dda(t_mlx *mlx);
void			calc_draw_start_end(t_mlx *mlx);
void			error_handle(t_game *game);
void			ns(t_mlx *mlx);
void			ew(t_mlx *mlx);
void			musik(void);
#endif