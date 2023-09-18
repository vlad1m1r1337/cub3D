/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:00 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/18 15:44:01 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_num_arrs(int **c_nums, int **f_nums)
{
	*c_nums = (int *)malloc(4 * sizeof(int));
	*f_nums = (int *)malloc(4 * sizeof(int));
	(*c_nums)[3] = -42;
	(*f_nums)[3] = -42;
}

void	hex_colors(int *c, int *f, t_game *game)
{
	int	hex_c;
	int	hex_f;

	hex_c = (c[0] << 16) | (c[1] << 8) | c[2];
	hex_f = (f[0] << 16) | (f[1] << 8) | f[2];
	game->floor_rgb = hex_f;
	game->ceiling_rgb = hex_c;
}

void	make_color_arr(char **rgb_arr, int *color_nums, int arr_size)
{
	while (rgb_arr[arr_size])
	{
		if (arr_size >= 3)
			parse_error("error: RGB colors must be 3 numbers\n");
		color_nums[arr_size] = check_num(rgb_arr[arr_size]);
		arr_size++;
	}
	if (arr_size != 3)
		parse_error("error: RGB colors must be 3 numbers\n");
	free(rgb_arr[0]);
	free(rgb_arr[1]);
	free(rgb_arr[2]);
	free(rgb_arr);
}

void	store_colors(char **ceil, char **flor, t_game *game)
{
	int		*c_nums;
	int		*f_nums;

	trim_spaces(ceil);
	trim_spaces(flor);
	init_num_arrs(&c_nums, &f_nums);
	make_color_arr(ceil, c_nums, 0);
	make_color_arr(flor, f_nums, 0);
	hex_colors(c_nums, f_nums, game);
	free(c_nums);
	free(f_nums);
}
