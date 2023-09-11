#ifndef CUBE_H
# define CUBE_H
# define H  600
# define W  600

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

int worldMap[24][24];

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

#endif