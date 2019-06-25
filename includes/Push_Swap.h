/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:46:30 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/25 20:23:11 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFF_SIZE 30

# include "libft.h"
# include <fcntl.h>

typedef enum		e_stacks
{
	A, B, I
}					t_stacks;


typedef struct		s_mylist
{
	int				fd;
	char			*inter_str;
	struct s_mylist	*next;
}					t_mylist;

typedef struct		s_stack
{
	int				value;
	int 			index;
	int				stack;
	struct s_stack	*next;
	struct s_stack	*prev;
}                   t_stack;

# define			DEB	0x8000000
# define			COL	0x10000000
# define			INT 0x20000000
# define			DES	0x40000000

# define			_FILE__ (*flags << 40) >> 40
# define			_TIME__ (*flags >> 32)

t_stack				*new_elem_of_stack(int value, int index);
t_stack				*copy_stack(t_stack *a, int high);
void				labeler(t_stack **a, int size);
void				error_handler(int code, int none);
void				swap_for_quicksort(t_stack **a, int i, int j);
void				quicksort_ascending(t_stack **a, t_stack **b, int high, char **res);
void				quicksort(t_stack **a, int low, int high);
int					is_sorted(t_stack *a);
int					partition(t_stack **a, int low, int high);
int					get_value_from_stack(t_stack **a, int index);
int					get_next_line(const int fd, char **line);
int					push(t_stack **a, t_stack **b);
int					swap(t_stack **a);
int					rotate(t_stack **a);
int					rotate_reverse(t_stack **a);
int					get_size(t_stack *a);
int					print_usage(void);
int					ft_printf(const char *format, ...);
int					find_median(t_stack *a, int high, int asc);
int					checking_args(int *argc, char ***argv, size_t *flags);

#endif
