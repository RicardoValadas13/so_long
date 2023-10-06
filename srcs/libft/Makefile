# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 14:49:56 by rbenjami          #+#    #+#              #
#    Updated: 2023/10/06 14:06:05 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRC_FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_calloc.c\
	ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strdup.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c\
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c \
	ft_printf/ft_hexbase16lc.c  ft_printf/ft_printadress.c  ft_printf/ft_putchar.c  ft_printf/ft_putstr.c \
	ft_printf/ft_hexbase16uc.c  ft_printf/ft_printf.c	    ft_printf/ft_putnbr.c   ft_printf/ft_unsdec10.c
	
	
SRC_DIR = srcs

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

CFLAGS = -Wall -Werror -Wextra -Iinc

all: $(NAME)

$(NAME) : $(OBJ)
	ar -crs $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re