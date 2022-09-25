/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:59:32 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/15 18:00:33 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	replace(char **str, char to_replace, char replaced)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == to_replace)
				str[i][j] = replaced;
			j++;
		}
		i++;
	}
}

void	fill_every_line(t_map *map, int line_size)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) < line_size)
			map->map[i] = append_spaces(map->map[i], line_size - ft_strlen(map->map[i]));
		i++;
	}
}

char	*append_spaces(char *str, int n_of_spaces)
{
	char	*tmp;
	char	*spaces;
	int		i;

	i = 0;
	tmp = NULL;
	spaces = NULL;
	spaces = malloc(sizeof(char) * (n_of_spaces + 1));
	while (i < n_of_spaces)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[i] = '\0';
	tmp = ft_strjoin_2(str, spaces);
	free (str);
	return (tmp);
}
