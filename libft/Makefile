# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/20 13:55:40 by ldamulel          #+#    #+#              #
#    Updated: 2018/01/09 10:34:53 by ldamulel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = includes/

SRC = ft_strcpy.c ft_strncpy.c ft_isdigit.c ft_toupper.c ft_tolower.c \
	  ft_isalpha.c ft_isalnum.c ft_isprint.c ft_strlen.c ft_strdup.c \
	  ft_strstr.c ft_putchar.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_strcat.c ft_strncat.c ft_memcpy.c ft_bzero.c ft_memset.c \
	  ft_isascii.c ft_memccpy.c ft_strdel.c ft_strclr.c ft_memdel.c \
	  ft_memalloc.c ft_strnew.c ft_putendl.c ft_putendl_fd.c ft_striter.c \
	  ft_striteri.c ft_strcmp.c ft_strjoin.c ft_memcmp.c ft_strchr.c \
	  ft_strrchr.c ft_strmap.c ft_strsub.c ft_memchr.c ft_strequ.c \
	  ft_strncmp.c ft_strnequ.c ft_strmapi.c ft_memmove.c  ft_strlen.c\
	  ft_strnstr.c ft_strlcat.c ft_strtrim.c ft_itoa.c ft_strsplit.c \
	  ft_putnbr_fd.c ft_putnbr.c ft_atoi.c get_next_line.c\

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf *.o

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

