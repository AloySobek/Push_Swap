/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/10 21:39:10 by vrichese         ###   ########.fr       */
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
int all = 0;

int 			push(t_stack **a, t_stack **b)
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
	return (1);
}

int			swap(t_stack **a)
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
		while ((*iter).next)
			iter = (*iter).next;
		(*iter).next = tmp;
		(*tmp).next = NULL;
		(*tmp).prev = iter;
	}
	return (1);
}

int			rotate_reverse(t_stack **a)
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

int 			get_value_from_stack(t_stack **a, int index)
{
	t_stack *iter;
	int size;

	iter = *a;
	if (iter)
	{
		//if (iter->next == NULL)
		//{
		//	size = get_size(iter) - index - 1;
		//	while (size--)
		//		iter = iter->prev;
		//}
		//else
		//{
			while (index--)
				iter = iter-> next;
		//}
		return (iter->value);
	}
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

void	quicksort_(t_stack **a, t_stack **b, int low, int high, int f)
{
	count++;
	int pivot;
	int size;
	int size_a;
	int	size_b;
	size_a = 0;
	size_b = 0;
	size = high + 1;
	if (size <= 1)
	{
		printf("size_a: %d\nsize_b: %d\n", size_a, size_b);
		count <= 8 ? print_stack(*a) : 0;
		count <= 8 ? print_stack(*b) : 0;
		count <= 8 ? printf("\n|%d|\n", all) : 0;
		count == 8 ? exit(1) : 0;
		return ;
	}
	if (size == 2)
	{
		if (get_value_from_stack(!f ? a : b, low) > get_value_from_stack(!f ? a : b, high))
			all += swap((!f ? a : b));
		printf("size_a: %d\nsize_b: %d\n", size_a, size_b);
		count <= 8 ? print_stack(*a) : 0;
		count <= 8 ? print_stack(*b) : 0;
		count <= 8 ? printf("\n|%d|\n", all) : 0;
		count == 8 ? exit(1) : 0;
		return ;
	}
	pivot = get_value_from_stack((!f ? a : b), (size / 2));
	while (size--)
	{
		if ((!f ? (*a)->value : (*b)->value) < pivot)
		{
			!f ? all += push(a, b) : (all += push(b, a));
			!f ? size_b++ : size_a++;
		}
		else
		{
			if ((!f ? (*a)->value : (*b)->value) == pivot)
			{
				!f ? all += push(a, b) : (all += push(b, a));
				all += rotate(!f ? b : a);
			}
			else
			{
				all += rotate(!f ? a : b);
				!f ? size_a++ : size_b++;
			}
		}
	}
	size = !f ? size_a : size_b;
	while (size--)
		all += rotate_reverse (!f ? a : b);
	printf("size_a: %d\nsize_b: %d\n", size_a, size_b);
	count <= 8 ? print_stack(*a) : 0;
	count <= 8 ? print_stack(*b) : 0;
	count <= 8 ? printf("\n|%d|\n", all) : 0;
	count == 8 ? exit(1) : 0;
	quicksort_(a, b, 0, size_a - 1, 0);
	!f ? all += rotate_reverse(b) : (all += rotate_reverse(a));
	!f ? all += push(b, a) : (all += push(a, b));
	//count == 7 ? print_stack(*a) : 0;
	//count == 7 ? print_stack(*b) : 0;
	//count == 7 ? printf("\n|%d|\n", all) : 0;
	//count == 7 ? exit(1) : 0;
	quicksort_(a, b, 0, size_b - 1, 1);
	if (!f)
	{
		size = size_b;
		while (size-- > 1)
			all += rotate(b);
		all += push(b, a);
		size = size_b;
		while (size-- > 1)
		{
			all += rotate_reverse(b);
			all += push(b, a);
		}
	}
	else
	{
		size = size_b;
		while (size-- > 1)
			all += rotate(a);
		all += push(a, b);
		size = size_b;
		while (size-- > 1)
		{
			all += rotate_reverse(b);
			all += push(a, b);
		}
	}
	!f ? all += rotate_reverse(b) : (all += rotate_reverse(a));
	!f ? all += push(b, a) : (all += push(a, b));
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
  /*while (is_sorted(a) == 0 || is_empty(&b) == 1)
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
	printf("\n|%d|\n", all);
	return (0);
}