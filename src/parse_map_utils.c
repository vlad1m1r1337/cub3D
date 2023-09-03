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

#include "../includes/cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*ptr;
// 	int		i;
// 	int		len;

// 	len = ft_strlen(s1);
// 	i = 0;
// 	ptr = (char *)malloc(sizeof(char) * len + 1);
// 	if (!ptr)
// 		return (NULL);
// 	while (*s1)
// 		ptr[i++] = *s1++;
// 	ptr[i] = '\0';
// 	return (ptr);
// }