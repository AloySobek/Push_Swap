# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 21:16:18 by vrichese          #+#    #+#              #
#    Updated: 2019/07/15 14:47:23 by vrichese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1	= push_swap
NAME_2	= checker

PUSH_SW	= source/push_swap_func
CHECKER	= source/checker_func
COMMON_	= source/common_functions

LIBDIR	= $(GNLDIR)/libft
FT_DIR	= ft_printf
GNLDIR	= get_next_line

LIBFT	= $(LIBDIR)/libft.a
PRINTF	= $(FT_DIR)/libftprintf.a
GNL		= $(GNLDIR)/source/get_next_line.c

PRININC	= $(FT_DIR)/includes
LIBFINC	= $(LIBDIR)/includes
GNLINCL	= $(GNLDIR)/includes
PUSHINC	= includes
INCLUDE	= -I./$(PRININC) -I./$(LIBFINC) -I./$(GNLINCL) -I./$(PUSHINC)

SRC_PUS	= $(addprefix $(PUSH_SW)/, push_swap.c available_acts.c quicksort.c optimizer_string.c sort_100.c)

SRC_CHE	= $(addprefix $(CHECKER)/, checker.c available_acts.c flags_handler.c) $(GNL)

SRC_COM	= $(addprefix $(COMMON_)/, common_functions.c args_handler.c sorting_algorithm.c)

OBJ_PUS	= ${SRC_PUS:%.c=%.o}

OBJ_CHE	= ${SRC_CHE:%.с=%.o}

OBJ_COM	= ${SRC_COM:%.c=%.o}

CFLAGS	= -Wall -Werror -Wextra

CC		= gcc

all: $(NAME_1) $(NAME_2)


$(NAME_1): $(OBJ_PUS) $(OBJ_COM) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_2): $(OBJ_CHE) $(OBJ_COM) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(PUSH_SW)/%.o: $(PUSH_SW)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(CHECKER)/%.o: $(CHECKER)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(COMMON_)/%.o: $(COMMON_)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)
	@$(MAKE) -C $(LIBDIR) clean

$(PRINTF):
	@$(MAKE) -C $(FT_DIR)
	@$(MAKE) -C $(FT_DIR) clean

clean:
	@rm -f $(OBJ_PUS) $(OBJ_COM)

fclean: clean
	@rm -f $(NAME_1) $(NAME_2)
	@$(MAKE) -C $(LIBDIR) fclean
	@$(MAKE) -C $(FT_DIR) fclean

re: fclean all
