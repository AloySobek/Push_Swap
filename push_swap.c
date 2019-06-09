/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/09 21:45:25 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_stack
{
	int				value;
	int 			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int count = 0;

void			push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*a)
	{
		tmp = *a;
		*a = tmp->next;
		*a ? (*a)->prev = NULL : 0;
		(*tmp).next = *b;
		*b ? (*b)->prev = tmp : 0;
		*b = tmp;
	}
}

void			swap(t_stack **a)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		tmp->prev = *a;
		(*a)->next = tmp->next;
		(*a)->prev = tmp;
		tmp->next = *a;
		tmp->prev = NULL;
		*a = tmp;
	}
}

void			rotate(t_stack **a)
{
	t_stack *tmp;
	t_stack *iter;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		iter = *a;
		while ((*iter).next)
			iter = (*iter).next;
		(*iter).next = tmp;
		(*tmp).next = NULL;
		(*tmp).prev = iter;
	}
}

void			rotate_reverse(t_stack **a)
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

int 			get_value_from_stack(t_stack **a, int index)
{
	t_stack *iter;

	iter = *a;
	while (index--)
		iter = iter->next;
	return (iter->value);
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

int				calc_median(t_stack *a)
{
	int pivot;
	int first;
	int medium;
	int last;

	first = a->value;
	while (a->next)
		a = a->next;
	last = a->value;
	medium = a->index / 2;
	while (a->index != medium)
		a = a->prev;
	medium = a->value;
	if (medium <= first)
	{
		if (medium >= last)
			return (medium);
		else
		{
			if (first >= last)
				return (last);
			else
				return (first);
		}
	}
	else
	{
		if (first >= last)
			return (last);
		else
		{
			if (medium >= last)
				return (last);
			else
				return (medium);
		}
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

void    print_stack(t_stack *st)
{
    static int count = 1;

    printf("\n-----------%d-----------\n", count++);
    while (st)
    {
        printf("%d ", st->value);
        st = st->next;
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

int		get_size(t_stack *a)
{
	int count;
	count = 0;
	while (a)
	{
		++count;
		a = a->next;
	}
	return (count);
}

int		is_empty(t_stack **a)
{
	if (*a)
		return (1);
	return (0);
}

void	modif_swap(t_stack **a, t_stack **b)
{

}

void	quicksort_(t_stack **a, t_stack **b, int low, int high, int f)
{
	int pivot;
	int size;
	int size_a;
	int	size_b;
	int size2;
	size_a = 0;
	size_b = 0;
	size = high + 1;
	size2 = size;
	count++;
	pivot = get_value_from_stack((f == 0 ? a : b), (size / 2));
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (get_value_from_stack(!f ? a : b, low) < get_value_from_stack(!f ? a : b, high))
			swap((f == 0 ? a : b));
		count == 10 ? printf("|%d|\n", pivot) : 0;
		count == 10 ? print_stack(*a) : 0;
		count == 10 ? print_stack(*b) : 0;
		count == 10 ? exit(1) : 0;
		return ;
	}
	if (f)
	{
		push(b, a);
		size--;
		pivot = get_value_from_stack((f == 0 ? a : b), (size / 2));
	}
	while (size-- > 0)
	{
		if ((f ? (*b)->value : (*a)->value) > pivot)
		{
			!f ? push(a, b) : push(b, a);
			!f ? size_b++ : size_a++;
		}
		else
		{
			if ((f ? (*b)->value : (*a)->value) == pivot)
			{
				!f ? push(a, b) : push(b, a);
				rotate(!f ? b : a);
				!f ? size_b++ : size_a++;
			}
			else
			{
				rotate(!f ? a : b);
				!f ? size_a++ : size_b++;
			}
		}
	}
	rotate_reverse(!f ? b : a);
	//count == 10 ? printf("|%d|\n", pivot) : 0;
	//count == 10 ? print_stack(*a) : 0;
	//count == 10 ? print_stack(*b) : 0;
	//count == 10 ? exit(1) : 0;
	quicksort_(a, b, 0, size_a - 1, 0);
	quicksort_(a, b, 0, size_b - 1, 1);
	!f ? push(b, a) : push(a, b);
	//count == 9 ? print_stack(*a) : 0;
	//count == 9 ? print_stack(*b) : 0;
	//count == 9 ? exit(1) : 0;
	size = size2;
	//if (!f)
	//{
	//	while (size-- > 1)
	//		!f ? rotate(b) : rotate(a);
	//	!f ? push(b, a) : push(a, b);
	//	while (size2-- > 1)
	//	{
	//		rotate_reverse(!f ? b : a);
	//		!f ? push(b, a) : push(a, b);
	//	}
	//}
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stack *c;
	t_stack *iter;
	t_stack *iter2;
	int pivot;
	int size;
	int i;

	b = NULL;
	a = new_elem_of_stack(0, 0);
	c = new_elem_of_stack(0, 0);
	iter = a;
	iter2 = c;
	i = 1;
	while (i < argc)
	{
		iter->value = atoi(argv[i]);
		iter2->value = atoi(argv[i++]);
		i != argc ? iter->next = new_elem_of_stack(0, iter->index + 1) : 0;
		i != argc ? iter2->next = new_elem_of_stack(0, iter2->index + 1) : 0;
		i != argc ? iter->next->prev = iter : 0;
		i != argc ? iter2->next->prev = iter2 : 0;
		i != argc ? iter = iter->next : 0;
		i != argc ? iter2 = iter2->next : 0;
	}
	//quicksort(&c, 0, argc - 2);
	//print_stack(a);
	//print_stack(b);
	//print_stack(c);
	//push(&a, &b);
	//push(&a, &b);
	//rotate(&b);
	quicksort_(&a, &b, 0, argc - 2, 0);
/*	while (is_sorted(a) == 0 || is_empty(&b) == 1)
	{
		pivot = get_value_from_stack(&a, (get_size(a)) / 2);
		size = get_size(a);
		while (size--)
		{
			if (a->value > pivot)
			{
				push(&a, &b);
				count++;
			}
			else
			{
				if (a->value == pivot)
				{
					push(&a, &b);
					rotate(&b);
					count += 2;
				}
				else
				{
					rotate(&a);
					count++;
				}
			}
		}
		print_stack(a);
		print_stack(b);
		print_stack(c);
		pivot = get_value_from_stack(&a, (get_size(a)) / 2);
		size = get_size(a);
		printf("\npivot is: %d\nsize is: %d\n", pivot, size);
		while (size--)
		{
			if (a->value > pivot)
			{
				push(&a, &b);
				count++;
			}

			else
			{
				if (a->value == pivot)
				{
					push(&a, &b);
					rotate(&b);
					count += 2;
				}
				else
				{
					rotate(&a);
					count++;
				}
			}
		}
		//rotate_reverse(&b);
		//push(&b, &a);
		//count += 2;
	}*/
	//print_stack(a);
	//print_stack(b);
	//print_stack(c);
	//printf("\n|%d|\n", count);
	return (0);
}