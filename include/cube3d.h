#ifndef CUBE_H
# define CUBE_H
# define HW  600

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

int px;
int py;
int flag;

int left;
int right;
int straight;
int back;

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
}			t_mlx;

void	hooks(t_mlx *mlx);

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

void	window_creating(t_mlx *mlx);

void	draw_yellow_square(t_mlx *mlx);

#endif