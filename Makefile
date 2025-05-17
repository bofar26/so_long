# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipang <mipang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 13:02:31 by mipang            #+#    #+#              #
#    Updated: 2025/05/16 16:12:36 by mipang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude -Iminilibx
SRCS = src/main.c \
	src/utiles/utiles.c \
	src/map/map_check_path_valid.c \
	src/map/map_elements_check_utiles.c \
	src/map/map_input_check.c \
	src/map/map_get_map.c \
	src/map/load_map.c \
	src/map/map_utils.c \
	src/control/handle_key_move.c

OBJS =$(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT =$(LIBFT_DIR)/libft.a
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm -lbsd

all:$(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

mlx:
	@make -C $(MLX_DIR)
	
$(NAME):$(OBJS) $(LIBFT) mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean:clean
	rm -f $(NAME)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean

re:fclean all

.PHONY: clean fclean all re

