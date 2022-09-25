/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:04:16 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/25 15:10:32 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start_raycasting(t_ray *ray, t_data *data)
{
	int	color;

	color = 100000; //JUSTE POUR TEST, SERA CHANGEE PAR LA SUITE
	//Ne pas oublier de changer les valeurs pos_x pos_y dir_x dir_y plane_x plane_y en fonction de l'orientation du joueur
	ray->dir_x = 0;
	ray->dir_y = -1;
	ray->plane_x = 0.66;
	ray->plane_y = 0;
	ray->x = 0;
	while (ray->x <= ray->screen_x)
	{
		color = 100000;
		ray->camera_x = 2 * ray->x / (double)(ray->screen_x) - 1;
		ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
		ray->map_x = (int)(ray->pos_x);
		ray->map_y = (int)(ray->pos_y);
		ray->deltadist_x = sqrt(1 + ((ray->raydir_y * ray->raydir_y) / (ray->raydir_x * ray->raydir_y)));
		ray->deltadist_y = sqrt(1 + ((ray->raydir_x * ray->raydir_x) / (ray->raydir_y * ray->raydir_y)));
		ray->hit = 0;
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
		while (ray->hit == 0)
		{
			if (ray->sidedist_x < ray->sidedist_y)
			{
				ray->sidedist_x +=ray->deltadist_x;
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
			ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
		else
			ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
		ray->line_height = (int)(ray->screen_y / ray->perpwalldist);
		ray->drawstart = -ray->line_height / 2 + ray->screen_y / 2;
		if (ray->drawstart < 0)
			ray->drawstart = 0;
		ray->drawend = ray->line_height / 2 + ray->screen_y / 2;
		if (ray->drawend >= ray->screen_y)
			ray->drawend = ray->screen_y - 1;
		if (ray->side == 1)
			color = color / 2;
		int	cpy_drawstart = ray->drawstart;
		int	cpy_drawend = ray->drawend;
		while (cpy_drawstart < ray->drawend)
		{
			my_mlx_pixel_put(&data->img, ray->x, cpy_drawstart, color);
			cpy_drawstart++;
		}
		ray->x++;
	}
}

void	render(t_data data)
{
	data.assets = NULL;
	// AJOUTER LA FONCTION POUR RECUPERER LES TEXTURES DES DIFFERENTS MURS ICI;
	data.img.img = mlx_new_image(data.mlx_ptr, data.ray.screen_x, data.ray.screen_y);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	start_raycasting(&data.ray, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img, 0, 0);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, ClientMessage,
		StructureNotifyMask, &close_win, &data);
	mlx_loop(data.mlx_ptr);
}
