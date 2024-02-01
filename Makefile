# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 19:26:27 by emikhayl          #+#    #+#              #
#    Updated: 2024/02/01 20:56:20 by emikhayl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = push_swap.h

SOURCES = big_sort.c check_input.c swap.c helper_sort.c main.c set_index.c \
		  sort_alg.c stack_commands.c push.c rotate.c rrr.c find_last_node.c \
		  reverse_rotate.c push_swap.c


OBJECTS = $(SOURCES:.c=.o)

COMPILER = gcc

CFLAGS = -Wall -Wextra -Werror

# Metodo implicito
%.o: %.c	$(INCLUDES) Makefile
	$(COMPILER) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

# Mis metodos
all: 	$(NAME)

# Link object files to create the executable
#$(OBJECTS): $(SOURCES) $(INCLUDES) Makefile

$(NAME): $(OBJECTS)
	$(COMPILER) -o $(NAME) $(OBJECTS) $(CFLAGS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
