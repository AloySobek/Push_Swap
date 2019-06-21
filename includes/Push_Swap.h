/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:46:30 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/21 18:16:08 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFF_SIZE 30

# include "libft.h"

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
	struct s_stack	*next;
	struct s_stack	*prev;
}                   t_stack;

# define			COL	0x10000000
# define			GRE	0x20000000
# define			LIF	0x40000000
# define			OUF	0x80000000

void				quicksort_ascending(t_stack **a, t_stack **b, int high, char **res);
int					get_next_line(const int fd, char **line);
int					push(t_stack **a, t_stack **b);
int					swap(t_stack **a);
int					rotate(t_stack **a);
int					rotate_reverse(t_stack **a);
int					ft_printf(const char *format, ...);

#endif
