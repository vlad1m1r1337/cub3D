/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:50:35 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/22 12:53:30 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	moving_forward(t_mlx *mlx)
{
	double	temp_x;
	double	temp_y;

	temp_x = mlx->pos_x + mlx->dir_x * mlx->moveSpeed;
	temp_y = mlx->pos_y + mlx->dir_y * mlx->moveSpeed;

	if (mlx->worldMap[(int)temp_x][(int)temp_y] != '1')
	{
		mlx->pos_x = temp_x;
		mlx->pos_y = temp_y;
	}
}

void	moving_back(t_mlx *mlx)
{
	double	temp_x;
	double	temp_y;

	temp_x = mlx->pos_x - mlx->dir_x * mlx->moveSpeed;
	temp_y = mlx->pos_y - mlx->dir_y * mlx->moveSpeed;

	if (mlx->worldMap[(int)temp_x][(int)temp_y] != '1')
	{
		mlx->pos_x = temp_x;
		mlx->pos_y = temp_y;
	}
}

void	moving_right(t_mlx *mlx)
{
	double	temp_x;
	double	temp_y;

	temp_x = mlx->pos_x + mlx->plane_x * mlx->moveSpeed;
	temp_y = mlx->pos_y;

	if (mlx->worldMap[(int)temp_x][(int)temp_y] != '1')
	{
		mlx->pos_x = temp_x;
		mlx->pos_y = temp_y;
	}
}

void moving_left(t_mlx *mlx)
{
	double	temp_x;
	double	temp_y;

	temp_x = mlx->pos_x - mlx->plane_x * mlx->moveSpeed;
	temp_y = mlx->pos_y;

	if (mlx->worldMap[(int)temp_x][(int)temp_y] != '1')
	{
		mlx->pos_x = temp_x;
		mlx->pos_y = temp_y;
	}
}

void	spin_left(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(mlx->rotSpeed) - mlx->dir_y * sin(mlx->rotSpeed);
	mlx->dir_y = olddir_x * sin(mlx->rotSpeed) + mlx->dir_y * cos(mlx->rotSpeed);
	oldplane_x = mlx->plane_x;
	mlx->plane_x = mlx->plane_x * cos(mlx->rotSpeed) - mlx->plane_y * sin(mlx->rotSpeed);
	mlx->plane_y = oldplane_x * sin(mlx->rotSpeed) + mlx->plane_y * cos(mlx->rotSpeed);
}

void	spin_right(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(-(mlx->rotSpeed)) - mlx->dir_y * sin(-(mlx->rotSpeed));
	mlx->dir_y = olddir_x * sin(-(mlx->rotSpeed)) + mlx->dir_y * cos(-(mlx->rotSpeed));
	oldplane_x = mlx->plane_x;
	mlx->plane_x = mlx->plane_x * cos(-(mlx->rotSpeed)) - mlx->plane_y * sin(-(mlx->rotSpeed));
	mlx->plane_y = oldplane_x * sin(-(mlx->rotSpeed)) + mlx->plane_y * cos(-(mlx->rotSpeed));
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
