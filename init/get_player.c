/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:17:18 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/02 17:18:34 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_orientation(t_ray *ray, char c)
{
	if (c == 'N')
	{
		ray->dir_y = -1;
		ray->plane_x = 0.66;
	}
	if (c == 'S')
	{
		ray->dir_y = 1;
		ray->plane_x = -0.66;
	}
	if (c == 'W')
	{
		ray->dir_x = -1;
		ray->plane_y = -0.66;
	}
	if (c == 'E')
	{
		ray->dir_x = 1;
		ray->plane_y = 0.66;
	}
}

void	get_initial_player_pos(t_ray *ray, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
			|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				printf("Player found at X = %d, Y = %d\n", j, i);
				ray->pos_x = (double)j + 0.5;
				ray->pos_y = (double)i + 0.5;
				get_orientation(ray, map->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}
