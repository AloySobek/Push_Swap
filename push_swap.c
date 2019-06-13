/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/13 21:07:43 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



typedef struct		s_stack
{
	int				value;
	int 			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	quicksort_(t_stack **a, t_stack **b, int low, int high);
void	quicksort__(t_stack **a, t_stack **b, int low, int high);

int count = 0;
int all = 0;

int 			push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*a)
	{
		(*a)->index == 0 ? write(1, "pb\n", 3) : write(1, "pa\n", 3);
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


int			swap(t_stack **a)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		(*a)->index == 0 ? write(1, "sa\n", 3) : write(1, "sb\n", 3);
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

int			rotate(t_stack **a)
{
	t_stack *tmp;
	t_stack *iter;

	if (*a && (*a)->next)
	{
		(*a)->index == 0 ? write(1, "ra\n", 3) : write(1, "rb\n", 3);
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

int			rotate_reverse(t_stack **a)
{
	t_stack *iter;

	if (*a && (*a)->next)
	{
		(*a)->index == 0 ? write(1, "rra\n", 4) : write(1, "rrb\n", 4);
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

int			ss(t_stack **a, t_stack **b)
{
	if (swap(a) || swap(b))
		return (1);
	return (0);
}

int 		rr(t_stack **a, t_stack **b)
{
	if (rotate(a) || rotate(b))
		return (1);
	return (0);
}

int			rrr(t_stack **a, t_stack **b)
{
	if (rotate_reverse(a) || rotate_reverse(b))
		return (1);
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

int		find_median(t_stack *a, int high)
{
	int size;
	t_stack *tmp;

	tmp = copy_stack(a, high + 1);
	quicksort(&tmp, 0, high);
	size = high + 1;
	return (get_value_from_stack(&tmp, size / 2));
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

int			get_previos(t_stack *a, int value, int high)
{
	t_stack *tmp;

	tmp = copy_stack(a, high + 1);
	quicksort(&tmp, 0, high);
	while (tmp->next->value != value)
		tmp = tmp->next;
	return (tmp->value);
}

void		fourth_sort(t_stack **a)
{
	int one = (*a)->value;
	int two = (*a)->next->value;
	int three = (*a)->next->next->value;
	int four = (*a)->next->next->next->value;

	if (four > one && four > two && four > three && three > two && three > one && two > one)
		return;
	if (four > one && four > two && four > three && two > three && one < two && one < three)
	{
		rotate(a);
		swap(a);
		rotate_reverse(a);
	}
	if (four > one && four > two && four > three && three > one && three > two && one > two)
	{
		swap(a);
	}
	if (four > one && four > two && four > three && two > one && two > three && one > three)
	{

	}
}

void		third_sort(t_stack **a)
{
	int one;
	int two;
	int three;

	one = (*a)->value;
	two = (*a)->next->value;
	three = (*a)->next->next->value;
	if (one > two && one > three && two < three)
	{
		all += swap(a);
		return ;
	}
	if (one > two && one > three && two > three)
	{
		all += rotate(a);
		all += swap(a);
		return ;
	}
	if (two > one && two > three && one < three)
	{
		all += rotate_reverse(a);
		all += swap(a);
		return ;
	}
	if (two > one && two > three && one > three)
	{
		all += rotate_reverse(a);
		return ;
	}
	if (three > one && three > two && one > two)
	{
		all += swap(a);
		return ;
	}
	if (three > one && three > two && one < two)
		return ;
}

void		third_sort_(t_stack **a)
{
	int one;
	int two;
	int three;

	one = (*a)->value;
	two = (*a)->next->value;
	three = (*a)->next->next->value;
	if (one > two && one > three && two < three)
	{
		all += rotate_reverse(a);
		all += swap(a);
		return ;
	}
	if (one > two && one > three && two > three)
		return ;
	if (two > one && two > three && one < three)
	{
		all += rotate(a);
		return ;
	}
	if (two > one && two > three && one > three)
	{
		all += swap(a);
		return ;
	}
	if (three > one && three > two && one > two)
	{
		all += rotate_reverse(a);
		return ;
	}
	if (three > one && three > two && one < two)
	{
		all += swap(a);
		all += rotate_reverse(a);
		return ;
	}
}

void	quicksort__(t_stack **a, t_stack **b, int low, int high)
{
	int pivot;
	int size;
	int size_a;
	int	size_b;

	size_a = 0;
	size_b = 0;
	size = high + 1;
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (get_value_from_stack(a, low) < get_value_from_stack(a, high))
			swap(a);
		return ;
	}
	if (size == 3 && get_size(*a) == 3)
	{
		third_sort_(a);
		return ;
	}
	pivot = find_median(*a, high);
	while (size--)
	{
		if ((*a)->value > pivot)
		{
			all += push(a, b);
			size_b++;
		}
		else
		{
			if ((*a)->value == pivot)
			{
				all += push(a, b);
				all += rotate(b);
			}
			else
			{
				all += rotate(a);
				size_a++;
			}
		}
	}
	size = size_a;
	if (get_size(*a) > size)
		while (size--)
			all += rotate_reverse (a);
	quicksort__(a, b, 0, size_a - 1);
	all += rotate_reverse(b);
	all += push(b, a);
	quicksort__(b, a, 0, size_b - 1);
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

void	quicksort_(t_stack **a, t_stack **b, int low, int high)
{
	int pivot;
	int size;
	int size_a;
	int	size_b;

	size_a = 0;
	size_b = 0;
	size = high + 1;
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (get_value_from_stack(a, low) > get_value_from_stack(a, high))
			swap(a);
		return ;
	}
	if (size == 3 && get_size(*a) == 3)
	{
		third_sort(a);
		return ;
	}
	pivot = find_median(*a, high);
	while (size--)
	{
		if ((*a)->value < pivot)
		{
			all += push(a, b);
			size_b++;
		}
		else
		{
			if ((*a)->value == pivot)
			{
				all += push(a, b);
				all += rotate(b);
			}
			else
			{
				all += rotate(a);
				size_a++;
			}
		}
	}
	size = size_a;
	if (get_size(*a) > size)
		while (size--)
			all += rotate_reverse(a);
	quicksort_(a, b, 0, size_a - 1);
	all += rotate_reverse(b);
	all += push(b, a);
	quicksort__(b, a, 0, size_b - 1);
	size = size_b;
	while (size--)
		all += push(b, a);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stack *c;
	t_stack *iter;
	int pivot;
	int size;
	int size_a;
	int size_b;
	int size_a1;
	int size_b1;
	int size_b12;
	int size_a12;

	b = NULL;
	a = new_elem_of_stack(0, 0);
	c = new_elem_of_stack(0, 0);
	iter = a;
	size = 1;
	while (size < argc)
	{
		iter->value = atoi(argv[size++]);
		size != argc ? iter->next = new_elem_of_stack(0, 0) : 0;
		size != argc ? iter->next->prev = iter : 0;
		size != argc ? iter = iter->next : 0;
	}
	pivot = find_median(a, argc - 2);
	size = argc - 1;
	size_a = 0;
	size_b = 0;
	while (size--)
	{
		if (a->value < pivot)
		{
			all += push(&a, &b);
			size_b++;
		}
		else
		{
			all += rotate(&a);
			size_a++;
		}
	}
	quicksort_(&a, &b, 0, size_a - 1);
	quicksort__(&b, &a, 0, size_b - 1);
	while (size_b--)
		all += push(&b, &a);
	//print_stack(a);
	//print_stack(b);
	//printf("\n|%d|\n", all);
	return (0);
}
