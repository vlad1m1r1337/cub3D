/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:16:33 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/22 12:53:08 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx -> data + (y * mlx -> size_l + x * (mlx -> bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	rgb_to_hex(int r, int g, int b)
{
	unsigned int	hex_value;

	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;

	hex_value = (r << 16) | (g << 8) | b;

	return (hex_value);
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
