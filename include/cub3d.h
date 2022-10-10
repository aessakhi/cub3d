/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:13:35 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/10 10:43:39 by aessakhi         ###   ########.fr       */
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
	int		*floor_rgb;
	int		*ceiling_rgb;
}	t_map;

typedef struct s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		raydir_x;
	double		raydir_y;
	double		camera_x;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perpwalldist;
	int			line_height;
	int			drawstart;
	int			drawend;
	int			x;
	int			screen_x;
	int			screen_y;
	int			floor_color;
	int			ceiling_color;
	double		rot_speed;
	double		move_speed;
}					t_ray;

typedef struct s_texture_check
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
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

typedef struct s_img
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
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
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
	t_tex		tex[4];
	t_map		*map;
}	t_data;

//Check file
void			check_arg(int argc, char **argv);
int				check_file_extension(char	*file, char *ext);
void			check_if_file_exists(char	*file);

//Parse file
t_map			*get_map_from_file(char *file, t_map *map);
int				get_number_of_lines(char *file);
void			check_number_of_lines(int n_lines);
void			get_file_content(char *file, char **tmp);
void			get_textures(char	**tmp, t_map *map);

//Get textures
void			get_textures(char **tmp, t_map *map);
void			get_textures_2(t_texture_check *tex,
					char **tmp, t_map *map, int i);
void			get_map(t_texture_check *tex, char **tmp, t_map *map, int i);
void			check_if_empty_line_in_map(char **tmp, t_map *map, int i);
int				is_map(char *str);
int				is_empty_line(char *str);
void			get_no(t_texture_check *tex, char **tmp, t_map *map, int i);
void			get_so(t_texture_check *tex, char **tmp, t_map *map, int i);
void			get_we(t_texture_check *tex, char **tmp, t_map *map, int i);
void			get_ea(t_texture_check *tex, char **tmp, t_map *map, int i);
void			get_f(t_texture_check *tex, char **tmp, t_map *map, int i);
void			get_c(t_texture_check *tex, char **tmp, t_map *map, int i);
char			**param_in_order(char **param);
int				check_end_of_map(char **tmp, int i);
char			*replace_tab_by_spaces(char	*str);
void			replace_tab_by_spaces_loop(char *str,
					char *result, t_tab_check *tab);
int				count_n_of_tabs(char	*str);
void			free_map(t_map *map);

//Parse map
void			parse_map(t_map *map);
int				get_max_line_size(char	**array);

//Utils
char			*ft_strdup(const char *s1);
void			free_dbl_array(char	**array);
void			print_dbl_array(char **array);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strtrim(char *s1, char const *set);
char			*ft_strjoin_cub3d(char *s1, char *s2);
char			**ft_split(char const *s, char *sep);
int				dblarray_size(char **array);
int				ft_atoi(const char *str);
void			print_int_array(int	*array);
char			*ft_strjoin_2(char *s1, char *s2);
int				ft_str_is_digit(char *str);

//Error
void			ft_perror_parsing(t_map *map, char *error);

//Check map sides
void			check_map_sides(char **str, t_error *error, int max_size);
void			check_left_side(char **str, t_error *error);
void			check_right_side(char **str, t_error *error, int max_size);
void			check_bottom_side(char **str, t_error *error);
void			check_top_side(char **str, t_error *error);
void			check_downwards(char **str, t_error *error, int i, int j);
void			check_upwards(char **str, t_error *error, int i, int j);
void			check_left(char **str, t_error *error, int i, int j);
void			check_right(char **str, t_error *error, int i, int j);
void			check_around_space(char **str, t_error *error, int i, int j);

void			get_color_range(t_map *map);
void			get_texture_path(t_map *map);
void			final_map_check(char **str, t_error *error, t_map *map);
void			replace(char **str, char to_replace, char replaced);
void			fill_every_line(t_map *map, int line_size);
void			check_line(char **str, int i, t_error *error);
void			check_first_last_line(char	*str, t_map *map);
void			check_first_wall(char **str, int i, t_error *error);
void			check_last_wall(char **str, int i, t_error *error);
char			*append_spaces(char *str, int n_of_spaces);

//Init
void			init_tex_check(t_texture_check *tex_check);
void			init_map(t_map *map);
void			init_raycasting(t_ray *ray, t_data *data);

//Raycasting
void			start_raycasting(t_ray *ray, t_data *data);
void			render(t_data data);

//Hooks & loops
int				handle_no_event(t_data *data);
int				close_win(t_data *data);
int				handle_keypress(int keysym, t_data *data);

//Move player
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
void			move_up(t_data *data);
void			move_down(t_data *data);
void			move_right(t_data *data);
void			move_left(t_data *data);

//Get textures img
void			get_texture_img(t_img *img, t_data *data, char *path);
void			get_textures_img(t_data *data);

//Use colors
int				convert_rgb(int	*rgb);
void			get_colors(t_ray *ray, t_map *map);

//Get player
void			get_initial_player_pos(t_ray *ray, t_map *map);
void			get_orientation(t_ray *ray, char c);

//Free
void			free_mlx(t_data *data);
void			free_texture_img(t_img *img, t_data *data);
void			free_textures(t_data *data);
void			free_everything(t_data *data);

//Draw
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_pixel_from_img(t_img *img, int x, int y);
void			draw_wall(t_ray *ray, t_tex *tex, t_img *img, t_data *data);
void			draw_floor(t_ray *ray, t_data *data);
void			draw_ceiling(t_ray *ray, t_data *data);
void			render_new_image(t_data *data);

#endif
