/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:26:41 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/28 20:35:39 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_median(t_stack **a, int high, int asc)
{
	t_stack	*iter_tmp;
	t_stack	*iter_a;
	t_stack	*tmp;
	int		tmp2;
	int		size;

	tmp = copy_stack(*a, high + 1);
	quicksort(&tmp, 0, high);
	size = high + 1;
	if (asc)
		tmp2 = get_value_from_stack(&tmp, size / 2);
	else
	{
		if (get_size(tmp) % 2 == 0)
			tmp2 = get_value_from_stack(&tmp, size / 2 - 1);
		else
			tmp2 = get_value_from_stack(&tmp, size / 2);
	}
	free_list(&tmp);
	return (tmp2);
}

int			sort_three_ascending(t_stack **a, char **res)
{
	int		first;
	int		secon;
	int		third;

	first = (*a)->value;
	secon = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > third && third > secon)
		get_size(*a) == 3 ? rotate_(a, res) : swap_(a, res) && rotate_(a, res)
			&& swap_(a, res) && reverse_(a, res);
	else if (first > secon && third < secon)
		get_size(*a) == 3 ? rotate_(a, res) && swap_(a, res) : swap_(a, res)
	&& rotate_(a, res) && swap_(a, res) && reverse_(a, res) && swap_(a, res);
	else if (secon > first && secon > third && first < third)
		get_size(*a) == 3 ? reverse_(a, res) && swap_(a, res) : rotate_(a, res)
			&& swap_(a, res) && reverse_(a, res);
	else if (secon > first && secon > third && first > third)
		get_size(*a) == 3 ? reverse_(a, res) : rotate_(a, res) && swap_(a, res)
			&& reverse_(a, res) && swap_(a, res);
	else if (third > first && third > secon && first > secon)
		swap_(a, res);
	return (1);
}

int			sort_three_descending(t_stack **a, char **res)
{
	int		first;
	int		secon;
	int		third;

	first = (*a)->value;
	secon = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > third && third > secon)
		get_size(*a) == 3 ? reverse_(a, res) && swap_(a, res) : rotate_(a, res)
			&& swap_(a, res) && reverse_(a, res);
	else if (secon > first && secon > third && first < third)
		get_size(*a) == 3 ? rotate_(a, res) : swap_(a, res) && rotate_(a, res)
			&& swap_(a, res) && reverse_(a, res);
	else if (secon > first && secon > third && first > third)
		swap_(a, res);
	else if (third > first && third > secon && first > secon)
		get_size(*a) == 3 ? reverse_(a, res) : rotate_(a, res) && swap_(a, res)
			&& reverse_(a, res) && swap_(a, res);
	else if (third > first && third > secon && first < secon)
		get_size(*a) == 3 ? swap_(a, res) && reverse_(a, res) : swap_(a, res)
	&& rotate_(a, res) && swap_(a, res) && reverse_(a, res) && swap_(a, res);
	return (1);
}

void		quicksort_descending(t_stack **a, t_stack **b, int high, char **res)
{
	int		pivotal;
	int		size[2];

	if (high <= 1 || (high == 2 && ((*a)->value < (*a)->next->value ?
	swap_(a, res) : 1)) || (high == 3 && sort_three_descending(a, res)))
		return ;
	size[0] = 0;
	size[1] = 0;
	pivotal = find_median(a, high - 1, 1);
	while (high--)
		if ((*a)->value > pivotal && ++(size[1]))
			push_(a, b, res);
		else if ((*a)->value == pivotal && push_(a, b, res) >= 0)
			rotate_(b, res);
		else if (++(size[0]))
			rotate_(a, res);
	high = size[0];
	if (get_size(*a) > high)
		while (high--)
			reverse_(a, res);
	quicksort_descending(a, b, size[0], res);
	reverse_(b, res) && push_(b, a, res);
	quicksort_ascending(b, a, size[1], res);
	while ((size[1])--)
		push_(b, a, res);
	**res = 0;
}

void		quicksort_ascending(t_stack **a, t_stack **b, int high, char **res)
{
	int		pivotal;
	int		size[2];

	if (high <= 1 || (high == 2 && ((*a)->value > (*a)->next->value ?
	swap_(a, res) : 1)) || (high == 3 && sort_three_ascending(a, res)))
		return ;
	size[0] = 0;
	size[1] = 0;
	pivotal = find_median(a, high - 1, 0);
	while (high--)
		if ((*a)->value < pivotal && ++(size[1]))
			push_(a, b, res);
		else if ((*a)->value == pivotal && push_(a, b, res) >= 0)
			rotate_(b, res);
		else if (++(size[0]))
			rotate_(a, res);
	high = size[0];
	if (get_size(*a) > high)
		while (high--)
			reverse_(a, res);
	quicksort_ascending(a, b, size[0], res);
	reverse_(b, res) && push_(b, a, res);
	quicksort_descending(b, a, size[1], res);
	while ((size[1])--)
		push_(b, a, res);
	**res = 0;
}
