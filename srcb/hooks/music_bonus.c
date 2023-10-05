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

void	sighandler(int sig)
{
	if (sig != SIGKILL)
		return ;
	exit (0);
}

//void	game_no_exit(t_game *game, t_map *map, char *pstr)
//{
//	if (map)
//		free_map_data(map, 2);
//	if (game->fd != 0)
//		close(game->fd);
//	ft_putstr_fd(pstr, 1);
//}

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
