/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:09:50 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/10 10:14:59 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
			printf("Error\nNo map specified. Usage: ./cub3d MAP_NAME.cub\n");
		else
		{
			printf("Error\n");
			printf("Incorrect number of args. Usage: ./cub3d MAP_NAME.cub\n");
		}
		exit(EXIT_FAILURE);
	}
	check_file_extension(argv[1], ".cub");
	check_if_file_exists(argv[1]);
}

int	check_file_extension(char	*file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file) - 4;
	j = 0;
	while (file[i])
	{
		if (file[i] != ext[j])
		{
			printf("Error\nNot a .cub file. Usage: ./cub3d MAP_NAME.cub\n");
			exit(EXIT_FAILURE);
		}
		i++;
		j++;
	}
	return (1);
}

void	check_if_file_exists(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		if (errno == EISDIR)
			printf("Error\n.cub is a directory\n");
		else
			printf("Error\nNo such file or directory\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}
