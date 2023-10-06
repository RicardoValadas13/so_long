# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 12:00:28 by rbenjami          #+#    #+#              #
#    Updated: 2023/10/06 14:03:50 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Isrcs/libft/inc -Iinc

SRCS =	./srcs/so_long.c

OBJS :=$(SRCS:.c=.o)

#lib paths
LIBFT_PATH = srcs/libft

#lib names
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	

fclean: clean 
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re