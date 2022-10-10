/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:18:42 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/10 10:45:04 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	final_map_check(char **str, t_error *error, t_map *map)
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
			if (str[i][j] == 'O')
				check_around_space(str, error, i, j);
			if (str[i][j] == 'N' || str[i][j] == 'S'
				|| str[i][j] == 'E' || str[i][j] == 'W')
				error->player++;
			j++;
		}
		i++;
	}
	if (error->player > 1)
		ft_perror_parsing(map, "Multiple player starting postion");
	if (error->player == 0)
		ft_perror_parsing(map, "No player starting postion");
	if (error->map_not_closed == 1)
		ft_perror_parsing(map, "Map is not closed");
}

t_map	*get_map_from_file(char *file, t_map *map)
{
	int		n_lines;
	char	**tmp;

	n_lines = get_number_of_lines(file);
	check_number_of_lines(n_lines);
	map = NULL;
	map = malloc(sizeof(t_map));
	init_map(map);
	tmp = malloc(sizeof(char *) * (n_lines + 1));
	get_file_content(file, tmp);
	get_textures(tmp, map);
	free_dbl_array(tmp);
	map->map = ft_split(map->tmp_map, "\n");
	map->param = ft_split(map->tmp_param, "\n");
	map->param = param_in_order(map->param);
	get_texture_path(map);
	get_color_range(map);
	parse_map(map);
	replace(map->map, 'O', '1');
	return (map);
}

int	get_number_of_lines(char *file)
{
	int		fd;
	int		n_lines;
	char	*line;

	fd = open(file, O_RDONLY);
	n_lines = 0;
	while (get_next_line(fd, &line))
	{
		n_lines++;
		free(line);
	}
	free(line);
	close(fd);
	return (n_lines);
}

void	check_number_of_lines(int n_lines)
{
	if (n_lines < 9)
	{
		printf("Error\nProvide a complete map\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	get_file_content(char *file, char **tmp)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		tmp[i] = ft_strdup(line);
		free(line);
		i++;
	}
	tmp[i] = NULL;
	free (line);
	close(fd);
}
