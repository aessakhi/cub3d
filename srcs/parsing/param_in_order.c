/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_in_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:44:47 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/10 10:45:06 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**param_in_order(char **param)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof(char *) * (dblarray_size(param) + 1));
	while (param[i])
	{
		if (ft_strcmp(param[i], "NO ") || ft_strcmp(param[i], "NO\t"))
			tmp[0] = ft_strdup(param[i]);
		else if (ft_strcmp(param[i], "SO") || ft_strcmp(param[i], "SO\t"))
			tmp[1] = ft_strdup(param[i]);
		else if (ft_strcmp(param[i], "WE") || ft_strcmp(param[i], "WE\t"))
			tmp[2] = ft_strdup(param[i]);
		else if (ft_strcmp(param[i], "EA") || ft_strcmp(param[i], "EA\t"))
			tmp[3] = ft_strdup(param[i]);
		else if (ft_strcmp(param[i], "F") || ft_strcmp(param[i], "F\t"))
			tmp[4] = ft_strdup(param[i]);
		else if (ft_strcmp(param[i], "C") || ft_strcmp(param[i], "C\t"))
			tmp[5] = ft_strdup(param[i]);
		i++;
	}
	tmp[i] = NULL;
	free_dbl_array(param);
	return (tmp);
}
