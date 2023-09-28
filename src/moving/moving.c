/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:50:35 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/28 13:48:35 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	moving_forward(t_mlx *mlx)
{
	if(mlx->worldMap[(int)(mlx->pos_x + mlx->dir_x * mlx->moveSpeed)][(int)(mlx->pos_y)] == '0')
		mlx->pos_x += mlx->dir_x * mlx->moveSpeed;
	if(mlx->worldMap[(int)(mlx->pos_x)][(int)(mlx->pos_y + mlx->dir_y * mlx->moveSpeed)] == '0')
		mlx->pos_y += mlx->dir_y * mlx->moveSpeed;
}

void	moving_back(t_mlx *mlx)
{
	if(mlx->worldMap[(int)(mlx->pos_x - mlx->dir_x * mlx->moveSpeed)][(int)(mlx->pos_y)] == '0')
		mlx->pos_x -= mlx->dir_x * mlx->moveSpeed;
    if(mlx->worldMap[(int)(mlx->pos_x)][(int)(mlx->pos_y - mlx->dir_y * mlx->moveSpeed)] == '0')
		mlx->pos_y -= mlx->dir_y * mlx->moveSpeed;
}

void	moving_right(t_mlx *mlx)
{
	if(mlx->worldMap[(int)(mlx->pos_x + mlx->dir_y * mlx->moveSpeed)][(int)(mlx->pos_y)] == '0')
		mlx->pos_x += mlx->dir_y * mlx->moveSpeed;
	if(mlx->worldMap[(int)(mlx->pos_x)][(int)(mlx->pos_y - mlx->dir_x * mlx->moveSpeed)] == '0')
		mlx->pos_y -= mlx->dir_x * mlx->moveSpeed;
}

void moving_left(t_mlx *mlx)
{
	if(mlx->worldMap[(int)(mlx->pos_x - mlx->dir_y * mlx->moveSpeed)][(int)(mlx->pos_y)] == '0')
		mlx->pos_x -= mlx->dir_y * mlx->moveSpeed;
	if(mlx->worldMap[(int)(mlx->pos_x)][(int)(mlx->pos_y + mlx->dir_x * mlx->moveSpeed)] == '0')
		mlx->pos_y += mlx->dir_x * mlx->moveSpeed;
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
