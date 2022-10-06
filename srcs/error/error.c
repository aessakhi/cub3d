/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:52:20 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:05:11 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_perror_parsing(t_map *map, char *error)
{
	printf("Error\n%s\n", error);
	free_map(map);
	exit(EXIT_FAILURE);
}
