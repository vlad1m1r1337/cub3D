/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:40:11 by jfrances          #+#    #+#             */
/*   Updated: 2023/09/19 17:40:13 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void conditionals(t_map *map, int i, int j, char c) 
{
    if (c == ' ')
        map->int_grid[i][j] = -1;
    else if (c == 'N')
        map->int_grid[i][j] = 2;
    else if (c == 'S')
        map->int_grid[i][j] = 3;
    else if (c == 'E')
        map->int_grid[i][j] = 4;
    else if (c == 'W')
        map->int_grid[i][j] = 5;
    else if (c == '0')
        map->int_grid[i][j] = 0;
    else if (c == '1')
        map->int_grid[i][j] = 1;
}

void copy_grid(t_map *map, int i, int j) 
{
    while (map->grid[++i]) 
	{
        j = -1;
        while (map->grid[i][++j])
            conditionals(map, i, j, map->grid[i][j]);
    }
}

void create_int_array(t_game *game, t_map *map) 
{
    int i;

    i = -1;
    map->int_grid = (int **)malloc(sizeof(int *) * (map->size + 1));
    if (!map->int_grid)
        exit(1); // Replace with your error handling
    map->int_grid[map->size] = NULL;
    while (map->grid[++i][0] != SENTINEL) 
	{
        map->int_grid[i] = (int *)malloc(sizeof(int) * (ft_strlen(map->grid[i]) + 1));
        if (!map->int_grid[i])
            exit(1); // Replace with your error handling
    }
    copy_grid(map, -1, -1);
	game->data = map;
}

void print_int_array(t_map *map) 
{
    int i, j;
    for (i = 0; map->int_grid[i]; i++) 
	{
        for (j = 0; map->int_grid[i][j] != -1; j++) 
		{
            printf("%d ", map->int_grid[i][j]);
        }
        printf("\n");
    }
}
