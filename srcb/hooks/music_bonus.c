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

void	musik(void)
{
	static int	i = 0;
	int			f;

	if (i == 0)
	{
		f = fork();
		if (!f)
			system("afplay ./srcb/music/skayrim-muzyka-iz-igry.mp3");
		i++;
	}
}
