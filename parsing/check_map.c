/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:57:05 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/03 19:28:59 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_map(t_map *map)
{
	int	i;
	int	map_size;
	int	max_line_size;
	t_error error;

	i = 0;
	error.map_not_closed = 0;
	error.player = 0;
	map_size = dblarray_size(map->map);
	max_line_size = get_max_line_size(map->map);
	fill_every_line(map, max_line_size);
	check_first_last_line(map->map[0]);
	check_first_last_line(map->map[map_size - 1]);
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		check_line(map->map, i, &error);
		i++;
	}
	check_left_side(map->map, &error);
	check_right_side(map->map, &error, max_line_size);
	check_top_side(map->map, &error);
	check_bottom_side(map->map, &error);
	replace(map->map, ' ', '0');
	final_map_check(map->map, &error);
	printf("Error player %d\n", error.player);
	if (error.map_not_closed || error.player != 1)
		ft_perror_parsing(map, "Player");
	//Parse des lignes intermédiaires. Premier et dernier caractères doivent être des 1
	//Pareil pour la dernière ligne
}

void	check_first_last_line(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isins("1 ", str[i]))
			printf("Error\n");
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

void	check_line(char	**str, int	i, t_error *error)
{
	//Premier et dernier caractères sont des '1'
	check_first_wall(str, i, error);
	check_last_wall(str, i, error);
	//Check caractère juste en dessous
}
