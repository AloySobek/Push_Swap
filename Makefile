# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 21:16:18 by vrichese          #+#    #+#              #
#    Updated: 2019/06/19 17:28:04 by vrichese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1	= push_swap
NAME_2	= checker

SRCDIR	= source
LIBDIR	= libft
FT_DIR	= ft_printf

SRC_PU	= $(addprefix $(SRCDIR)/, push_swap.c)

SRC_CH	= $(addprefix $(LIBDIR)/, checker.c available_commands.c)

OBJ_PU	= ${SRC_PU:.c=.o}

OBJ_CH	= ${SRC_CH:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_PU) $(OBJ_CH)

$(SRC_PU)/%.o: $(SRC_PU)/%.c
	$(CC) $(CFLAGS) -I./includes -c $< -o $(NAME_1)

$(SRC_CH)/%.o: $(SRC_CH)/%.c
	$(CC) $(CFLAGS) -I./includes -c $< -o $(NAME_2)

clean:
	@rm -f $(OBJ_PU) $(OBJ_PU)

fclean: clean
	@rm -f $(NAME_1) $(NAME_2)

re: fclean all