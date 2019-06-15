/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/15 16:58:48 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *str;

typedef struct		s_stack
{
	int				value;
	int 			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void		quicksort_ascending(t_stack **a, t_stack **b, int low, int high, char **res);
int			ss(t_stack **a, char **res);
int 		rr(t_stack **a, char **res);
int			rrr(t_stack **a, char **res);

int count = 0;
int all = 0;

int 			push(t_stack **a, t_stack **b, char **res)
{
	t_stack *tmp;
	if (*a)
	{
		if ((*a)->index == 0)
		{
			if (*((*res) - 2) == 'a' && *((*res) - 4) == '\n' && *((*res) - 3) == 'p')
			{
				*res -= 3;
				all -= 2;
			}
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
			{
				*res -= 3;
				all -= 2;
			}
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


int			swap(t_stack **a, char **res)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		if ((*a)->index == 0)
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

int			rotate(t_stack **a, char **res)
{
	t_stack *tmp;
	t_stack *iter;

	if (*a && (*a)->next)
	{
		if ((*a)->index == 0)
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

int			rotate_reverse(t_stack **a, char **res)
{
	t_stack *iter;

	if (*a && (*a)->next)
	{
		if ((*a)->index == 0)
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

int			get_previos(t_stack *a, int value, int high)
{
	t_stack *tmp;

	tmp = copy_stack(a, high + 1);
	quicksort(&tmp, 0, high);
	while (tmp->next->value != value)
		tmp = tmp->next;
	return (tmp->value);
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
	{
		all += swap(a, res);
		return (1);
	}
	if (one > two && one > three && two > three)
	{
		all += rotate(a, res);
		all += swap(a, res);
		return (1);
	}
	if (two > one && two > three && one < three)
	{
		all += rotate_reverse(a, res);
		all += swap(a, res);
		return (1);
	}
	if (two > one && two > three && one > three)
	{
		all += rotate_reverse(a, res);
		return (1);
	}
	if (three > one && three > two && one > two)
	{
		all += swap(a, res);
		return (1);
	}
	if (three > one && three > two && one < two)
		return (1);
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
	{
		all += rotate_reverse(a, res);
		all += swap(a, res);
		return (1);
	}
	if (one > two && one > three && two > three)
		return (1);
	if (two > one && two > three && one < three)
	{
		all += rotate(a, res);
		return (1);
	}
	if (two > one && two > three && one > three)
	{
		all += swap(a, res);
		return (1);
	}
	if (three > one && three > two && one > two)
	{
		all += rotate_reverse(a, res);
		return (1);
	}
	if (three > one && three > two && one < two)
	{
		all += swap(a, res);
		all += rotate_reverse(a, res);
		return (1);
	}
	return (1);
}

void	fifth_sort(t_stack **a)
{
	int one = (*a)->value;
	int two = (*a)->next->value;
	int three = (*a)->next->next->value;
	int four = (*a)->next->next->next->value;
	int fife = (*a)->next->next->next->next->next->value;

}

void	quicksort_descending(t_stack **a, t_stack **b, int low, int high, char **res)
{
	int length;
	int size_a;
	int	size_b;
	int pivot;

	length = high + 1;
	size_a = 0;
	size_b = 0;
	if (length <= 1)
		return ;
	if (length == 2)
	{
		if (get_value_from_stack(a, low) < get_value_from_stack(a, high))
			all += swap(a, res);
		return ;
	}
	if (length == 3 && get_size(*a) == 3 && third_sort_(a, res))
		return ;
	pivot = find_median(*a, high);
	while (length--)
		if ((*a)->value > pivot && ++size_b)
			all += push(a, b, res);
		else
			if ((*a)->value == pivot && (all += push(a, b, res) >= 0))
				all += rotate(b, res);
			else if (++size_a)
				all += rotate(a, res);
	length = size_a;
	if (get_size(*a) > length)
		while (length--)
			all += rotate_reverse (a, res);
	quicksort_descending(a, b, 0, size_a - 1, res);
	all += rotate_reverse(b, res);
	all += push(b, a, res);
	quicksort_ascending(b, a, 0, size_b - 1, res);
	while (size_b--)
		all += push(b, a, res);
}

void	quicksort_ascending(t_stack **a, t_stack **b, int low, int high, char **res)
{
	int pivot;
	int length;
	int size_a;
	int	size_b;

	length = high + 1;
	size_a = 0;
	size_b = 0;
	if (length <= 1)
		return ;
	if (length == 2)
	{
		if (get_value_from_stack(a, low) > get_value_from_stack(a, high))
			all += swap(a, res);
		return ;
	}
	if (length == 3 && get_size(*a) == 3 && third_sort(a, res))
		return ;
	pivot = find_median(*a, high);
	while (length--)
		if ((*a)->value < pivot && ++size_b)
			all += push(a, b, res);
		else
			if ((*a)->value == pivot && (all += push(a, b, res) >= 0))
				all += rotate(b, res);
			else if (++size_a)
				all += rotate(a, res);
	length = size_a;
	if (get_size(*a) > length)
		while (length--)
			all += rotate_reverse(a, res);
	quicksort_ascending(a, b, 0, size_a - 1, res);
	all += rotate_reverse(b, res);
	all += push(b, a, res);
	quicksort_descending(b, a, 0, size_b - 1, res);
	while (size_b--)
		all += push(b, a, res);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stack *iter;
	char	*res;
	char	*hello;
	int size;
	int size_a;
	int size_b;

	b = NULL;
	res = (char *)malloc(sizeof(char) * 100000);
	*res++ = 'z';
	*res++ = 'z';
	*res++ = 'z';
	*res++ = 'z';
	*res++ = '\n';
	hello = res;
	a = new_elem_of_stack(0, 0);
	iter = a;
	size = 1;
	while (size < argc)
	{
		iter->value = atoi(argv[size++]);
		size != argc ? iter->next = new_elem_of_stack(0, 0) : 0;
		size != argc ? iter->next->prev = iter : 0;
		size != argc ? iter = iter->next : 0;
	}
	quicksort_ascending(&a, &b, 0, argc - 2, &res);
	*res = 0;
	printf("%s", hello);
	//print_stack(a);
	//print_stack(b);
	//printf("\n|%d|\n", all);
	return (0);
}
