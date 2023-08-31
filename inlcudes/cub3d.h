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

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "string.h"
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
	char	**map;
	int		players;
	double	position_player_x;
	double	position_player_y;
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
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		floor_color;
	int		ceiling_color;
	int		count_arguments_in_file;
	t_img	img;
	t_img	img_sprites[4];
}			t_game;
