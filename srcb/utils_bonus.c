/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:16:33 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/30 18:14:58 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img.addr + (y * mlx->img.line_length + \
			x * (mlx->img.bits_per_pixel / 8));
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
	system("killall afplay");
	exit(0);
}

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}
