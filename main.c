/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:12:41 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/25 16:48:55 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

//RETAPER LE MAKEFILE, NE PAS OUBLIER LES FLAGS + NE PAS OUBLIER DE VERIFIER QUE LES FICHIERS DONT ON A BESOIN NE SONT PAS DES raydirECTORIES

void	get_initial_player_pos(t_ray *ray, t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || map->map[i][j] == 'E' ||map->map[i][j] == 'W')
			{
				printf("Player found at X = %d, Y = %d\n", j, i);
				ray->pos_x = (double)j + 0.5;
				ray->pos_y = (double)i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		close_win(t_data *data)
{
	//AJOUT FONCTION POUR TOUT FREE;
	//Fonction pour free les textures des murs;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_display(data->mlx_ptr);
	free_map(data->map);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void	rotate_left(t_data *data)
{
	double	olddir_x;
	double	oldplane_x = data->ray.plane_x;

	olddir_x = data->ray.dir_x;
	oldplane_x = data->ray.plane_x;
	data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rot_speed) - data->ray.dir_y * sin(-data->ray.rot_speed);
	data->ray.dir_y = olddir_x * sin(-data->ray.rot_speed) + data->ray.dir_y * cos(-data->ray.rot_speed);
	data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rot_speed) - data->ray.plane_y * sin(-data->ray.rot_speed);
	data->ray.plane_y = oldplane_x * sin(-data->ray.rot_speed) + data->ray.plane_y * cos(-data->ray.rot_speed);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, data->ray.screen_x, data->ray.screen_y);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	start_raycasting(&data->ray, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}

void	rotate_right(t_data *data)
{
	double	olddir_x;
	double	oldplane_x = data->ray.plane_x;

	olddir_x = data->ray.dir_x;
	oldplane_x = data->ray.plane_x;
	data->ray.dir_x = data->ray.dir_x * cos(data->ray.rot_speed) - data->ray.dir_y * sin(data->ray.rot_speed);
	data->ray.dir_y = olddir_x * sin(data->ray.rot_speed) + data->ray.dir_y * cos(data->ray.rot_speed);
	data->ray.plane_x = data->ray.plane_x * cos(data->ray.rot_speed) - data->ray.plane_y * sin(data->ray.rot_speed);
	data->ray.plane_y = oldplane_x * sin(data->ray.rot_speed) + data->ray.plane_y * cos(data->ray.rot_speed);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, data->ray.screen_x, data->ray.screen_y);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	start_raycasting(&data->ray, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}

void	move_up(t_data *data)
{
	if (data->map->map[(int)(data->ray.pos_y)][(int)(data->ray.pos_x + data->ray.dir_x * data->ray.move_speed)] != '1')
		data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
	if (data->map->map[(int)(data->ray.pos_y + data->ray.dir_y * data->ray.move_speed)][(int)(data->ray.pos_x)] != '1')
		data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
	printf("Player pos = %f / %f\n", data->ray.pos_x, data->ray.pos_y);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, data->ray.screen_x, data->ray.screen_y);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	start_raycasting(&data->ray, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}

void	move_down(t_data *data)
{
	if (data->map->map[(int)(data->ray.pos_y)][(int)(data->ray.pos_x - data->ray.dir_x * data->ray.move_speed)] != '1')
		data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
	if (data->map->map[(int)(data->ray.pos_y - data->ray.dir_y * data->ray.move_speed)][(int)(data->ray.pos_x)] != '1')
		data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
	printf("Player pos = %f / %f\n", data->ray.pos_x, data->ray.pos_y);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, data->ray.screen_x, data->ray.screen_y);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	start_raycasting(&data->ray, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
}

int	handle_keypress(int keysym, t_data *data)
{	
	if (keysym == XK_Escape)
	{
		//A REMPLACER PAR LA FONCTION POUR TOUT FREE
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img.img);
		mlx_destroy_display(data->mlx_ptr);
		free_map(data->map);
		free(data->mlx_ptr);
		exit(EXIT_SUCCESS);
		return (0);
	}
	if (keysym == XK_d)
		rotate_right(data);
	if (keysym == XK_a)
		rotate_left(data);
	if (keysym == XK_s)
		move_down(data);
	if (keysym == XK_w)
		move_up(data);
	return (0);
}

int	handle_no_event(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	return (0);
}

void	get_texture_img(t_img *img, t_data *data, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->width, &img->height);
	if (img->img == NULL)
	{
		printf("Error\n");
		//Maxi free ici pls
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	get_textures_img(t_data *data)
{
	get_texture_img(&data->tex->NO, data, data->map->path_to_no);
	get_texture_img(&data->tex->SO, data, data->map->path_to_so);
	get_texture_img(&data->tex->WE, data, data->map->path_to_we);
	get_texture_img(&data->tex->EA, data, data->map->path_to_ea);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_arg(argc, argv);
	data.map = NULL;
	data.map = get_map_from_file(argv[1], data.map);
	// Une fois la partie map faite, l'ajouter à data
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		printf("Error MLX INIT NE PAS OUBLIER D'AJOUTER LA FONCTION POUR FREE\n");
	// mlx_get_screen_size(data.mlx_ptr, &data.ray.screenx, &data.ray.screeny);
	init_raycasting(&data.ray);
	get_textures_img(&data);
	printf("Screen X = %d, screen y = %d\n", data.ray.screen_x, data.ray.screen_y);
	data.ray.screen_x = 1600; // VALEURS TESTS, LES VRAIES VALEURS SERONT RECUP AVEC MLX GET SCREEN SIZE
	data.ray.screen_y = 900; // SAME AS ABOVE
	printf("Screen X = %d, screen y = %d\n", data.ray.screen_x, data.ray.screen_y);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.ray.screen_x, data.ray.screen_y, "cub3d");
	if (data.win_ptr == NULL)
		printf("Error MLX WINDOW NE PAS OUBLIER D'AJOUTER LA FONCTION POUR FREE\n");
	//FONCTION RENDER AVEC LA LOOP COMMENCE ICI
	printf("Initial player pos x = %f, pos y = %f\n", data.ray.pos_x, data.ray.pos_y);
	get_initial_player_pos(&data.ray, data.map);
	printf("Initial player pos x = %f, pos y = %f\n", data.ray.pos_x, data.ray.pos_y);
	render(data);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free_map(data.map);
}
