/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:57:05 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:24 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_map(t_map *map)
{
	int		i;
	int		map_size;
	int		max_line_size;
	t_error	error;

	i = 0;
	error.map_not_closed = 0;
	error.player = 0;
	map_size = dblarray_size(map->map);
	if (map_size < 3)
		ft_perror_parsing(map, "Not a map (3 lines minimum)");
	max_line_size = get_max_line_size(map->map);
	fill_every_line(map, max_line_size);
	check_first_last_line(map->map[0], map);
	check_first_last_line(map->map[map_size - 1], map);
	while (map->map[i])
	{
		check_line(map->map, i, &error);
		i++;
	}
	check_map_sides(map->map, &error, max_line_size);
	replace(map->map, ' ', '0');
	final_map_check(map->map, &error, map);
}

void	check_first_last_line(char	*str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isins("1 ", str[i]))
			ft_perror_parsing(map, "Map is not closed");
		i++;
	}
}

void	check_first_wall(char **str, int i, t_error *error)
{
	int	j;

	j = 0;
	while (str[i][j] == ' ' && str[i][j])
	{
		if (i > 0)
			if (str[i - 1][j] != ' ' && str[i - 1][j] != '1')
				error->map_not_closed = 1;
		if (i < dblarray_size(str) - 1)
			if (str[i + 1][j] != ' ' && str[i + 1][j] != '1')
				error->map_not_closed = 1;
		j++;
	}
	if (str[i][j] != '1')
		error->map_not_closed = 1;
	if (str[i + 1])
		if (str[i + 1][j])
			if (str[i + 1][j] != ' ' && str[i + 1][j] != '1')
				error->map_not_closed = 1;
}

void	check_last_wall(char **str, int i, t_error *error)
{
	int	j;

	j = ft_strlen(str[i]) - 1;
	while (str[i][j] == ' ' && str[i][j])
	{
		if (i > 0)
			if (str[i - 1][j] != ' ' && str[i - 1][j] != '1')
				error->map_not_closed = 1;
		if (i < dblarray_size(str) - 1)
			if (str[i + 1][j] != ' ' && str[i + 1][j] != '1')
				error->map_not_closed = 1;
		j--;
	}
	if (str[i][j] != '1')
		error->map_not_closed = 1;
	if (str[i + 1])
		if (str[i + 1][j])
			if (str[i + 1][j] != ' ' && str[i + 1][j] != '1')
				error->map_not_closed = 1;
}

void	check_line(char **str, int i, t_error *error)
{
	check_first_wall(str, i, error);
	check_last_wall(str, i, error);
}
