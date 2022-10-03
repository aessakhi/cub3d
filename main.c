/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:12:41 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/03 19:09:47 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

//RETAPER LE MAKEFILE, NE PAS OUBLIER LES FLAGS + NE PAS OUBLIER DE VERIFIER QUE LES FICHIERS DONT ON A BESOIN NE SONT PAS DES raydirECTORIES
int	main(int argc, char **argv)
{
	t_data	data;

	check_arg(argc, argv);
	data.map = NULL;
	data.map = get_map_from_file(argv[1], data.map);
	data.img.img = NULL;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_perror_parsing(data.map, "Mlx init issue");
	mlx_get_screen_size(data.mlx_ptr, &data.ray.screen_x, &data.ray.screen_y);
	data.ray.screen_x = data.ray.screen_x / 2;
	data.ray.screen_y = data.ray.screen_y / 2;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.ray.screen_x, data.ray.screen_y, "cub3d");
	if (data.win_ptr == NULL)
	{
		printf("Error\nIssue with creating the window\n");
		free_map(data.map);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		exit(EXIT_FAILURE);
	}
	render(data);
	free_everything(&data);
}
