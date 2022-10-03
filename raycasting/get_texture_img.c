/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:12:13 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/03 19:10:46 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_texture_img(t_img *img, t_data *data, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&img->width, &img->height);
	if (img->img == NULL)
	{
		printf("Error\nEmpty texture file\n");
		free_everything(data);
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	get_textures_img(t_data *data)
{
	data->tex->NO.img = NULL;
	data->tex->SO.img = NULL;
	data->tex->WE.img = NULL;
	data->tex->EA.img = NULL;
	get_texture_img(&data->tex->NO, data, data->map->path_to_no);
	get_texture_img(&data->tex->SO, data, data->map->path_to_so);
	get_texture_img(&data->tex->WE, data, data->map->path_to_we);
	get_texture_img(&data->tex->EA, data, data->map->path_to_ea);
}
