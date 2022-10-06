/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:51:42 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:17 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	*get_rgb_values(t_map *map, char **tmp)
{
	int	i;
	int	*rgb;

	i = 0;
	rgb = malloc(sizeof(int) * 3);
	while (tmp[i])
	{
		if (!ft_str_is_digit(tmp[i]))
		{
			free(rgb);
			free_dbl_array(tmp);
			ft_perror_parsing(map, "Invalid RGB format");
		}
		rgb[i] = ft_atoi(tmp[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free(rgb);
			free_dbl_array(tmp);
			ft_perror_parsing(map, "Invalid RGB value");
		}
		i++;
	}
	return (rgb);
}

void	check_color_range(t_map *map, int i)
{
	char	**tmp;
	char	**tmp_range;

	tmp = NULL;
	tmp_range = NULL;
	tmp = ft_split(map->param[i], " \t");
	if (dblarray_size(tmp) != 2)
	{
		free_dbl_array(tmp);
		ft_perror_parsing(map, "Invalid color format");
	}
	tmp_range = ft_split(tmp[1], ",");
	free_dbl_array(tmp);
	if (dblarray_size(tmp_range) != 3)
	{
		free_dbl_array(tmp_range);
		ft_perror_parsing(map, "Invalid color format");
	}
	if (i == 4)
		map->floor_rgb = get_rgb_values(map, tmp_range);
	if (i == 5)
		map->ceiling_rgb = get_rgb_values(map, tmp_range);
	free_dbl_array(tmp_range);
}

void	get_color_range(t_map *map)
{
	check_color_range(map, 4);
	check_color_range(map, 5);
}
