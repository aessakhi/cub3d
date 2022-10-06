/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:03:07 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:18 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_if_first_line(char **str, t_error *error, int i, int j)
{
	if (j != 0)
	{
		if (!isins("1O", str[i - 1][j - 1]))
		{
			printf("Error here LINE = %s LINE NUMBER %d\n", str[i], i);
			error->map_not_closed = 1;
		}
	}
	if (str[i][j + 1])
	{
		if (!isins("1O", str[i - 1][j + 1]))
		{
			printf("Error here LINE = %s LINE NUMBER %d\n", str[i], i);
			error->map_not_closed = 1;
		}
	}
	if (!isins("1O", str[i - 1][j]))
	{
		printf("Error here LINE = %s LINE NUMBER %d\n", str[i], i);
		error->map_not_closed = 1;
	}
}

void	check_if_line_after(char **str, t_error *error, int i, int j)
{
	if (j != 0)
	{
		if (!isins("1O", str[i + 1][j - 1]))
		{
			printf("Error here LINE = %s LINE NUMBER %d\n", str[i], i);
			error->map_not_closed = 1;
		}
	}
	if (str[i][j + 1])
	{
		if (!isins("1O", str[i + 1][j + 1]))
		{
			printf("Error here LINE = %s LINE NUMBER %d\n", str[i], i);
			error->map_not_closed = 1;
		}
	}
	if (!isins("1O", str[i + 1][j]))
	{
		printf("Error here LINE = %s LINE NUMBER %d\n", str[i], i);
		error->map_not_closed = 1;
	}
}

void	check_around_space(char **str, t_error *error, int i, int j)
{
	if (i != 0)
		check_if_first_line(str, error, i, j);
	if (str[i + 1])
		check_if_line_after(str, error, i, j);
	if (j != 0)
	{
		if (!isins("1O", str[i][j - 1]))
		{
			printf("Error here LINE = %s LINE NUMBER %d\n", str[i], i);
			error->map_not_closed = 1;
		}
	}
	if (str[i][j + 1])
	{
		if (!isins("1O", str[i][j + 1]))
		{
			printf("Error here LINE = %s LINE NUMBER %d\n", str[i], i);
			error->map_not_closed = 1;
		}
	}
}
