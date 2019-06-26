/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:26:41 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/26 22:02:20 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_worst_descending(t_stack **a, char **res)
{
	if (get_size(*a) == 3)
	{
		swap_(a, res);
		reverse_(a, res);
	}
	else
	{
		swap_(a, res);
		rotate_(a, res);
		swap_(a, res);
		reverse_(a, res);
		swap_(a, res);
	}
}

void	sort_worst_ascending(t_stack **a, char **res)
{
	if (get_size(*a) == 3)
	{
		rotate_(a, res);
		swap_(a, res);
	}
	else
	{
		swap_(a, res);
		rotate_(a, res);
		swap_(a, res);
		reverse_(a, res);
		swap_(a, res);
	}
}

int		sort_three(t_stack **a, char **res)
{
	int one;
	int two;
	int three;

	one = (*a)->value;
	two = (*a)->next->value;
	three = (*a)->next->next->value;
	if (one > two && one > three && two < three)
	{
		if (get_size(*a) == 3)
			rotate_(a, res);
		else
		{
			swap_(a, res);
			rotate_(a, res);
			swap_(a, res);
			reverse_(a, res);
		}
	}
	else if (one > two && one > three && two > three)
		sort_worst_ascending(a, res);
	else if (two > one && two > three && one < three)
	{
		if (get_size(*a) == 3)
		{
			reverse_(a, res);
			swap_(a, res);
		}
		else
		{
			rotate_(a, res);
			swap_(a, res);
			reverse_(a, res);
		}
	}
	else if (two > one && two > three && one > three)
	{
		if (get_size(*a) == 3)
			reverse_(a, res);
		else
		{
			rotate_(a, res);
			swap_(a, res);
			reverse_(a, res);
			swap_(a, res);
		}
	}
	else if (three > one && three > two && one > two)
		swap_(a, res);
	return (1);
}

int			sort_three_(t_stack **a, char **res)
{
	int one;
	int two;
	int three;

	one = (*a)->value;
	two = (*a)->next->value;
	three = (*a)->next->next->value;
	if (one > two && one > three && two < three)
	{
		if (get_size(*a) == 3)
		{
			reverse_(a, res);
			swap_(a, res);
		}
		else
		{
			rotate_(a, res);
			swap_(a, res);
			reverse_(a, res);
		}
	}
	else if (two > one && two > three && one < three)
	{
		if (get_size(*a) == 3)
			rotate_(a, res);
		else
		{
			swap_(a, res);
			rotate_(a ,res);
			swap_(a, res);
			reverse_(a, res);
		}
	}
	else if (two > one && two > three && one > three)
		swap_(a, res);
	else if (three > one && three > two && one > two)
	{
		if (get_size(*a) == 3)
			reverse_(a, res);
		else
		{
			rotate_(a, res);
			swap_(a, res);
			reverse_(a, res);
			swap_(a, res);
		}
	}
	else if (three > one && three > two && one < two)
		sort_worst_descending(a, res);
	return (1);
}

void	quicksort_descending(t_stack **a, t_stack **b, int high, char **res)
{
	int size[2];
	t_stack *pivot;
	int		test;

	if (high <= 1 || (high == 2 && ((*a)->value < (*a)->next->value ?
	swap_(a, res) : 1)) || (high == 3 && sort_three_(a, res)))
		return ;
	size[0] = 0;
	size[1] = 0;
	test = 0;
	pivot  = find_median(a, high - 1, 1);
	while (high--)
	{
		if ((*a)->value > pivot->value && ++(size[1]))
			push_(a, b, res);
		else
			if (((*a)->value == pivot->value || (*a)->index == (pivot->index + 1)) && push_(a, b, res) >= 0)
			{
				rotate_(b, res);
				++test;
			}
			else if (++(size[0]))
				rotate_(a, res);
	}
	high = size[0];
	if (get_size(*a) > high)
		while (high--)
			reverse_(a, res);
	quicksort_descending(a, b, size[0], res);
	while (test--)
		reverse_(b, res) && push_(b, a, res);
	quicksort_ascending(b, a, size[1], res);
	while ((size[1])--)
		push_(b, a, res);
}

void	quicksort_ascending(t_stack **a, t_stack **b, int high, char **res)
{
	int		size[2];
	t_stack	*pivot;
	int		test;

	if (high <= 1 || (high == 2 && ((*a)->value > (*a)->next->value ?
	swap_(a, res) : 1)) || (high == 3 && sort_three(a, res)))
		return ;
	size[0] = 0;
	size[1] = 0;
	test = 0;
	pivot  = find_median(a, high - 1, 0);
	while (high--)
	{
		if ((*a)->value < pivot->value && ++(size[1]))
			push_(a, b, res);
		else
			if (((*a)->index == pivot->index || (*a)->index == (pivot->index - 1)) && push_(a, b, res) >= 0)
			{
				ft_printf("\n%d\n%d\n__", (*a)->index, (*a)->value);
				rotate_(b, res);
				++test;
				ft_printf("|%d|\n", test);
			}
			else if (++(size[0]))
				rotate_(a, res);
	}
	high = size[0];
	if (get_size(*a) > high)
		while (high--)
			reverse_(a, res);
	quicksort_ascending(a, b, size[0], res);
	while (test--)
		reverse_(b, res) && push_(b, a, res);
	quicksort_descending(b, a, size[1], res);
	while ((size[1])--)
		push_(b, a, res);
}