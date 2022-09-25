/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:28:38 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/15 17:48:35 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_textures(char **tmp, t_map *map)
{
	int	i;
	char	**textures;
	t_texture_check	tex;

	i = 0;
	init_tex_check(&tex);
	while (tmp[i])
	{
		get_textures_2(&tex, tmp, map, i);
		i++;
	}
	if (!tex.NO || !tex.SO || !tex.WE || !tex.EA || !tex.F || !tex.C || !tex.map)
		ft_perror_parsing(map, "Map missing an element");
}

void	get_textures_2(t_texture_check *tex, char **tmp, t_map *map, int i)
{
	if (!is_map(tmp[i]))
		tmp[i] = ft_strtrim(tmp[i], " \t");
	if (ft_strcmp(tmp[i], "NO ") || ft_strcmp(tmp[i], "NO\t"))
		get_NO(tex, tmp, map, i);
	else if (ft_strcmp(tmp[i], "SO") || ft_strcmp(tmp[i], "SO\t"))
		get_SO(tex, tmp, map, i);
	else if (ft_strcmp(tmp[i], "WE") || ft_strcmp(tmp[i], "WE\t"))
		get_WE(tex, tmp, map, i);
	else if (ft_strcmp(tmp[i], "EA") || ft_strcmp(tmp[i], "EA\t"))
		get_EA(tex, tmp, map, i);
	else if (ft_strcmp(tmp[i], "F") || ft_strcmp(tmp[i], "F\t"))
		get_F(tex, tmp, map, i);
	else if (ft_strcmp(tmp[i], "C") || ft_strcmp(tmp[i], "C\t"))
		get_C(tex, tmp, map, i);
	else if (is_map(tmp[i]))
		get_map(tex, tmp, map, i);
	else if (is_empty_line(tmp[i]) && tex->map == 1)
		check_if_empty_line_in_map(tex, tmp, map, i);
	else if (!is_empty_line(tmp[i]))
	{
		free_dbl_array(tmp);
		ft_perror_parsing(map, "Invalid element in map");
	}
}

int	is_empty_line(char *str)
{
	int		i;
	char	*valid_chars;

	i = 0;
	valid_chars = " \n\t";
	while (str[i])
	{
		if (!isins(valid_chars, str[i]))
			return (0);
		i++;
	}
	return (1);
}
