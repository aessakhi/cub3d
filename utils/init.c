/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:44:29 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/25 16:25:45 by aessakhi         ###   ########.fr       */
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

void	init_raycasting(t_ray *ray)
{
	ray->pos_x = 0;
	ray->pos_y = 0;
	ray->dir_x = 0;
	ray->dir_y = -1;
	ray->plane_x = 0.66;
	ray->plane_y = 0;
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->camera_x = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perpwalldist = 0;
	ray->line_height = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->x = 0;
	ray->screen_x = 0;
	ray->screen_y = 0;
	ray->rot_speed = 0.033;
	ray->move_speed = 0.10;
}
