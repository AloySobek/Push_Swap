/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:55:48 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 21:38:47 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest(t_stack *a, int size)
{
	int		high;

	high = 0;
	if (a)
	{
		high = a->index;
		while (size--)
		{
			a->index > high ? high = a->index : 0;
			a = a->next;
		}
	}
	return (high);
}

static int	find_lowest(t_stack *a, int size)
{
	int		low;

	low = 0;
	if (a)
	{
		low = a->index;
		while (size--)
		{
			a->index < low ? low = a->index : 0;
			a = a->next;
		}
	}
	return (low);
}

static int	where_to(t_stack *s, int place)
{
	int		f;
	int		i;

	i = 0;
	f = 1;
	while (s && (s->index == place ? !(f = 0) : 1) && ((f ? --i : ++i) || 1))
		s = s->next;
	return (i);
}

static void	sort_back(t_stack **a, t_stack **b, int size, char **act)
{
	int		beg;
	int		end;

	beg = find_highest(*b, size);
	end = find_lowest(*b, size);
	while (end <= beg)
	{
		while ((*b)->index != beg && (*b)->index != beg - 1)
			if ((*b)->index == end || (*b)->index == end + 1)
			{
				(*b)->index == end ? end += 1 + (rot_last(*a) == end + 1) : 0;
				push_(b, a, act) && rotate_(a, act);
			}
			else
				where_to(*b, beg) >= 0 ? rotate_(b, act) : reverse_(b, act);
		push_(b, a, act);
		while ((*a)->index == beg || (*a)->next->index == beg
		|| rot_last(*a) == beg)
			--beg;
		(*a)->index > (*a)->next->index ? swap_(a, act) : 0;
	}
	while (rot_last(*a) < (*a)->next->index && reverse_(a, act) >= 0)
		(*a)->index > (*a)->next->index ? swap_(a, act) : 0;
}

void		sort_100(t_stack **a, t_stack **b, int size, char **act)
{
	int		pivot;
	int		count;
	int		check;

	if (size <= 1 || (size == 2 && ((*a)->index > (*a)->next->index ?
	swap_(a, act) : 1)) || (size == 3 && sort_three_ascending(a, act)))
		return ;
	check = 0;
	count = 0;
	pivot = find_lowest(*a, size) + size / 2 + size % 2;
	while (count * 2 < size || check != 2)
		if ((*a)->index < pivot && ++count)
			push_(a, b, act);
		else if ((*a)->index == pivot && ++check)
			push_(a, b, act) && rotate_(b, act);
		else if ((*a)->index == pivot + 1 && ++check)
			push_(a, b, act) && rotate_(b, act);
		else
			rotate_(a, act);
	sort_100(a, b, size - count - 2, act);
	reverse_(b, act) && reverse_(b, act);
	push_(b, a, act) && push_(b, a, act);
	(*a)->index > (*a)->next->index ? swap_(a, act) : 0;
	sort_back(a, b, count, act);
}
