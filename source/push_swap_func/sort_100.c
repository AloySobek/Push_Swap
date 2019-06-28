/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:55:48 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/28 22:07:14 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_highest(t_stack *a, int size)
{
    int	high;

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

int		find_lowest(t_stack *a, int size)
{
	int low;

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

int		find_first(t_stack *a)
{
	if (a)
	{
		if (a->next)
			return (a->next->index);
		while (a->prev)
			a = a->next;
		return (a->index);
	}
	return (0);
}

int		find_last(t_stack *a)
{
	if (a)
	{
		if (a->prev)
			return (a->prev->index);
		while (a->next)
			a = a->next;
		return (a->index);
	}
	return (0);
}

int    where_to(t_stack *s, int place)
{
    int			f;
	int			i;

	i = 0;
	f = 1;
	while (s && (s->index == place ? !(f = 0) : 1) && ((f ? --i : ++i) || 1))
		s = s->next;
    return (i);
}

void    sort_back(t_stack **a, t_stack **b, int size, char **act)
{
    int start;
    int thend;

    start = find_highest(*b, size);
    thend = find_lowest(*b, size);
    while (thend <= start)
    {
        while ((*b)->index != start && (*b)->index != start - 1)
            if ((*b)->index == thend || (*b)->index == thend + 1)
            {
                if ((*b)->index == thend)
                    thend += 1 + (find_last(*a) == thend + 1);
                push_(b, a, act);
                rotate_(a, act);
            }
            else if (where_to(*b, start) >= 0)
                rotate_(b, act);
            else
                reverse_(b, act);
        push_(b, a, act);
        while ((*a)->index == start ||
            find_last(*a) == start || (*a)->next->index == start)
            --start;
        if ((*a)->index > (*a)->next->index)
            swap_(a, act);
    }
    while (find_last(*a) < (*a)->next->index)
    {
        reverse_(a, act);
        if ((*a)->index > (*a)->next->index)
            swap_(a, act);
    }
}

void    sort_100(t_stack **a, t_stack **b, int size, char **act)
{
    int pivot;
    int count;
    int check_p = 0;

    if (size == 2 && (*a)->index > (*a)->next->index)
        swap_(a, act);
    else if (size == 3)
        sort_three_ascending(a, act);
    else if (size > 3)
    {
        pivot = find_lowest(*a, size) + size / 2 + size % 2;
        count = 0;
        while (count * 2 < size || check_p != 2)
        {
            if ((*a)->index < pivot)
            {
                push_(a, b, act);
                ++count;
            }
            else if ((*a)->index == pivot)
            {
                push_(a, b, act);
                rotate_(b, act);
                ++check_p;
            }
            else if ((*a)->index == pivot + 1)
            {
                push_(a, b, act);
                rotate_(b, act);
                ++check_p;
            }
            else
                rotate_(a, act);
        }
        sort_100(a, b, size - count - 2, act);
        reverse_(b, act);
        reverse_(b, act);
        push_(b, a, act);
        push_(b, a, act);
        if ((*a)->index > (*a)->next->index)
            swap_(a, act);
        sort_back(a, b, count, act);
    }
}
