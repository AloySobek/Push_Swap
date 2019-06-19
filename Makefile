# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 21:16:18 by vrichese          #+#    #+#              #
#    Updated: 2019/06/19 19:15:52 by vrichese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1	= push_swap
NAME_2	= checker

PUSDIR	= source/push_swap_func
CHEDIR	= source/checker_func

LIBDIR	= libft
FT_DIR	= ft_printf

SRC_PU	= $(addprefix $(PUSDIR)/, push_swap.c)
SRC_CH	= $(addprefix $(CHEDIR)/, checker.c available_commands.c get_next_line.c)

INCLUDE	= includes

CC		= gcc

#CFLAGS	= -Wall -Werror -Wextra

all: $(NAME_1) $(NAME_2)

$(NAME_1):
	@cd $(FT_DIR) && $(MAKE)
	@$(CC) $(CFLAGS) -I./$(INCLUDE) $(SRC_PU) $(FT_DIR)/libftprintf.a -o $(NAME_1)

$(NAME_2):
	@cd $(LIBDIR) && $(MAKE)
	@$(CC) $(CFLAGS) -I./$(INCLUDE) $(SRC_CH) $(FT_DIR)/libftprintf.a $(LIBDIR)/libft.a -o $(NAME_2)
	@cd $(LIBDIR) && $(MAKE) fclean
	@cd $(FT_DIR) && $(MAKE) fclean

clean:
	@rm -f $(OBJ_PU) $(OBJ_PU)

fclean: clean
	@rm -f $(NAME_1) $(NAME_2)

re: fclean all