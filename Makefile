# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 12:00:28 by rbenjami          #+#    #+#              #
#    Updated: 2023/10/19 18:00:45 by ricardovala      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS = -lmlx_Linux -lXext -lX11 -lm
	MLX_DIRECTORY = mlx_linux/
else ifeq ($(UNAME), Darwin)
	CFLAGS = -lmlx -framework OpenGL -framework AppKit
	MLX_DIRECTORY = mlx_mac/
endif


LIBFT_DIRECTORY = srcs/libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)
LIBFT = $(LIBFT_DIRECTORY)libft.a

MLX_HEADER = $(MLX_DIRECTORY)
MLX = $(MLX_DIRECTORY)libmlx.a

HEADERS_LIST = so_long.h
HEADERS_DIRECTORY = inc/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SCRS_LIST = checkers_utils.c \
			checkers.c \
			error.c \
			game_logic.c \
			game_render.c \
			game_sprites.c \
			key_handling.c \
			so_long_utils.c \
			so_long.c \
			xpm_parser.c
SCRS_DIRECTORY = srcs/
SCRS = $(addprefix $(SCRS_DIRECTORY), $(SCRS_LIST))

OBJS_LIST = $(patsubst %.c, %.o, $(SCRS_LIST))
OBJS_DIRECTORY = objs/
OBJS = $(addprefix $(OBJS_DIRECTORY), $(OBJS_LIST))

CC = cc
FLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
LIBRARIES = -L$(LIBFT_DIRECTORY) -lft -L$(MLX_DIRECTORY) $(CFLAGS)
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADER) -I $(MLX_HEADER)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_DIRECTORY) $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIBRARIES) -o $(NAME)

$(OBJS_DIRECTORY):
	mkdir -p $(OBJS_DIRECTORY)

$(OBJS_DIRECTORY)%.o : $(SCRS_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -sC $(LIBFT_DIRECTORY)

$(MLX):
	make -sC $(MLX_DIRECTORY)

clean:
	make -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJS_DIRECTORY)

fclean: clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	make -sC $(LIBFT_DIRECTORY) clean
	rm -f $(NAME)

re:
	make fclean
	make all

git:
	git add .
	git commit
	git push
	
.PHONY  : re fclean clean all