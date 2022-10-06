/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:27:01 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/06 17:51:20 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_no(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->no++;
	if (tex->no != 1 || tex->map != 0)
	{
		printf("Error\n");
		if (tex->no != 1)
			printf("Multiple paths to north texture\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3d(map->tmp_param, tmp[i]);
}

void	get_so(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->so++;
	if (tex->so != 1 || tex->map != 0)
	{
		printf("Error\n");
		if (tex->so != 1)
			printf("Multiple paths to south texture\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3d(map->tmp_param, tmp[i]);
}

void	get_we(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->we++;
	if (tex->we != 1 || tex->map != 0)
	{
		if (tex->we != 1)
			printf("Multiple paths to west texture\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3d(map->tmp_param, tmp[i]);
}

void	get_ea(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->ea++;
	if (tex->ea != 1 || tex->map != 0)
	{
		if (tex->ea != 1)
			printf("Multiple paths to east texture\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3d(map->tmp_param, tmp[i]);
}
