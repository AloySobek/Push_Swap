# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 21:16:18 by vrichese          #+#    #+#              #
#    Updated: 2019/06/19 15:15:56 by vrichese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1	= push_swap
NAME_2	= checker

SRCDIR	= source
LIBDIR	= libft
FT_DIR	= ft_printf

SRC_PU	= $(addprefix $(SRCDIR)/, push_swap.c)

SRC_CH	= $(addprefix $(LIBDIR)/, checker.c available_commands.c)

OBJ		= ${SRC:.c=.o} ${LIB:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
$(LIBDIR)/%.o: $(LIBDIR)/%.c
	$(CC) $(CFLAGS) -I./includes -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all