/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:42:36 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/15 18:28:29 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	if (map->floor_RGB)
		free(map->floor_RGB);
	if (map->ceiling_RGB)
		free(map->ceiling_RGB);
	if (map)
		free(map);
	map = NULL;
}
