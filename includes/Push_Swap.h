/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:46:30 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 18:31:28 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

typedef enum		e_stacks
{
	A, B, I
}					t_stacks;

typedef enum		e_strings
{
	MAJOR, FREED, PRINT
}					t_strings;

typedef struct		s_stack
{
	int				value;
	int				index;
	int				stack;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

# define DEB		0x8000000
# define COL		0x10000000
# define INT		0x20000000
# define DES		0x40000000

# define _FILE__	(*flags << 40) >> 40
# define _TIME__	(*flags >> 32)

# define P_G		ft_printf("@{green}▄@{eoc}")
# define P_R		ft_printf("@{red}▄@{eoc}")

t_stack				*get_elem_from_stack(t_stack **a, int index);
t_stack				*new_elem_of_stack(int value, int index);
t_stack				*copy_stack(t_stack *a, int high);
void				push_optimizer(int where, char **res);
void				swap_optimizer(int where, char **res);
void				rotate_optimizer(int where, char **res);
void				reverse_optimizer(int where, char **res);
void				labeler(t_stack **a, int size);
void				sort_100(t_stack **a, t_stack **b, int size, char **act);
void				error_handler(int code, int none);
void				swap_for_quicksort(t_stack **a, int i, int j);
void				quicksort_ascending(t_stack **a, t_stack **b,
					int high, char **res);
void				quicksort_descending(t_stack **a, t_stack **b,
					int high, char **res);
void				quicksort(t_stack **a, int low, int high);
void				free_list(t_stack **a);
void				flags_picker(char *str, char *fd, size_t *flags);
int					sort_three_ascending(t_stack **a, char **res);
int					push_(t_stack **a, t_stack **b, char **res);
int					swap_(t_stack **a, char **res);
int					rotate_(t_stack **a, char **res);
int					reverse_(t_stack **a, char **res);
int					is_sorted(t_stack *a);
int					partition(t_stack **a, int low, int high);
int					get_value_from_stack(t_stack **a, int index);
int					push(t_stack **a, t_stack **b);
int					swap(t_stack **a);
int					rotate(t_stack **a);
int					reverse(t_stack **a);
int					get_size(t_stack *a);
int					print_usage(void);
int					get_max(t_stack *a);
int					check_duplicate(t_stack **a);
int					checking_args(char *str);
int					print_usage(void);
int					rot_last(t_stack *a);

#endif
