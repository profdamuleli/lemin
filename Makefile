# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 11:34:56 by ldamulel          #+#    #+#              #
#    Updated: 2018/04/03 11:35:09 by ldamulel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFILES = lemin.c \
	 ants_movements.c \
	 connect.c \
	 error_checks.c \
	 generate_room.c \
	 path_process.c \
	 queue_process.c \
	 free_trim.c \
	 free_lemin.c \

OFILES = lemin.o \
	 ants_movements.o \
	 connect.o \
	 error_checks.o \
	 generate_room.o \
	 path_process.o \
	 queue_process.o \
	 free_trim.o \
	 free_lemin.o \

LIBFT = ./libft

FLAGS = -Wall \
	-Wextra \
	-Werror \

all: $(NAME)

$(NAME): 
	 @make -C $(LIBFT)
	 @gcc -c $(FLAGS) $(CFILES)
	 @gcc -o $(NAME) $(FLAGS) $(OFILES) -L$(LIBFT) -lft

clean: 
	@rm -f $(OFILES)
	@cd ./libft && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd ./libft && $(MAKE) fclean

re: fclean all
