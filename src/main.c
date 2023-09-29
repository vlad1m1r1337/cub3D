/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:20:39 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/29 17:58:13 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_mlx	*mlx;
	mlx = malloc(sizeof(t_mlx));
	window_creating(mlx);
	parsing(argc, argv);
	initial_game_parametres(mlx);
	char worldMap[MAP_WIDTH][MAP_HEIGHT] = {
			{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '0', '1', '1', '1', '1', '1', '0', '1'},
			{'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
			{'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
			{'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};
	//recopy in map
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			mlx->worldMap[i][j] = worldMap[i][j];
		}
	}
	mlx_loop_hook(mlx->mlx_ptr, &render, mlx);
	hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
