/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   available_acts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:57:35 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 21:35:32 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*a)
	{
		tmp = *a;
		*a = tmp->next;
		*a ? (*a)->prev = NULL : 0;
		tmp->next = *b;
		*b ? (*b)->prev = tmp : 0;
		*b = tmp;
		(*b)->prev = NULL;
	}
	return (1);
}

int			swap(t_stack **a)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next ? tmp->next->prev = *a : 0;
		(*a)->prev = tmp;
		tmp->next = *a;
		tmp->prev = NULL;
		*a = tmp;
	}
	return (1);
}

int			rotate(t_stack **a)
{
	t_stack *tmp;
	t_stack *iter;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		iter = *a;
		while (iter->next)
			iter = (*iter).next;
		iter->next = tmp;
		tmp->next = NULL;
		tmp->prev = iter;
	}
	return (1);
}

int			reverse(t_stack **a)
{
	t_stack *iter;

	if (*a && (*a)->next)
	{
		iter = *a;
		while (iter->next->next)
			iter = iter->next;
		iter->next->next = *a;
		(*a)->prev = iter->next;
		*a = iter->next;
		(*a)->prev = NULL;
		iter->next = NULL;
	}
	return (1);
}

int			get_max(t_stack *a)
{
	t_stack	*iter;
	int		max;

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
