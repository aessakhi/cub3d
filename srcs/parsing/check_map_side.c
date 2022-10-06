/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_side.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:53:29 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:22 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_left_side(char **str, t_error *error)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] == ' ')
		{
			str[i][j] = 'O';
			check_right(str, error, i, j);
		}
		if (!str[i + 1])
			return ;
		i++;
	}
}

void	check_right_side(char **str, t_error *error, int max_size)
{
	int	i;
	int	j;

	i = 0;
	j = max_size - 1;
	while (str[i][j])
	{
		if (str[i][j] == ' ')
		{
			str[i][j] = 'O';
			check_left(str, error, i, j);
		}
		if (!str[i + 1])
			return ;
		i++;
	}
}

void	check_bottom_side(char **str, t_error *error)
{
	int	i;
	int	j;

	i = dblarray_size(str) - 1;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] == ' ')
		{
			str[i][j] = 'O';
			check_upwards(str, error, i, j);
		}
		j++;
	}
}

void	check_top_side(char **str, t_error *error)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] == ' ')
		{
			str[i][j] = 'O';
			check_downwards(str, error, i, j);
		}
		j++;
	}
}

void	check_map_sides(char **str, t_error *error, int max_line_size)
{
	check_left_side(str, error);
	check_right_side(str, error, max_line_size);
	check_top_side(str, error);
	check_bottom_side(str, error);
}
