/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:57:27 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/26 22:01:58 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_size(t_stack *a)
{
	int count;
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

t_stack			*get_elem_from_stack(t_stack **a, int index)
{
	t_stack		*iter;

	iter = *a;
	if (iter)
	{
		while (index--)
			iter = iter->next;
		return (iter);
	}
	return (NULL);
}

int 			get_value_from_stack(t_stack **a, int index)
{
	t_stack *iter;

	iter = *a;
	if (iter)
	{
		while (index--)
			iter = iter->next;
		return (iter->value);
	}
	return (0);
}

void			swap_for_quicksort(t_stack **a, int i, int j)
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

int				partition(t_stack **a, int low, int high)
{
	int i;
	int j;
	int pivot;

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

void			quicksort(t_stack **a, int low, int high)
{
	int p;

	if (low < high)
	{
		p = partition(a, low, high);
		quicksort(a, low, p - 1);
		quicksort(a, p + 1, high);
	}
}

t_stack			*copy_stack(t_stack *a, int high)
{
	t_stack *tmp;
	t_stack *ret;

	tmp = new_elem_of_stack(0, 0);
	ret = tmp;
	while (high--)
	{
		tmp->value = a->value;
		tmp->prev = a->prev;
		a = a->next;
		high != 0 ? tmp->next = new_elem_of_stack(0, tmp->index + 1) : 0;
		high != 0 ? tmp = tmp->next : 0;
	}
	tmp->next = NULL;
	return (ret);
}

t_stack			*find_median(t_stack **a, int high, int asc)
{
	int size;
	t_stack *tmp;
	t_stack *iter_tmp;
	t_stack *iter_a;

	tmp = copy_stack(*a, high + 1);
	quicksort(&tmp, 0, high);
	labeler(&tmp, high + 1);
	size = high + 1;
	if (asc)
		return (get_elem_from_stack(&tmp, size / 2));
	else
	{
		if (get_size(tmp) % 2 == 0)
			return (get_elem_from_stack(&tmp, size / 2 - 1));
		else
			return (get_elem_from_stack(&tmp, size / 2));
	}
}
