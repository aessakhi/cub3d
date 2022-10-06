/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:32:59 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/06 17:51:51 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_f(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tex->f++;
	if (tex->f != 1 || tex->map != 0)
	{
		printf("Error\n");
		if (tex->f != 1)
			printf("Multiple RGB range for floor\n");
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
	tex->c++;
	if (tex->c != 1 || tex->map != 0)
	{
		printf("Error\n");
		if (tex->c != 1)
			printf("Multiple RGB range for ceiling\n");
		if (tex->map)
			printf("Wrong order: map before texture path");
		free_dbl_array(tmp);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	map->tmp_param = ft_strjoin_cub3d(map->tmp_param, tmp[i]);
}
