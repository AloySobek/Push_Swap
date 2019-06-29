/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   available_acts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:41:12 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 21:36:25 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			push_(t_stack **a, t_stack **b, char **res)
{
	t_stack	*tmp;

	if (a && *a)
	{
		push_optimizer((*a)->stack, res);
		res = NULL;
		tmp = *a;
		*a = tmp->next;
		*a ? (*a)->prev = NULL : 0;
		tmp->next = *b;
		if (tmp->stack == 0)
			tmp->stack = 1;
		else
			tmp->stack = 0;
		*b ? (*b)->prev = tmp : 0;
		*b = tmp;
		(*b)->prev = NULL;
	}
	return (1);
}

int			swap_(t_stack **a, char **res)
{
	t_stack *tmp;

	if (a && *a && (*a)->next)
	{
		swap_optimizer((*a)->stack, res);
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

int			rotate_(t_stack **a, char **res)
{
	t_stack *tmp;
	t_stack *iter;

	if (a && *a && (*a)->next)
	{
		rotate_optimizer((*a)->stack, res);
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		iter = *a;
		while (iter->next)
			iter = iter->next;
		iter->next = tmp;
		tmp->next = NULL;
		tmp->prev = iter;
	}
	return (1);
}

int			reverse_(t_stack **a, char **res)
{
	t_stack *iter;

	if (a && *a && (*a)->next)
	{
		reverse_optimizer((*a)->stack, res);
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
