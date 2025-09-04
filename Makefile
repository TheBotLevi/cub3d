# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 17:25:08 by ljeribha          #+#    #+#              #
#    Updated: 2025/09/03 16:52:44 by ljeribha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
INCLUDES = inc/cub3d.h

SRC_DIR = src
OBJ_DIR = obj
MLX_INC = miniLibX/minilibx-linux
MLX_LIB = ${MLX_INC}/libmlx_Linux.a

PATH_LIBFT = libft
PATH_PRINTF = libft/ft_printf
PATH_GNL = libft/get_next_line

FT_PRINTF = ${PATH_LIBFT}/ft_printf/libftprintf.a
GET_NEXT_LINE = ${PATH_LIBFT}/get_next_line/get_next_line.a
LIBFT = ${PATH_LIBFT}/libft.a

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
SRCS = src/cub_hooks.c \
	src/cub_main.c \
	src/cub_utils.c

CUB3D = cub3d

OBJ_DIRS = ${OBJ_DIR}

LDFLAGS = -L${MLX_INC} -lmlx_Linux -lX11 -lXext -L${PATH_LIBFT}
HEADER = -I. -I${PATH_LIBFT} -I${MLX_INC}

all: ${OBJ_DIRS} ${LIBFT} ${CUB3D}

${OBJ_DIRS}:
	mkdir -p ${OBJ_DIRS}

${CUB3D}: ${OBJS} ${LIBFT} ${GET_NEXT_LINE} ${FT_PRINTF}
	${CC} -g ${CFLAGS} -o $@ $^ ${LDFLAGS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INCLUDES} | ${OBJ_DIRS}
	@ ${CC} -g ${CFLAGS} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${PATH_LIBFT} --no-print-directory > /dev/null 2>&1

${FT_PRINTF}:
	${MAKE} -C ${PATH_PRINTF} --no-print-directory > /dev/null 2>&1

${GET_NEXT_LINE}:
	${MAKE} -C ${PATH_GNL} --no-print-directory > /dev/null 2>&1

clean:
	rm -f ${OBJS}
	rm -rf ${OBJ_DIR}
	${MAKE} -C ${PATH_LIBFT} clean

fclean: clean
	rm -f ${CUB3D}
	${MAKE} -C ${PATH_LIBFT} fclean

re: fclean all

.PHONY: all clean fclean re