/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   available_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:41:12 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/26 20:21:09 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ss(t_stack **a, char **res)
{
	**res = 's';
	*res += 1;
	**res = 's';
	*res += 1;
	**res = '\n';
	*res += 1;
	return (0);
}

int 		rr(t_stack **a, char **res)
{
	**res = 'r';
	*res += 1;
	**res = 'r';
	*res += 1;
	**res = '\n';
	*res += 1;
	return (0);
}

int			rrr(t_stack **a, char **res)
{
	**res = 'r';
	*res += 1;
	**res = 'r';
	*res += 1;
	**res = 'r';
	*res += 1;
	**res = '\n';
	*res += 1;
	return (0);
}

int 			push_(t_stack **a, t_stack **b, char **res)
{
	t_stack *tmp;
	if (*a)
	{
		push_optimizer(a, res);
		tmp = *a;
		*a = tmp->next;
		*a ? (*a)->prev = NULL : 0;
		tmp->next = *b;
		tmp->stack == 0 ? tmp->stack = 1 : (tmp->stack = 0);
		*b ? (*b)->prev = tmp : 0;
		*b = tmp;
		return (1);
	}
	return (0);
}


int			swap_(t_stack **a, char **res)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		swap_optimizer(a, res);
		tmp = (*a)->next;
		tmp->prev = *a;
		(*a)->next = tmp->next;
		(*a)->prev = tmp;
		tmp->next = *a;
		tmp->prev = NULL;
		*a = tmp;
		return (1);
	}
	return (0);
}

int			rotate_(t_stack **a, char **res)
{
	t_stack *tmp;
	t_stack *iter;

	if (*a && (*a)->next)
	{
		rotate_optimizer(a, res);
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		iter = *a;
		while ((*iter).next)
			iter = (*iter).next;
		(*iter).next = tmp;
		(*tmp).next = NULL;
		(*tmp).prev = iter;
		return (1);
	}
	return (0);
}

int			reverse_(t_stack **a, char **res)
{
	t_stack *iter;

	if (*a && (*a)->next)
	{
		reverse_optimizer(a, res);
		iter = *a;
		while (iter->next->next)
			iter = iter->next;
		iter->next->next = *a;
		(*a)->prev = iter->next;
		*a = iter->next;
		(*a)->prev = NULL;
		iter->next = NULL;
		return (1);
	}
	return (0);
}