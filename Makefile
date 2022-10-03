# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:57:17 by aessakhi          #+#    #+#              #
#    Updated: 2022/10/03 19:28:35 by aessakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	main.c error/error.c \
			file/check_file.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			parsing/check_colors.c parsing/check_if_map_closed.c parsing/check_map.c parsing/check_map_direction.c parsing/check_map_side.c parsing/check_textures.c parsing/get_colors.c parsing/get_map.c parsing/get_textures.c parsing/get_wall_textures.c parsing/parse_file.c parsing/replace_tabs.c \
			utils/2D_array.c utils/free.c utils/ft_atoi.c utils/ft_split.c utils/ft_strjoin_2.c utils/ft_strjoin_cub3d.c utils/map_utils.c utils/utils.c \
			raycasting/raycasting.c raycasting/get_texture_img.c raycasting/use_colors.c \
			mlx/my_mlx_pixel_put.c mlx/get_pixel_from_img.c mlx/hooks.c mlx/move_player.c mlx/draw.c mlx/render.c\
			init/init.c init/get_player.c

CC		= gcc

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

NAME	= cub3d

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
