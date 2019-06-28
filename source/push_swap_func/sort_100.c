/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:55:48 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/28 15:38:25 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_highest(t_stack *a, int size)
{
    int	high;

    high = 0;
    if (a)
	{
        high = a->value;
		while (size--)
		{
			a->value > high ? high = a->value : 0;
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
		low = a->value;
		while (size--)
		{
			a->value < low ? low = a->value : 0;
			a = a->next;
		}
	}

}

void    sort_back(t_stack **a, t_stack **b, int size, char **act)
{
    int start;
    int thend;

    start = find_highest(*b, size);
    thend = find_lowest(*b, size);
    while (thend <= start)
    {
        while ((*b)->value != start && (*b)->value != start - 1)
            if ((*b)->value == thend || (*b)->value == thend + 1)
            {
                if ((*b)->value == thend)
                    thend += 1 + ((*a)->prev->value == thend + 1);
                push_(b, a, act);
                rotate_(a, act);
            }
            else if (where_to(*b, start) >= 0)
                rotate_(b, act);
            else
                reverse_(b, act);
        push_(b, a, act);
        while ((*a)->value == start ||
            (*a)->prev->value == start || (*a)->next->value == start)
            --start;
        if ((*a)->value > (*a)->next->value)
            swap_(a, act);
    }
    while ((*a)->prev->value < (*a)->next->value)
    {
        reverse_(a, act);
        if ((*a)->value > (*a)->next->value)
            swap_(a, act);
    }
}

void    sort_100(t_stack **a, t_stack **b, int size, int **coms)
{
    int pivot;
    int count;
    int check_p = 0;

    if (size == 2 && (*a)->place > (*a)->right->place)
        swap(a, coms);
    else if (size == 3)
        solve_3(a, coms);
    else if (size > 3)
    {
        pivot = find_lowest(*a, size) + size / 2 + size % 2;
        count = 0;
        while (count * 2 < size || check_p != 2)
        {
            if ((*a)->place < pivot)
            {
                push(a, b, coms);
                ++count;
            }
            else if ((*a)->place == pivot)
            {
                push(a, b, coms);
                rotate(b, coms);
                ++check_p;
            }
            else if ((*a)->place == pivot + 1)
            {
                push(a, b, coms);
                rotate(b, coms);
                ++check_p;
            }
            else
                rotate(a, coms);
        }
        sort_100(a, b, size - count - 2, coms);
        reverse(b, coms);
        reverse(b, coms);
        push(b, a, coms);
        push(b, a, coms);
        if ((*a)->place > (*a)->right->place)
            swap(a, coms);
        sort_back(a, b, count, coms);
    }
}

static int    where_to(t_stack *s, int place)
{
    t_stack    *rotate;
    int        direction;

    direction = 0;
    rotate = s;
    while (rotate->place != place)
    {
        rotate = rotate->right;
        ++direction;
    }
    rotate = s;
    while (rotate->place != place)
    {
        rotate = rotate->left;
        --direction;
    }
    return (direction);
}