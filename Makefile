# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clboutry <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 15:47:19 by clboutry          #+#    #+#              #
#    Updated: 2019/02/02 15:37:23 by aahizi-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fillit

SRCS = valid_file.c\
	   valid_tetri.c\
	   backtracking.c\
	   error.c\
	   map.c

FLAGS = -Wall -Wextra -Werror

LIBRARY = libft/libft.a

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) 
	make -C libft/
	$(CC) $(FLAGS) $(LIBRARY) $^ -o $@

clean:
	rm -rf $(OBJS)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all
