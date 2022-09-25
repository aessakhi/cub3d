/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:50:43 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/15 17:51:08 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_texture_path(t_map *map, int i)
{
	char	**tmp;
	int		fd;

	tmp = NULL;
	tmp = ft_split(map->param[i], " \t");
	if (dblarray_size(tmp) != 2)
	{
		free_dbl_array(tmp);
		ft_perror_parsing(map, "Invalid path to texture");
	}
/* 	fd = open(tmp[1], O_RDONLY);
	if (fd == -1)
	{
		ft_perror_parsing(map, "No such file or directory");
	} */
	//Check if XPM?
	if (i == 0)
		map->path_to_no = ft_strdup(tmp[1]);
	if (i == 1)
		map->path_to_so = ft_strdup(tmp[1]);
	if (i == 2)
		map->path_to_we = ft_strdup(tmp[1]);
	if (i == 3)
		map->path_to_ea = ft_strdup(tmp[1]);
	free_dbl_array(tmp);
	/* close(fd); */
}

void	get_texture_path(t_map *map)
{
	int		i;

	i = 0;
	print_dbl_array(map->param);
	while (map->param[i] && i < 4)
	{
		check_texture_path(map, i);
		i++;
	}
}
