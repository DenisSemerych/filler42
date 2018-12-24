# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 19:58:50 by dsemeryc          #+#    #+#              #
#    Updated: 2018/12/23 18:22:12 by dsemeryc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dsemeryc.filler

OBJ = main.o read_info.o useful.o play.o useful_2.o

SRCS = main.c read_info.c useful.c play.c useful_2.c

CFLAGS = -Wall -Wextra -Werror

all:
	make -C libftprintf/
	@gcc -c $(CFLAGS) $(SRCS) -I includes/
	@gcc -o $(NAME) $(CFLAGS) $(OBJ) libftprintf/libftprintf.a -I includes/
	@echo "Ready for action"

clean:
	@make clean -C libftprintf
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libftprintf
	@rm -rf $(NAME)

re: fclean all
