/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:58:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 18:47:57 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_list(t_stack **a)
{
	if (*a)
	{
		free_list(&(*a)->next);
		free(*a);
		*a = NULL;
	}
}

t_stack		*new_elem_of_stack(int value, int index)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		error_handler(0, 0);
	new->value = value;
	new->index = index;
	new->stack = 0;
	new->next = NULL;
	new->prev = NULL;
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

int			get_size(t_stack *a)
{
	int		count;

	count = 0;
	if (a)
	{
		if ((a->next) == NULL)
			while (a)
			{
				++count;
				a = a->prev;
			}
		else
			while (a)
			{
				++count;
				a = a->next;
			}
	}
	return (count);
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
	free_list(&tmp);
}
