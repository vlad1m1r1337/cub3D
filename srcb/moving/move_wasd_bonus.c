/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:46:20 by vgribkov          #+#    #+#             */
/*   Updated: 2023/09/30 18:15:18 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	moving_forward(t_mlx *mlx)
{
	if (mlx->gg->data->grid[(int)(mlx->pos_x + mlx->dir_x * \
		mlx->move_speed)][(int)(mlx->pos_y)] == '0')
	{
		mlx->pos_x += mlx->dir_x * mlx->move_speed;
	}
	if (mlx->gg->data->grid[(int)(mlx->pos_x)][(int)(mlx->pos_y + \
		mlx->dir_y * mlx->move_speed)] == '0')
	{
		mlx->pos_y += mlx->dir_y * mlx->move_speed;
	}
}

void	moving_back(t_mlx *mlx)
{
	if (mlx->gg->data->grid[(int)(mlx->pos_x - mlx->dir_x * \
		mlx->move_speed)][(int)(mlx->pos_y)] == '0')
	{
		mlx->pos_x -= mlx->dir_x * mlx->move_speed;
	}
	if (mlx->gg->data->grid[(int)(mlx->pos_x)][(int)(mlx->pos_y - \
		mlx->dir_y * mlx->move_speed)] == '0')
	{
		mlx->pos_y -= mlx->dir_y * mlx->move_speed;
	}
}

void	moving_right(t_mlx *mlx)
{
	if (mlx->gg->data->grid[(int)(mlx->pos_x + mlx->dir_y * \
		mlx->move_speed)][(int)(mlx->pos_y)] == '0')
	{
		mlx->pos_x += mlx->dir_y * mlx->move_speed;
	}
	if (mlx->gg->data->grid[(int)(mlx->pos_x)][(int)(mlx->pos_y - \
		mlx->dir_x * mlx->move_speed)] == '0')
	{
		mlx->pos_y -= mlx->dir_x * mlx->move_speed;
	}
}

void	moving_left(t_mlx *mlx)
{
	if (mlx->gg->data->grid[(int)(mlx->pos_x - mlx->dir_y * \
		mlx->move_speed)][(int)(mlx->pos_y)] == '0')
	{
		mlx->pos_x -= mlx->dir_y * mlx->move_speed;
	}
	if (mlx->gg->data->grid[(int)(mlx->pos_x)][(int)(mlx->pos_y + \
		mlx->dir_x * mlx->move_speed)] == '0')
	{
		mlx->pos_y += mlx->dir_x * mlx->move_speed;
	}
}
