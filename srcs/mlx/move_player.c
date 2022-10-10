/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:09:15 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/10 10:01:39 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_up(t_data *data)
{
	if (data->map->map[(int)(data->ray.pos_y)][(int)(data->ray.pos_x
		+ data->ray.dir_x * data->ray.move_speed)] != '1')
		data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
	if (data->map->map[(int)(data->ray.pos_y + data->ray.dir_y
			* data->ray.move_speed)][(int)(data->ray.pos_x)] != '1')
		data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
	render_new_image(data);
}

void	move_down(t_data *data)
{
	if (data->map->map[(int)(data->ray.pos_y)][(int)(data->ray.pos_x
		- data->ray.dir_x * data->ray.move_speed)] != '1')
		data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
	if (data->map->map[(int)(data->ray.pos_y - data->ray.dir_y
			* data->ray.move_speed)][(int)(data->ray.pos_x)] != '1')
		data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
	render_new_image(data);
}

void	move_left(t_data *data)
{
	if (data->map->map[(int)(data->ray.pos_y)][(int)(data->ray.pos_x
		+ data->ray.dir_y * data->ray.move_speed)] != '1')
		data->ray.pos_x += data->ray.dir_y * data->ray.move_speed;
	if (data->map->map[(int)(data->ray.pos_y - data->ray.dir_x
			* data->ray.move_speed)][(int)(data->ray.pos_x)] != '1')
		data->ray.pos_y -= data->ray.dir_x * data->ray.move_speed;
	render_new_image(data);
}

void	move_right(t_data *data)
{
	if (data->map->map[(int)(data->ray.pos_y)][(int)(data->ray.pos_x
		- data->ray.dir_y * data->ray.move_speed)] != '1')
		data->ray.pos_x -= data->ray.dir_y * data->ray.move_speed;
	if (data->map->map[(int)(data->ray.pos_y + data->ray.dir_x
			* data->ray.move_speed)][(int)(data->ray.pos_x)] != '1')
		data->ray.pos_y += data->ray.dir_x * data->ray.move_speed;
	render_new_image(data);
}
