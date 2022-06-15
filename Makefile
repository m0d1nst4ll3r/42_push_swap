# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 14:37:51 by rpohlen           #+#    #+#              #
#    Updated: 2022/01/28 11:52:07 by rpohlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON	= $(addprefix src/common/, \
			  error.c \
			  list.c \
			  operations.c \
			  args.c)

SRC_SORT	= push_swap.c

SRC_CHECK	= checker.c \
			  $(addprefix src/check/, \
			  exec.c \
			  verif.c \
			  read.c)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror \
			  -O3 \
			  -I include -I libft/include
LIB			= libft/libft.a

SORT		= push_swap

CHECK		= checker

OBJ_COMMON	= $(SRC_COMMON:.c=.o)

OBJ_SORT	= $(SRC_SORT:.c=.o) $(OBJ_COMMON)

OBJ_CHECK	= $(SRC_CHECK:.c=.o) $(OBJ_COMMON)

all:		$(SORT) $(CHECK)

$(SORT):	$(OBJ_SORT)
			make -C libft
			$(CC) $(CFLAGS) $(OBJ_SORT) $(LIB) -o $(SORT)

$(CHECK):	$(OBJ_CHECK)
			make -C libft
			$(CC) $(CFLAGS) $(OBJ_CHECK) $(LIB) -o $(CHECK)

clean:
			make clean -C libft
			rm -f $(OBJ_SORT) $(OBJ_CHECK)

fclean:		clean
			make fclean -C libft
			rm -f $(SORT) $(CHECK)

re:			fclean all

.PHONY:		all clean fclean re
