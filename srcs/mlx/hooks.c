/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:05:40 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/06 17:42:14 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_everything(data);
	if (keysym == XK_s)
		move_down(data);
	if (keysym == XK_w)
		move_up(data);
	if (keysym == XK_d)
		move_right(data);
	if (keysym == XK_a)
		move_left(data);
	if (keysym == XK_Right)
		rotate_right(data);
	if (keysym == XK_Left)
		rotate_left(data);
	return (0);
}

int	handle_no_event(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

int	close_win(t_data *data)
{
	free_everything(data);
	exit(EXIT_SUCCESS);
	return (0);
}
