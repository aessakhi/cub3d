/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:04:16 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:37 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	choose_wall_side(t_ray *ray, t_data *data)
{
	if (ray->side == 0 && ray->raydir_x < 0)
		draw_wall(ray, data->tex, &data->tex->ea, data);
	if (ray->side == 0 && ray->raydir_x >= 0)
		draw_wall(ray, data->tex, &data->tex->we, data);
	if (ray->side == 1 && ray->raydir_y >= 0)
		draw_wall(ray, data->tex, &data->tex->no, data);
	if (ray->side == 1 && ray->raydir_y < 0)
		draw_wall(ray, data->tex, &data->tex->so, data);
}

void	launch_rays(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ray->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ray->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ray->pos_y) * (ray->deltadist_y);
	}
}

void	increment_rays(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - ray->pos_x
				+ (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - ray->pos_y
				+ (1 - ray->step_y) / 2) / ray->raydir_y;
}

void	init_rays(t_ray *ray)
{
	ray->camera_x = 2 * ray->x / (double)(ray->screen_x) - 1;
	ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)(ray->pos_x);
	ray->map_y = (int)(ray->pos_y);
	ray->deltadist_x = sqrt(1 + ((ray->raydir_y * ray->raydir_y)
				/ (ray->raydir_x * ray->raydir_x)));
	ray->deltadist_y = sqrt(1 + ((ray->raydir_x * ray->raydir_x)
				/ (ray->raydir_y * ray->raydir_y)));
	ray->hit = 0;
}

void	start_raycasting(t_ray *ray, t_data *data)
{
	ray->x = 0;
	while (ray->x < ray->screen_x)
	{
		init_rays(ray);
		launch_rays(ray);
		increment_rays(ray, data);
		ray->line_height = (int)(ray->screen_y / ray->perpwalldist);
		ray->drawstart = -ray->line_height / 2 + ray->screen_y / 2;
		if (ray->drawstart < 0)
			ray->drawstart = 0;
		ray->drawend = ray->line_height / 2 + ray->screen_y / 2;
		if (ray->drawend >= ray->screen_y)
			ray->drawend = ray->screen_y - 1;
		draw_ceiling(ray, data);
		draw_floor(ray, data);
		choose_wall_side(ray, data);
		ray->x++;
	}
}
