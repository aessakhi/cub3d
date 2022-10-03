/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:44:29 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/03 18:52:58 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_tex_check(t_texture_check *tex_check)
{
	tex_check->NO = 0;
	tex_check->SO = 0;
	tex_check->WE = 0;
	tex_check->EA = 0;
	tex_check->F = 0;
	tex_check->C = 0;
	tex_check->map = 0;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->param = NULL;
	map->tmp_param = NULL;
	map->tmp_map = NULL;
	map->path_to_no = NULL;
	map->path_to_so = NULL;
	map->path_to_we = NULL;
	map->path_to_ea = NULL;
	map->ceiling_RGB = NULL;
	map->floor_RGB = NULL;
}

void	init_raycasting(t_ray *ray, t_data *data)
{
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0;
	ray->rot_speed = 0.10;
	ray->move_speed = 0.15;
	get_textures_img(data);
	get_colors(ray, data->map);
	get_initial_player_pos(ray, data->map);
}
