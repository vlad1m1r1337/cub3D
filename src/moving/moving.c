/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:50:35 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/29 17:55:12 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	spin_left(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(mlx->rot_speed) - \
		mlx->dir_y * sin(mlx->rot_speed);
	mlx->dir_y = olddir_x * sin(mlx->rot_speed) + \
		mlx->dir_y * cos(mlx->rot_speed);
	oldplane_x = mlx->plane_x;
	mlx->plane_x = mlx->plane_x * cos(mlx->rot_speed) - \
		mlx->plane_y * sin(mlx->rot_speed);
	mlx->plane_y = oldplane_x * sin(mlx->rot_speed) + \
		mlx->plane_y * cos(mlx->rot_speed);
}

void	spin_right(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(-(mlx->rot_speed)) - \
		mlx->dir_y * sin(-(mlx->rot_speed));
	mlx->dir_y = olddir_x * sin(-(mlx->rot_speed)) + \
		mlx->dir_y * cos(-(mlx->rot_speed));
	oldplane_x = mlx->plane_x;
	mlx->plane_x = mlx->plane_x * cos(-(mlx->rot_speed)) - \
		mlx->plane_y * sin(-(mlx->rot_speed));
	mlx->plane_y = oldplane_x * sin(-(mlx->rot_speed)) + \
		mlx->plane_y * cos(-(mlx->rot_speed));
}

void	moving(t_mlx *mlx)
{
	if (mlx -> w)
		moving_forward(mlx);
	if (mlx -> s)
		moving_back(mlx);
	if (mlx -> d)
		moving_right(mlx);
	if (mlx -> a)
		moving_left(mlx);
	if (mlx->arrow_left)
		spin_left(mlx);
	if (mlx->arrow_right)
		spin_right(mlx);
}
