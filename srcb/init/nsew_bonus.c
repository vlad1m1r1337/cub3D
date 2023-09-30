/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsew.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:35:30 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/30 18:14:12 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	ns(t_mlx *mlx)
{
	if (mlx->gg->data->spawn_orient == 'N')
	{
		mlx->dir_x = -1;
		mlx->dir_y = 0;
		mlx->plane_x = 0;
		mlx->plane_y = 0.66;
	}
	else if (mlx->gg->data->spawn_orient == 'S')
	{
		mlx->dir_x = 1;
		mlx->dir_y = 0;
		mlx->plane_x = 0;
		mlx->plane_y = -0.66;
	}
}

void	ew(t_mlx *mlx)
{
	if (mlx->gg->data->spawn_orient == 'E')
	{
		mlx->dir_x = 0;
		mlx->dir_y = 1;
		mlx->plane_x = 0.66;
		mlx->plane_y = 0;
	}
	else if (mlx->gg->data->spawn_orient == 'W')
	{
		mlx->dir_x = 0;
		mlx->dir_y = -1;
		mlx->plane_x = -0.66;
		mlx->plane_y = 0;
	}
}
