/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:42:36 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:41 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(t_map *map)
{
	if (map->map)
		free_dbl_array(map->map);
	if (map->param)
		free_dbl_array(map->param);
	if (map->tmp_map)
		free(map->tmp_map);
	if (map->tmp_param)
		free(map->tmp_param);
	if (map->path_to_no)
		free(map->path_to_no);
	if (map->path_to_so)
		free(map->path_to_so);
	if (map->path_to_we)
		free(map->path_to_we);
	if (map->path_to_ea)
		free(map->path_to_ea);
	if (map->floor_rgb)
		free(map->floor_rgb);
	if (map->ceiling_rgb)
		free(map->ceiling_rgb);
	if (map)
		free(map);
	map = NULL;
}

void	free_mlx(t_data *data)
{
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img.img)
		mlx_destroy_image(data->mlx_ptr, data->img.img);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	free_texture_img(t_img *img, t_data *data)
{
	if (img->img)
		mlx_destroy_image(data->mlx_ptr, img->img);
}

void	free_textures(t_data *data)
{
	free_texture_img(&data->tex->no, data);
	free_texture_img(&data->tex->so, data);
	free_texture_img(&data->tex->we, data);
	free_texture_img(&data->tex->ea, data);
}

void	free_everything(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->tex)
		free_textures(data);
	if (data->mlx_ptr)
		free_mlx(data);
	exit(EXIT_SUCCESS);
}
