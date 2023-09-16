#ifndef CUBE_H
# define CUBE_H
# define H  600
# define W  600

# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125
# define RGB_Red 0xFF0000
# define RGB_Green 0x00FF00
# define RGB_Blue 0x0000FF
# define RGB_White 0xFFFFFF
# define RGB_Yellow 0xFFFF00


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>

//int worldMap[24][24];

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		endian;
	int		scale;
	int		x;
	int		y;
	int		size_l;

	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldTime;
	double cameraX;
	int		w;
	int		a;
	int		s;
	int		d;
}			t_mlx;

void	hooks(t_mlx *mlx);

void	my_pixel_put(t_mlx *mlx, int x, int y, int color);

void	window_creating(t_mlx *mlx);

void	draw_yellow_square(t_mlx *mlx);

unsigned int rgb_to_hex(int r, int g, int b);

#endif