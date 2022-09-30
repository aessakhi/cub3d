/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:13:35 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/28 18:14:57 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

//Struct pour les info du joueurs X, Y, SPEED, ANGLE, ROTATE SPEED PEUT METTRE CA DIRECT DANS LA STRUCTURE RAYCAST ?

typedef struct s_map
{
	char	**map;
	char	**param;
	char	*tmp_map;
	char	*tmp_param;
	char	*path_to_no;
	char	*path_to_so;
	char	*path_to_we;
	char	*path_to_ea;
	int		*floor_RGB;
	int		*ceiling_RGB;
}	t_map;

typedef struct	s_ray
{
	double		pos_x; //position x du joueur
	double		pos_y; //position y du joueur
	double		dir_x; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		dir_y; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		plane_x; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plane_y; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydir_x; //calcul de direction x du rayon
	double		raydir_y; //calcul de direction y du rayon
	double		camera_x; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		map_x; // coordonée x du carré dans lequel est pos
	int		map_y; // coordonnée y du carré dans lequel est pos
	double		sidedist_x; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedist_y; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadist_x; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadist_y; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		step_x; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		step_y; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int		line_height; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		x; //permet de parcourir tous les rayons
	int		screen_x;
	int		screen_y;
	int		floor_color;
	int		ceiling_color;
	double	rot_speed;
	double	move_speed;
}					t_ray;

typedef struct s_texture_check
{
	int	NO;
	int	SO;
	int	WE;
	int	EA;
	int	F;
	int	C;
	int	map;
}	t_texture_check;

typedef struct s_error
{
	int	map_not_closed;
	int	player;
}	t_error;

typedef struct s_tab_check
{
	int	i;
	int	j;
	int	x;
}	t_tab_check;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_tex
{
	t_img	NO;
	t_img	SO;
	t_img	WE;
	t_img	EA;
	double	wall_x;
	int		x;
	int		y;
	double	step;
	double	pos;
}	t_tex;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_ray		ray;
	t_img		img;
	t_tex	tex[4];
	t_map		*map;
}	t_data;

//Check file
void	check_arg(int argc, char **argv);
int		check_file_extension(char	*file, char *ext);
void	check_if_file_exists(char	*file);

//Parse file
t_map	*get_map_from_file(char *file, t_map *map);
int		get_number_of_lines(char *file);
void	check_number_of_lines(int n_lines);
void	get_file_content(char *file, char **tmp);
void	get_textures(char	**tmp, t_map *map);

//Get textures
void	get_textures(char **tmp, t_map *map);
void	get_textures_2(t_texture_check *tex, char **tmp, t_map *map, int i);
void	get_map(t_texture_check *tex, char **tmp, t_map *map, int i);
void	check_if_empty_line_in_map(t_texture_check *tex, char **tmp, t_map *map, int i);
int		is_map(char *str);
int		is_empty_line(char *str);
void	get_NO(t_texture_check *tex, char **tmp, t_map *map, int i);
void	get_SO(t_texture_check *tex, char **tmp, t_map *map, int i);
void	get_WE(t_texture_check *tex, char **tmp, t_map *map, int i);
void	get_EA(t_texture_check *tex, char **tmp, t_map *map, int i);
void	get_F(t_texture_check *tex, char **tmp, t_map *map, int i);
void	get_C(t_texture_check *tex, char **tmp, t_map *map, int i);
int		check_end_of_map(char **tmp, int i);
char	*replace_tab_by_spaces(char	*str);
void	replace_tab_by_spaces_loop(char *str, char *result, t_tab_check *tab);
int		count_n_of_tabs(char	*str);
void	free_map(t_map *map);

//Parse map
void	parse_map(t_map *map);
int		get_max_line_size(char	**array);

//Utils
char	*ft_strdup(const char *s1);
void	free_dbl_array(char	**array);
void	print_dbl_array(char **array);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strtrim(char *s1, char const *set);
char *ft_strjoin_cub3D(char *s1, char *s2);
char	**ft_split(char const *s, char *sep);
int		dblarray_size(char **array);
int		ft_atoi(const char *str);
void	print_int_array(int	*array);
char *ft_strjoin_2(char *s1, char *s2);

//Error
void	ft_perror_parsing(t_map *map, char *error);

//Check map sides
void	check_left_side(char **str, t_error *error);
void	check_right_side(char **str, t_error *error, int max_size);
void	check_bottom_side(char **str, t_error *error);
void	check_top_side(char **str, t_error *error);

void	get_color_range(t_map *map);
void	get_texture_path(t_map *map);
void	final_map_check(char **str, t_error *error);
void	replace(char **str, char to_replace, char replaced);
void	fill_every_line(t_map *map, int line_size);
void	check_line(char	**str, int	i, t_error *error);
void	check_first_last_line(char	*str);
void	check_first_wall(char **str, int i, t_error *error);
void	check_last_wall(char **str, int i, t_error *error);
char	*append_spaces(char *str, int n_of_spaces);

//
void	check_downwards(char **str, t_error *error, int i, int j);
void	check_upwards(char **str, t_error *error, int i, int j);
void	check_left(char **str, t_error *error, int i, int j);
void	check_right(char **str, t_error *error, int i, int j);
void	check_around_space(char **str, t_error *error, int i, int j);

//Init
void	init_tex_check(t_texture_check *tex_check);
void	init_map(t_map *map);
void	init_raycasting(t_ray *ray);

//Raycasting
void	start_raycasting(t_ray *ray, t_data *data);
void	render(t_data data);

//Drawing
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

//Hooks & loops
int	handle_no_event(t_data *data);
int		close_win(t_data *data);
int	handle_keypress(int keysym, t_data *data);

#endif
