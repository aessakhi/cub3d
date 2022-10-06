/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:50:43 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/06 17:53:55 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_file_is_xpm(char	**tmp, char *ext, t_map *map)
{
	int	i;
	int	j;

	i = ft_strlen(tmp[1]) - 4;
	j = 0;
	while (tmp[1][i])
	{
		if (tmp[1][i] != ext[j])
		{
			free_dbl_array(tmp);
			ft_perror_parsing(map, "Texture file is not a .xpm file");
		}
		i++;
		j++;
	}
	return (1);
}

void	check_texture_file(char **tmp, t_map *map)
{
	int	fd;

	fd = open(tmp[1], O_RDWR);
	if (fd == -1)
	{
		free_dbl_array(tmp);
		if (errno == EISDIR)
			ft_perror_parsing(map, "Texture file is a directory");
		ft_perror_parsing(map, "No such file or directory");
	}
	close(fd);
}

void	check_texture_path(t_map *map, int i)
{
	char	**tmp;

	tmp = NULL;
	tmp = ft_split(map->param[i], " \t");
	if (dblarray_size(tmp) != 2)
	{
		free_dbl_array(tmp);
		ft_perror_parsing(map, "Multiple texture paths");
	}
	check_texture_file(tmp, map);
	check_file_is_xpm(tmp, ".xpm", map);
	if (i == 0)
		map->path_to_no = ft_strdup(tmp[1]);
	if (i == 1)
		map->path_to_so = ft_strdup(tmp[1]);
	if (i == 2)
		map->path_to_we = ft_strdup(tmp[1]);
	if (i == 3)
		map->path_to_ea = ft_strdup(tmp[1]);
	free_dbl_array(tmp);
}

void	get_texture_path(t_map *map)
{
	int		i;

	i = 0;
	while (map->param[i] && i < 4)
	{
		check_texture_path(map, i);
		i++;
	}
}
