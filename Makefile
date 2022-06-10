# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 10:45:42 by jnougaro          #+#    #+#              #
#    Updated: 2022/02/04 15:49:35 by jnougaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

INCLU	= -I./includes -I./mlx

CC 	= clang

LD_FLAGS = -L mlx

MLX_FLAGS = -lm -lmlx -lXext -lX11

CFLAGS	= -Wall -Werror -Wextra

MAIN	= main.c

PATH_PARSING = ./srcs/parsing

PATH_GAME = ./srcs/game

SRCS_PARSING	=	get_next_line.c \
			get_next_line_utils.c \
			utils_parsing.c \
			init_struct.c \
			free_and_print_error.c \
			set_arg.c \
			fill_info.c \
			check_map.c \
			check_map_2.c \
			fill_map_tab.c \
			check_param_rgb.c \
			check_param_coor.c 

SRCS_GAME	=	init_struct_game.c \
			init_mlx.c \
			free_struct_game.c \
			start_game.c \
			handle_event.c \
			handle_player.c \
			cast_rays.c \
			check_hit.c \
			check_wall.c \
			render_3D.c \
			texture.c

SRCS	= $(MAIN) $(addprefix $(PATH_PARSING)/, $(SRCS_PARSING)) \
			$(addprefix $(PATH_GAME)/, $(SRCS_GAME))

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

all:		${NAME}

%.o : %.c
		$(CC) $(INCLU) $(CFLAGS) -c $< -o $@

$(NAME):	${OBJS}
			cp includes/libft.h libft/
			make -C libft/ bonus
			make -C mlx/
			$(CC) $(LD_FLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) libft/libft.a

clean:
		${RM} ${OBJS}
		make -C libft/ clean
		make -C mlx/ clean
		${RM} libft/libft.a
		${RM} libft/libft.h

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
