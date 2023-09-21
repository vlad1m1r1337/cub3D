#include "../includes/cub3d.h"

void	my_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx -> data + (y * mlx -> size_l + x * (mlx -> bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int rgb_to_hex(int r, int g, int b) {
	// Ensure RGB values are within the valid range (0-255)
	r = (r < 0) ? 0 : ((r > 255) ? 255 : r);
	g = (g < 0) ? 0 : ((g > 255) ? 255 : g);
	b = (b < 0) ? 0 : ((b > 255) ? 255 : b);

	// Calculate the hexadecimal value
	unsigned int hex_value = (r << 16) | (g << 8) | b;

	return hex_value;
}

int	ex(void)
{
	exit(0);
}

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}
