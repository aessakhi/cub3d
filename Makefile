# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:57:17 by aessakhi          #+#    #+#              #
#    Updated: 2022/10/10 10:45:43 by aessakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	main.c \
			srcs/error/error.c \
			srcs/file/check_file.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			srcs/parsing/check_colors.c srcs/parsing/check_if_map_closed.c srcs/parsing/check_map.c srcs/parsing/check_map_direction.c srcs/parsing/check_map_side.c srcs/parsing/param_in_order.c srcs/parsing/check_textures.c srcs/parsing/get_colors.c srcs/parsing/get_map.c srcs/parsing/get_textures.c srcs/parsing/get_wall_textures.c srcs/parsing/parse_file.c srcs/parsing/replace_tabs.c \
			srcs/utils/2D_array.c srcs/utils/free.c srcs/utils/ft_atoi.c srcs/utils/ft_split.c srcs/utils/ft_strjoin_2.c srcs/utils/ft_strjoin_cub3d.c srcs/utils/map_utils.c srcs/utils/utils.c srcs/utils/ft_str_is_digit.c\
			srcs/raycasting/raycasting.c srcs/raycasting/get_texture_img.c srcs/raycasting/use_colors.c \
			srcs/mlx/my_mlx_pixel_put.c srcs/mlx/get_pixel_from_img.c srcs/mlx/hooks.c srcs/mlx/move_player.c srcs/mlx/rotate_player.c srcs/mlx/draw.c srcs/mlx/render.c\
			srcs/init/init.c srcs/init/get_player.c

CC		= gcc

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

NAME	= cub3D

RM		= rm -f

all: ${NAME}

$(NAME):	${OBJS}
	make -C minilibx-linux/
	gcc -o ${NAME} ${OBJS} -Lminilibx-linux -lmlx -lm -lbsd -lX11 -lXext ${CFLAGS}

clean:
	${RM} ${OBJS}
	make clean -C minilibx-linux/

fclean: clean
	${RM} ${NAME}
	make clean -C minilibx-linux/

re:		fclean all

.PHONY:	all clean fclean re bonus
