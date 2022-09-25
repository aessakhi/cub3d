/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:13:19 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/15 17:52:45 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_dbl_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

void	print_dbl_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	return ;
}

int	dblarray_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	get_max_line_size(char	**array)
{
	int	i;
	int	line_size;

	i = 0;
	line_size = 0;
	while (array[i])
	{
		if (ft_strlen(array[i]) > line_size)
			line_size = ft_strlen(array[i]);
		i++;
	}
	return (line_size);
}
