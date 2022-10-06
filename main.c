/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:12:41 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/05 13:08:36 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

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
	if (data.ray.screen_x > 1920)
		data.ray.screen_x = 1920;
	if (data.ray.screen_y > 1080)
		data.ray.screen_y = 1080;
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			data.ray.screen_x, data.ray.screen_y, "cub3d");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		ft_perror_parsing(data.map, "Window init issue");
	}
	render(data);
	free_everything(&data);
}
