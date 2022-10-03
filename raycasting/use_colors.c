/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:14:41 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/02 17:15:07 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	convert_rgb(int	*rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]));
}

void	get_colors(t_ray *ray, t_map *map)
{
	ray->floor_color = convert_rgb(map->floor_RGB);
	ray->ceiling_color = convert_rgb(map->ceiling_RGB);
}
