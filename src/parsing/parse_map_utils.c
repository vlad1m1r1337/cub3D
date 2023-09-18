/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:18 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/10 14:22:59 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	trim_spaces(char **arr)
{
	int		i;
	char	*save;

	i = 0;
	while (arr[i] != NULL)
	{
		save = arr[i];
		arr[i] = ft_strtrim(arr[i], " ");
		free(save);
		i++;
	}
}

void	space_skip(char **str)
{
	while (**str == ' ')
		(*str)++;
}

void	dup_grid(char **src, char **dest)
{
	int	i;

	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
}

void	free_grid(char **free_me)
{
	int	i;

	i = 0;
	while (free_me[i] != NULL)
	{
		free(free_me[i]);
		i++;
	}
	free(free_me);
}
