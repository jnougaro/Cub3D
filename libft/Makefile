# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 12:18:02 by jnougaro          #+#    #+#              #
#    Updated: 2021/10/13 16:51:04 by jnougaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

BONUS	= \

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

CC 	= gcc
RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra -g

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJS_BONUS}
		ar rc ${NAME} ${OBJS} ${OBJS_BONUS}


all:		${NAME}

clean:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all bonus clean fclean re
