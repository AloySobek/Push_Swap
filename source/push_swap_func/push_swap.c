/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/23 19:35:43 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Push_Swap.h"

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
		if ((*a)->index == 0)
		{
			if (*((*res) - 2) == 'a' && *((*res) - 4) == '\n' && *((*res) - 3) == 'p')
				*res -= 3;
			else
			{
				**res = 'p';
				*res += 1;
				**res = 'b';
				*res += 1;
				**res = '\n';
				*res += 1;
			}
		}
		else
		{
			if (*((*res) - 2) == 'b' && *((*res) - 4) == '\n' && *((*res) - 3) == 'p')
				*res -= 3;
			else
			{
				**res = 'p';
				*res += 1;
				**res = 'a';
				*res += 1;
				**res = '\n';
				*res += 1;
			}
		}
		tmp = *a;
		*a = tmp->next;
		*a ? (*a)->prev = NULL : 0;
		tmp->next = *b;
		tmp->index == 0 ? tmp->index = 1 : (tmp->index = 0);
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
		if ((*a)->index == 0)
		{
			if (*(*res - 2) == 'a' && *(*res - 4) == '\n' && *(*res - 3) == 's')
				*res -= 3;
			else
			{
				if (*(*res - 2) == 'b' && *(*res - 4) == '\n' && *(*res - 3) == 's')
				{
					*res -= 3;
					ss(a, res);
				}
				else
				{
					**res = 's';
					*res += 1;
					**res = 'a';
					*res += 1;
					**res = '\n';
					*res += 1;
				}
			}
		}
		else
		{
			if (*(*res - 2) == 'b' && *(*res - 4) == '\n' && *(*res - 3) == 's')
				*res -= 3;
			else
			{
				if (*(*res - 2) == 'a' && *(*res - 4) == '\n' && *(*res - 3) == 's')
				{
					*res -= 3;
					ss(a, res);
				}
				else
				{
					**res = 's';
					*res += 1;
					**res = 'b';
					*res += 1;
					**res = '\n';
					*res += 1;
				}
			}
		}
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
		if ((*a)->index == 0)
		{
			if (*(*res - 2) == 'a' && *(*res - 4) == 'r' && *(*res - 3) == 'r')
				*res -= 4;
			else
			{
				if (*(*res - 2) == 'b' && *(*res - 4) == '\n' && *(*res - 3) == 'r')
				{
					*res -= 3;
					rr(a, res);
				}
				else
				{
					**res = 'r';
					*res += 1;
					**res = 'a';
					*res += 1;
					**res = '\n';
					*res += 1;
				}
			}
		}
		else
		{
			if (*(*res - 2) == 'b' && *(*res - 4) == 'r' && *(*res - 3) == 'r')
				*res -= 4;
			else
			{
				if (*(*res - 2) == 'a' && *(*res - 4) == '\n' && *(*res - 3) == 'r')
				{
					*res -= 3;
					rr(a, res);
				}
				else
				{
					**res = 'r';
					*res += 1;
					**res = 'b';
					*res += 1;
					**res = '\n';
					*res += 1;
				}
			}
		}
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

int			rotate_reverse_(t_stack **a, char **res)
{
	t_stack *iter;

	if (*a && (*a)->next)
	{
		if ((*a)->index == 0)
		{
			if (*(*res - 2) == 'a' && *(*res - 4) == '\n' && *(*res - 3) == 'r')
				*res -= 3;
			else
			{
				if (*(*res - 2) == 'b' && *(*res - 5) == '\n' && *(*res - 3) == 'r' && *(*res - 4) == 'r')
				{
					*res -= 4;
					rrr(a, res);
				}
				else
				{
					**res = 'r';
					*res += 1;
					**res = 'r';
					*res += 1;
					**res = 'a';
					*res += 1;
					**res = '\n';
					*res += 1;
				}
			}
		}
		else
		{
			if (*(*res - 2) == 'b' && *(*res - 4) == '\n' && *(*res - 3) == 'r')
				*res -= 3;
			else
			{
				if (*(*res - 2) == 'a' && *(*res - 5) == '\n' && *(*res - 3) == 'r' && *(*res - 4) == 'r')
				{
					*res -= 4;
					rrr(a, res);
				}
				else
				{
					**res = 'r';
					*res += 1;
					**res = 'r';
					*res += 1;
					**res = 'b';
					*res += 1;
					**res = '\n';
					*res += 1;
				}
			}
		}
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

t_stack			*new_elem_of_stack(int value, int index)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	(*new).value = value;
	(*new).index = index;
	(*new).next = NULL;
	(*new).prev = NULL;
	return (new);
}

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

int 			get_value_from_stack(t_stack **a, int index)
{
	t_stack *iter;
	int size;

	iter = *a;
	if (iter)
	{
		while (index--)
			iter = iter-> next;
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

int		find_median(t_stack *a, int high, int asc)
{
	int size;
	t_stack *tmp;

	tmp = copy_stack(a, high + 1);
	quicksort(&tmp, 0, high);
	size = high + 1;
	if (asc)
		return (get_value_from_stack(&tmp, size / 2));
	else
	{
		if (get_size(tmp) % 2 == 0)
			return (get_value_from_stack(&tmp, size / 2 - 1));
		else
			return (get_value_from_stack(&tmp, size / 2));
	}
}

int		is_sorted(t_stack *a)
{
	a = a->next;
	while (a)
	{
		if (a->value <= a->prev->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int		third_sort(t_stack **a, char **res)
{
	int one;
	int two;
	int three;

	one = (*a)->value;
	two = (*a)->next->value;
	three = (*a)->next->next->value;
	if (one > two && one > three && two < three)
		if (get_size(*a) == 3)
			swap_(a, res);
		else
		{
			swap_(a, res);
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
		}
	else if (one > two && one > three && two > three)
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
			rotate_reverse_(a, res);
			swap_(a, res);
		}
	else if (two > one && two > three && one < three)
		if (get_size(*a) == 3)
		{
			rotate_reverse_(a, res);
			swap_(a, res);
		}
		else
		{
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
		}
	else if (two > one && two > three && one > three)
		if (get_size(*a) == 3)
			rotate_reverse_(a, res);
		else
		{
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
			swap_(a, res);
		}
	else if (three > one && three > two && one > two)
		swap_(a, res);
	return (1);
}

int			third_sort_(t_stack **a, char **res)
{
	int one;
	int two;
	int three;

	one = (*a)->value;
	two = (*a)->next->value;
	three = (*a)->next->next->value;
	if (one > two && one > three && two < three)
		if (get_size(*a) == 3)
		{
			rotate_reverse_(a, res);
			swap_(a, res);
		}
		else
		{
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
		}
	else if (two > one && two > three && one < three)
		if (get_size(*a) == 3)
			rotate_(a, res);
		else
		{
			swap_(a, res);
			rotate_(a ,res);
			swap_(a, res);
			rotate_reverse_(a, res);
		}
	else if (two > one && two > three && one > three)
		swap_(a, res);
	else if (three > one && three > two && one > two)
		if (get_size(*a) == 3)
			rotate_reverse_(a, res);
		else
		{
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
			swap_(a, res);
		}
	else if (three > one && three > two && one < two)
	{
		if (get_size(*a) == 3)
		{
			swap_(a, res);
			rotate_reverse_(a, res);
		}
		else
		{
			swap_(a, res);
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
			swap_(a, res);
		}
	}
	return (1);
}

void	quicksort_descending(t_stack **a, t_stack **b, int high, char **res)
{
	int size[2];
	int pivot;

	if (high <= 1 || (high == 2 && ((*a)->value < (*a)->next->value ?
	swap_(a, res) : 1)) || (high == 3 && third_sort_(a, res)))
		return ;
	size[0] = 0;
	size[1] = 0;
	pivot  = find_median(*a, high - 1, 1);
	while (high--)
		if ((*a)->value > pivot && ++(size[1]))
			push_(a, b, res);
		else if ((*a)->value < pivot && ++(size[0]))
			get_size(*a) > 2 ? rotate_(a, res) : 0;
		else if ((*a)->value == pivot && push_(a, b, res) >= 0)
				rotate_(b, res);
	high = size[0];
	if (get_size(*a) > high)
		while (high--)
			rotate_reverse_(a, res);
	quicksort_descending(a, b, size[0], res);
	rotate_reverse_(b, res) && push_(b, a, res);
	quicksort_ascending(b, a, size[1], res);
	while ((size[1])--)
		push_(b, a, res);
}

void	quicksort_ascending(t_stack **a, t_stack **b, int high, char **res)
{
	int	size[2];
	int	pivot;

	if (high <= 1 || (high == 2 && ((*a)->value > (*a)->next->value ?
	swap_(a, res) : 1)) || (high == 3 && third_sort(a, res)))
		return ;
	size[0] = 0;
	size[1] = 0;
	pivot  = find_median(*a, high - 1, 0);
	while (high--)
		if ((*a)->value < pivot && ++(size[1]))
			push_(a, b, res);
		else if ((*a)->value > pivot && ++(size[0]))
			get_size(*a) > 2 ? rotate_(a, res) : 0;
		else if ((*a)->value == pivot && push_(a, b, res) >= 0)
			rotate_(b, res);
	high = size[0];
	if (get_size(*a) > high)
		while (high--)
			rotate_reverse_(a, res);
	quicksort_ascending(a, b, size[0], res);
	rotate_reverse_(b, res) && push_(b, a, res);
	quicksort_descending(b, a, size[1], res);
	while ((size[1])--)
		push_(b, a, res);
}

int		main(int argc, char **argv)
{
	t_stack	*stacks[3];
	char	*strings[2];
	int		count;

	stacks[1] = NULL;
	if (!(strings[1] = (char *)malloc(sizeof(char) * 100000)))
		return(1);
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
	strings[0] = strings[1];
	stacks[0] = new_elem_of_stack(0, 0);
	stacks[2] = stacks[0];
	count = 1;
	while (count < argc)
	{
		stacks[2]->value = atoi(argv[count++]);
		stacks[2]->next = new_elem_of_stack(0, 0);
		stacks[2]->next->prev = stacks[2];
		stacks[2] = stacks[2]->next;
	}
	stacks[2]->prev->next = NULL;
	if (!is_sorted(stacks[0]))
	{
		quicksort_ascending(&stacks[0], &stacks[1], argc - 1, &strings[1]);
		*(strings[1]) = 0;
		ft_printf("%s", strings[0]);
	}
	else
		ft_printf("\n");
	return (0);
}
