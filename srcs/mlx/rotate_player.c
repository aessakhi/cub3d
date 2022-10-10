/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:01:14 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/10 10:01:41 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_left(t_data *data)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = data->ray.dir_x;
	oldplane_x = data->ray.plane_x;
	data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rot_speed)
		- data->ray.dir_y * sin(-data->ray.rot_speed);
	data->ray.dir_y = olddir_x * sin(-data->ray.rot_speed)
		+ data->ray.dir_y * cos(-data->ray.rot_speed);
	data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rot_speed)
		- data->ray.plane_y * sin(-data->ray.rot_speed);
	data->ray.plane_y = oldplane_x * sin(-data->ray.rot_speed)
		+ data->ray.plane_y * cos(-data->ray.rot_speed);
	render_new_image(data);
}

void	rotate_right(t_data *data)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = data->ray.dir_x;
	oldplane_x = data->ray.plane_x;
	data->ray.dir_x = data->ray.dir_x * cos(data->ray.rot_speed)
		- data->ray.dir_y * sin(data->ray.rot_speed);
	data->ray.dir_y = olddir_x * sin(data->ray.rot_speed)
		+ data->ray.dir_y * cos(data->ray.rot_speed);
	data->ray.plane_x = data->ray.plane_x * cos(data->ray.rot_speed)
		- data->ray.plane_y * sin(data->ray.rot_speed);
	data->ray.plane_y = oldplane_x * sin(data->ray.rot_speed)
		+ data->ray.plane_y * cos(data->ray.rot_speed);
	render_new_image(data);
}
