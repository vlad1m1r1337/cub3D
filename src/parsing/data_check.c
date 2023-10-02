/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:11 by jfrances          #+#    #+#             */
/*   Updated: 2023/10/02 16:12:23 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	fc_data(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && \
		(str[i] == ',') && (str[i] == ' '))
			return (-1);
		i++;
	}
	return (0);
}

int	fc_garbage(char *floor, char *ceil)
{
	int	i;
	int	cntf;
	int	cntc;

	i = 0;
	cntf = 0;
	cntc = 0;
	while (floor[i])
	{
		if (floor[i] == ',')
			cntf++;
		i++;
	}
	i = 0;
	while (ceil[i])
	{
		if (ceil[i] == ',')
			cntc++;
		i++;
	}
	if (cntc > 2 || cntf > 2)
		return (-1);
	if (fc_data(ceil) == -1 || fc_data(floor) == -1)
		return (-1);
	return (0);
}
