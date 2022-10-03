/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:11:48 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/03 18:49:44 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_wall(t_ray *ray, t_tex *tex, t_img *img, t_data *data)
{
	int	cpy_drawstart;

	cpy_drawstart = ray->drawstart;
	if (ray->side == 0)
		tex->wall_x = ray->pos_y + ray->perpwalldist * ray->raydir_y;
	else
		tex->wall_x = ray->pos_x + ray->perpwalldist * ray->raydir_x;
	tex->wall_x -= floor((tex->wall_x));
	tex->x = (int)(tex->wall_x * (double)(img->width));
	tex->step = 1.0 * img->height / ray->line_height;
	tex->pos = (ray->drawstart - ray->screen_y / 2 + ray->line_height / 2)
		* tex->step;
	while (cpy_drawstart < ray->drawend)
	{
		tex->y = (int)tex->pos;
		tex->pos += tex->step;
		my_mlx_pixel_put(&data->img, ray->x, cpy_drawstart,
			get_pixel_from_img(img, tex->x, tex->y));
		cpy_drawstart++;
	}
}

void	draw_floor(t_ray *ray, t_data *data)
{
	int	y;

	y = ray->drawend;
	while (y < ray->screen_y)
	{
		my_mlx_pixel_put(&data->img, ray->x, y, ray->floor_color);
		y++;
	}
}

void	draw_ceiling(t_ray *ray, t_data *data)
{
	int	y;

	y = 0;
	while (y < ray->drawstart)
	{
		my_mlx_pixel_put(&data->img, ray->x, y, ray->ceiling_color);
		y++;
	}
}
