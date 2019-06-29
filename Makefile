# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 21:16:18 by vrichese          #+#    #+#              #
#    Updated: 2019/06/29 16:30:38 by vrichese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1	= push_swap
NAME_2	= checker

PUSDIR	= source/push_swap_func
CHEDIR	= source/checker_func
COMDIR	= source/common_functions

GNLDIR	= get_next_line
LIBDIR	= $(GNLDIR)/libft
FT_DIR	= ft_printf

LIBFINC	= $(LIBDIR)/includes
PRININC	= $(FT_DIR)/includes
GNLINCL = $(GNLDIR)/includes
INCLUDE	= includes

SRC_PU	= $(addprefix $(PUSDIR)/, push_swap.c quicksort.c available_commands.c optimizer_string.c sort_100.c)
SRC_CH	= $(addprefix $(CHEDIR)/, checker.c available_acts.c flags_handler.c) $(GNLDIR)/source/get_next_line.c
SRC_CO	= $(addprefix $(COMDIR)/, common_functions.c args_handler.c sorting_algorithm.c)

CC		= gcc

#CFLAGS	= -Wall -Werror -Wextra

all: $(NAME_1) $(NAME_2)

$(NAME_1):
	@cd $(FT_DIR) && $(MAKE)
	@cd $(LIBDIR) && $(MAKE)
	@$(CC) $(CFLAGS) -I./$(INCLUDE) -I./$(LIBFINC) -I./$(PRININC) -I./$(GNLINCL) $(SRC_PU) $(SRC_CO) $(FT_DIR)/libftprintf.a $(LIBDIR)/libft.a -g -o $(NAME_1)

$(NAME_2):
	@$(CC) $(CFLAGS) -I./$(INCLUDE) -I./$(LIBFINC) -I./$(PRININC) -I./$(GNLINCL) $(SRC_CH) $(SRC_CO) $(FT_DIR)/libftprintf.a $(LIBDIR)/libft.a -o $(NAME_2)

clean:
	@rm -f $(OBJ_PU) $(OBJ_PU)
	@cd $(LIBDIR) && $(MAKE) clean
	@cd $(FT_DIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME_1) $(NAME_2)
	@cd $(LIBDIR) && $(MAKE) fclean
	@cd $(FT_DIR) && $(MAKE) fclean

re: fclean all