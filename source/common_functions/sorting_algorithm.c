/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:57:27 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/28 17:30:45 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_value_from_stack(t_stack **a, int index)
{
	t_stack	*iter;
	int		tmp;

	iter = *a;
	if (iter)
	{
		while (index--)
			iter = iter->next;
		tmp = iter->value;
		return (tmp);
	}
	return (0);
}

void		swap_for_quicksort(t_stack **a, int i, int j)
{
	t_stack *iter;
	t_stack *tmp;
	int		tmp2;

	iter = *a;
	while (iter)
	{
		if (iter->index == i)
		{
			tmp = iter;
			break ;
		}
		iter = iter->next;
	}
	while (iter)
	{
		if (iter->index == j)
		{
			tmp2 = iter->value;
			iter->value = tmp->value;
			tmp->value = tmp2;
			break ;
		}
		iter = iter->next;
	}
}

int			partition(t_stack **a, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	pivot = get_value_from_stack(a, (low + high) / 2);
	i = low;
	j = high;
	while (1)
	{
		while (get_value_from_stack(a, i) < pivot)
			++i;
		while (get_value_from_stack(a, j) > pivot)
			--j;
		if (i >= j)
			return (j);
		swap_for_quicksort(a, i, j);
	}
}

void		quicksort(t_stack **a, int low, int high)
{
	int		p;

	if (low < high)
	{
		p = partition(a, low, high);
		quicksort(a, low, p - 1);
		quicksort(a, p + 1, high);
	}
}

t_stack		*copy_stack(t_stack *a, int high)
{
	t_stack *prev;
	t_stack *tmp;
	t_stack *ret;

	tmp = new_elem_of_stack(0, 0);
	ret = tmp;
	while (high--)
	{
		if (a)
		{
			tmp->value = a->value;
			tmp->stack = a->stack;
			a = a->next;
			tmp->next = new_elem_of_stack(0, tmp->index + 1);
			prev = tmp;
			tmp = tmp->next;
			tmp->prev = prev;
		}
	}
	tmp->prev->next = NULL;
	free(tmp);
	return (ret);
}
