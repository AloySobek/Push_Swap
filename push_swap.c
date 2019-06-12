/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/12 20:42:57 by vrichese         ###   ########.fr       */
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
		return (1);
	}
	return (0);
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

void	quicksort_(t_stack **a, t_stack **b, int low, int high, int f)
{
	int pivot;
	int size;
	int size_a;
	int	size_b;
	int flag;
	int prev;
	flag = 0;
	size_a = 0;
	size_b = 0;
	size = high + 1;
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (get_value_from_stack(!f ? a : b, low) > get_value_from_stack(!f ? a : b, high))
		{
			all += swap(!f ? a : b);
			//!f ? write(1, "sa\n", 3) : write(1, "sb\n", 3);
		}
		return ;
	}
	if (size == 3 && get_size(!f ? *a : *b) == 3)
	{
		third_sort(!f ? a : b);
		return ;
	}
	pivot = find_median(!f ? *a : *b, high);
	prev = get_previos(!f ? *a : *b, pivot, high);
	while (size--)
	{
		if ((!f ? (*a)->value : (*b)->value) < pivot)
		{
			if ((!f ? (*a)->value : (*b)->value) == prev)
			{
				!f ? all += push(a, b) : push(b, a);
				!f ? write(1, "pb\n", 3) : write(1, "pa\n", 3);
				all += rotate(!f ? b : a);
				!f ? write(1, "rb\n", 3) : write(1, "ra\n", 3);
				flag ? flag = 2 : (flag = 3);
			}
			else
			{
				!f ? all += push(a, b) : (all += push(b, a));
				//!f ? write(1, "pb\n", 3) : write(1, "pa\n", 3);
				!f ? size_b++ : size_a++;
			}
		}
		else
		{
			if ((!f ? (*a)->value : (*b)->value) == pivot)
			{
				!f ? all += push(a, b) : (all += push(b, a));
				//!f ? write(1, "pb\n", 3) : write(1, "pa\n", 3);
				all += rotate(!f ? b : a);
				//!f ? write(1, "rb\n", 3) : write(1, "ra\n", 3);
				flag != 3 ? flag = 1 : 0;
			}
			else
			{
				all += rotate(!f ? a : b);
				//!f ? write(1, "ra\n", 3) : write(1 ,"rb\n", 3);
				!f ? size_a++ : size_b++;
			}
		}
	}
	//size = !f ? size_a : size_b;
	//if (get_size(!f ? *a : *b) > size)
	//	while (size--)
	//	{
	//		all += rotate_reverse (!f ? a : b);
	//		//!f ? write(1, "rra\n", 4) : write(1 ,"rrb\n", 4);
	//	}
	quicksort_(a, b, 0, (!f ? size_a - 1 : size_b - 1), (!f ? 0 : 1));
	if (flag == 2)
	{
		!f ? all += rotate_reverse(b) && write(1, "rrb\n", 4) : (all += rotate_reverse(a)) && write(1, "rra\n", 4);
		!f ? all += rotate_reverse(b) /* && write(1, "rrb\n", 4)*/ : (all += rotate_reverse(a)) /* && write(1, "rra\n", 4)*/;
		!f ? all += push(b, a) && write(1, "pa\n", 3) : (all += push(a, b)) && write(1, "pb\n", 3);
		!f ? all += push(b, a) /* && write(1, "pa\n", 3) */: (all += push(a, b)) /* && write(1, "pb\n", 3)*/;
	}
	else
	{
		!f ? all += rotate_reverse(b) && write(1, "rrb\n", 4) : (all += rotate_reverse(a)) && write(1, "rra\n", 4);
		!f ? all += rotate_reverse(b) && write(1, "rrb\n", 4) : (all += rotate_reverse(a)) && write(1, "rra\n", 4);
		all += swap(!f ? b : a);
		!f ? write(1, "sb\n", 3) : write(1, "sa\n", 3);
		!f ? all += push(b, a) && write(1, "pa\n", 3) : (all += push(a, b)) && write(1, "pb\n", 3);
		!f ? all += push(b, a) && write(1, "pa\n", 3) : (all += push(a, b)) && write(1, "pb\n", 3);
	}
	quicksort_(a, b, 0, (!f ? size_b - 1 : size_a - 1), !f ? 1 : 0);
	if (!f)
	{
		size = size_b;
		while (size-- > 1)
		{
			all += rotate(b);
		//	write(1, "rb\n", 3);
		}
		all += push(b, a);
		//write(1, "pa\n", 3);
		size = size_b;
		while (size-- > 1)
		{
			all += rotate_reverse(b);
			//write(1, "rrb\n", 4);
			all += push(b, a);
			//write(1, "pa\n", 3);
		}
	}
	else
	{
		size = size_a;
		while (size-- > 1)
		{
			all += rotate(a);
		//	write(1, "ra\n", 3);
		}
		all += push(a, b);
		//write(1, "pb\n", 3);
		size = size_a;
		while (size-- > 1)
		{
			all += rotate_reverse(a);
		//	write(1, "rra\n", 4);
			all += push(a, b);
	//		write(1, "pb\n", 3);
		}
	}
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
	//int hello = find_median(a, argc - 2);
	//push(&a, &b);
	//push(&a, &b);
	//rotate(&b);
	quicksort_(&a, &b, 0, argc - 2, 0);
	print_stack(a);
	print_stack(b);
	//print_stack(c);
	printf("\n|%d|\n", all);
	return (0);
}