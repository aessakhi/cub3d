/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_direction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:56:00 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:20 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_downwards(char **str, t_error *error, int i, int j)
{
	if (!str[i + 1])
		return ;
	i++;
	while (str[i][j] != '1' && str[i][j])
	{
		if (str[i][j] != ' ' && str[i][j] != '1' && str[i][j] != 'O')
			error->map_not_closed = 1;
		if (str[i][j] == ' ')
		{
			str[i][j] = 'O';
			check_left(str, error, i, j);
			check_right(str, error, i, j);
		}
		if (!str[i + 1])
			return ;
		i++;
	}
}

void	check_upwards(char **str, t_error *error, int i, int j)
{
	if (i == 0)
		return ;
	i--;
	while (str[i][j] != '1' && str[i][j])
	{
		if (str[i][j] != ' ' && str[i][j] != '1' && str[i][j] != 'O')
			error->map_not_closed = 1;
		if (str[i][j] == ' ')
		{
			str[i][j] = 'O';
			check_left(str, error, i, j);
			check_right(str, error, i, j);
		}
		if (i == 0)
			return ;
		i--;
	}
}

void	check_left(char **str, t_error *error, int i, int j)
{
	if (j == 0)
		return ;
	j--;
	while (str[i][j] != '1' && str[i][j])
	{
		if (str[i][j] != ' ' && str[i][j] != '1' && str[i][j] != 'O')
			error->map_not_closed = 1;
		if (str[i][j] == ' ')
		{
			str[i][j] = 'O';
			check_upwards(str, error, i, j);
			check_downwards(str, error, i, j);
		}
		if (j == 0)
			return ;
		j--;
	}
}

void	check_right(char **str, t_error *error, int i, int j)
{
	if (!str[i][j + 1])
		return ;
	j++;
	while (str[i][j] != '1' && str[i][j])
	{
		if (str[i][j] != ' ' && str[i][j] != '1' && str[i][j] != 'O')
			error->map_not_closed = 1;
		if (str[i][j] == ' ')
		{
			str[i][j] = 'O';
			check_upwards(str, error, i, j);
			check_downwards(str, error, i, j);
		}
		j++;
	}
}
