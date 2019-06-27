/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:58:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/27 15:56:24 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*new_elem_of_stack(int value, int stack)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	(*new).value = value;
	(*new).index = stack;
	(*new).next = NULL;
	(*new).prev = NULL;
	return (new);
}

int			is_sorted(t_stack *a)
{
	t_stack *iter;

	iter = a;
	if (iter && iter->next)
	{
		while (iter->next)
		{
			if (iter->value >= iter->next->value)
				return (0);
			iter = iter->next;
		}
	}
	return (1);
}

void		labeler(t_stack **a, int size)
{
	t_stack	*iter_tmp;
	t_stack	*iter_a;
	t_stack	*tmp;

	tmp = copy_stack(*a, size);
	quicksort(&tmp, 0, size - 1);
	iter_tmp = tmp;
	iter_tmp->index = 0;
	while (iter_tmp)
	{
		iter_a = *a;
		while (iter_a->value != iter_tmp->value)
			iter_a = iter_a->next;
		iter_a->index = iter_tmp->index + 1;
		iter_tmp = iter_tmp->next;
	}
}

int			print_usage(void)
{
	ft_printf("Usage: Give a numeric sequence that needs to be sorted\n       ");
	ft_printf("[-v] displaing stacks during the processing\n       ");
	ft_printf("[-c] dispalaying with colour\n");
	return (1);
}


int			fd_collector(char **argv, size_t *flags)
{
	int		fd;

	fd = open(*argv, O_RDONLY);
	if (fd > 0)
		*flags |= fd;
	else
		error_handler(0, 0);
	return (1);
}

void		error_handler(int code, int none)
{
	if (code)
		print_usage();
	else if (!none)
		ft_printf("Error\n");
	exit(1);
}

int				get_max(t_stack *a)
{
	t_stack		*iter;
	int			max;

	if (a)
	{
		iter = a;
		max = iter->index;
		while (iter)
		{
			if (iter->index > max)
				max = iter->index;
			iter = iter->next;
		}
		return (max);
	}
	return (0);
}
