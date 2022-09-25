/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:27:01 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/15 17:48:56 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_NO(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->NO++;
	if (tex->NO != 1 || tex->SO != 0 || tex->WE != 0 || tex->EA != 0 || tex->F != 0 || tex->C != 0 || tex->map != 0)
	{
		printf("Error\n");
		if (tex->NO != 1)
			printf("Multiple paths to north texture\n");
		if (tex->SO != 0 || tex->WE != 0 || tex->EA != 0 || tex->F != 0 || tex->C != 0)
			printf("Wrong order\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3D(map->tmp_param, tmp[i]);
}

void	get_SO(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->SO++;
	if (tex->NO != 1 || tex->SO != 1 || tex->WE != 0 || tex->EA != 0 || tex->F != 0 || tex->C != 0 || tex->map != 0)
	{
		printf("Error\n");
		if (tex->SO != 1)
			printf("Multiple paths to south texture\n");
		if (tex->NO != 1 || tex->WE != 0 || tex->EA != 0 || tex->F != 0 || tex->C != 0)
			printf("Wrong order\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3D(map->tmp_param, tmp[i]);
}

void	get_WE(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->WE++;
	if (tex->NO != 1 || tex->SO != 1 || tex->WE != 1 || tex->EA != 0 || tex->F != 0 || tex->C != 0 || tex->map != 0)
	{
		if (tex->WE != 1)
			printf("Multiple paths to west texture\n");
		if (tex->NO != 1 || tex->SO != 1 || tex->WE != 0 || tex->EA != 0 || tex->F != 0 || tex->C != 0)
			printf("Wrong order\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3D(map->tmp_param, tmp[i]);
}

void	get_EA(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->EA++;
	if (tex->NO != 1 || tex->SO != 1 || tex->WE != 1 || tex->EA != 1 || tex->F != 0 || tex->C != 0 || tex->map != 0)
	{
		if (tex->EA != 1)
			printf("Multiple paths to east texture\n");
		if (tex->NO != 1 || tex->SO != 1 || tex->WE != 1 || tex->F != 0 || tex->C != 0)
			printf("Wrong order\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3D(map->tmp_param, tmp[i]);
}
