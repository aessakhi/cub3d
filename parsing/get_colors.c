/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:32:59 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/03 19:38:08 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_f(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->F++;
	if (tex->NO != 1 || tex->SO != 1 || tex->WE != 1
		|| tex->EA != 1 || tex->F != 1 || tex->C != 0 || tex->map != 0)
	{
		printf("Error\n");
		if (tex->F != 1)
			printf("Multiple RGB range for floor\n");
		if (tex->NO != 1 || tex->SO != 1
			|| tex->WE != 1 || tex->EA != 1 || tex->C != 0)
			printf("Wrong order\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3d(map->tmp_param, tmp[i]);
}

void	get_c(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->C++;
	if (tex->NO != 1 || tex->SO != 1 || tex->WE != 1
		|| tex->EA != 1 || tex->F != 1 || tex->C != 1 || tex->map != 0)
	{
		printf("Error\n");
		if (tex->C != 1)
			printf("Multiple RGB range for ceiling\n");
		if (tex->NO != 1 || tex->SO != 1
			|| tex->WE != 1 || tex->EA != 1 || tex->F != 1)
			printf("Wrong order\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3d(map->tmp_param, tmp[i]);
}
