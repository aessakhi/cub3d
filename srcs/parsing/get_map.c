/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:42:41 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:28 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_map(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	tmp[i] = replace_tab_by_spaces(tmp[i]);
	tex->map = 1;
	if (!tex->no && !tex->so && !tex->we && !tex->ea
		&& !tex->f && !tex->c)
	{
		free_dbl_array(tmp);
		ft_perror_parsing(map, "Wrong order: Map before textures/color ranges");
	}
	map->tmp_map = ft_strjoin_cub3d(map->tmp_map, tmp[i]);
}

void	check_if_empty_line_in_map(char **tmp, t_map *map, int i)
{
	if (!check_end_of_map(tmp, i))
	{
		free_dbl_array(tmp);
		ft_perror_parsing(map, "Empty line in map");
	}
}

int	is_map(char *str)
{
	int		i;
	char	*valid_chars;

	i = 0;
	if (!isins(str, '1'))
		return (0);
	valid_chars = "10NSEW \n\t";
	while (str[i])
	{
		if (!isins(valid_chars, str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_end_of_map(char **tmp, int i)
{
	i++;
	while (tmp[i])
	{
		if (!is_empty_line(tmp[i]))
			return (0);
		i++;
	}
	return (1);
}
