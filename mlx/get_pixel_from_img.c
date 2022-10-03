/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_from_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:15:22 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/03 18:15:36 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	get_pixel_from_img(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8))));
}
