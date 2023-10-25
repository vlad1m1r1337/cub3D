/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:56:45 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/30 18:13:52 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	musik(t_mlx *mlx)
{
	static int	i = 0;

	if (i == 0)
	{
		mlx->f = fork();
		if (!mlx->f)
		{
			while (1)
				system("exec afplay ./srcb/music/skayrim-muzyka-iz-igry.mp3");
		}
		i++;
	}
}
