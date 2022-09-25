/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:51:42 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/25 15:12:19 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	*get_RGB_values(t_map *map, char **tmp)
{
	int	i;
	int	*RGB;

	i = 0;
	RGB = malloc(sizeof(int) * 3);
	while (tmp[i])
	{
		RGB[i] = ft_atoi(tmp[i]);
		//NE PAS OUBLIER DE CHECK SI CE SONT TOUS DES DIGITS
		if (RGB[i] < 0 || RGB[i] > 255)
		{
			free(RGB);
			free_dbl_array(tmp);
			ft_perror_parsing(map, "Invalid RGB value");
		}
		i++;
	}
	return (RGB);
}

void	check_color_range(t_map *map, int i)
{
	char	**tmp;
	char	**tmp_range;
	//Besoin de check si il y a bien 2 elements
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
	//Besoin de check si il y a 3 couleurs
	if (i == 4)
		map->floor_RGB = get_RGB_values(map, tmp_range);
	if (i == 5)
		map->ceiling_RGB = get_RGB_values(map, tmp_range);
	free_dbl_array(tmp_range);
	//Besoin de check si les couleurs sont comprises entre 0 et 255
}

void	get_color_range(t_map *map)
{
	check_color_range(map, 4);
	check_color_range(map, 5);
}
