/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/25 21:00:06 by vrichese         ###   ########.fr       */
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
		if ((*a)->stack == 0)
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
		tmp->stack == 0 ? tmp->stack = 1 : (tmp->stack = 0);
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
		if ((*a)->stack == 0)
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
		if ((*a)->stack == 0)
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
		if ((*a)->stack == 0)
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

/*static int    where_to(t_stack *a, int index)
{
    t_stack    *rotate;
    int        direction;

    direction = 0;
    rotate = a;
    while (rotate->index != index)
    {
        rotate = rotate->right;
        ++direction;
    }
    rotate = s;
    while (rotate->index != index)
    {
        rotate = rotate->left;
        --direction;
    }
    return (direction);
}

static void    sort_back(t_stack **a, t_stack **b, int size, char **str)
{
    int start;
    int end;

    start = find_highest(*b, size);
    end = find_lowest(*b, size);
    while (end <= start)
    {
        if (where_to(*b, start) < 0)
        {
			while ((*b)->index != start)
            {
                if ((*b)->index == start - 1)
                    push_(b, a, str);
                else if ((*b)->index == end || (*b)->index == end + 1)
                {
                    push_(b, a, str);
                    rotate_(a, str);
                }
                else
                    rotate_(b, str);
            }
		}
        else
		{
            while ((*b)->index != start)
            {
                if ((*b)->index == start - 1)
                    push_(b, a, str);
                else if ((*b)->index == end || (*b)->index == end + 1)
                {
                    push_(b, a, str);
                    rotate_(a, str);
                }
                else
                    reverse_(b, str);
            }
		}
        push_(b, a, str);
        --start;
        if ((*a)->index > (*a)->next->index)
        {
            swap_(a, str);
            --start;
        }
        if ((*a)->prev->index == start)
            --start;
        while ((*a)->prev->index == end || (*a)->prev->prev->index == end)
            ++end;
    }
    while ((*a)->prev->index < (*a)->prev->index)
    {
        reverse_(a, str);
        if ((*a)->index > (*a)->next->index)
            swap_(a, str);
    }
}

void    sort_100(t_stack **a, t_stack **b, int size, int **coms)
{
    int pivot;
    int count;
    int check_p = 0;

    if (size == 2 && (*a)->index > (*a)->right->index)
        swap(a, coms);
    else if (size == 3)
        solve_3(a, coms);
    else if (size > 3)
    {
        pivot = find_lowest(*a, size) + size / 2 + size % 2;
        count = 0;
        while (count * 2 < size || check_p != 2)
        {
            if ((*a)->index < pivot)
            {
                push(a, b, coms);
                ++count;
            }
            else if ((*a)->index == pivot)
            {
                push(a, b, coms);
                rotate(b, coms);
                ++check_p;
            }
            else if ((*a)->index == pivot + 1)
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
        if ((*a)->index > (*a)->right->index)
            swap(a, coms);
        sort_back(a, b, count, coms);
    }
}*/

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
		if (get_size(*a) == 3)
			rotate_(a, res);
		else
		{
			swap_(a, res);
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
		}
	}
	else if (one > two && one > three && two > three)
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
			rotate_reverse_(a, res);
			swap_(a, res);
		}
	}
	else if (two > one && two > three && one < three)
	{
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
	}
	else if (two > one && two > three && one > three)
	{
		if (get_size(*a) == 3)
			rotate_reverse_(a, res);
		else
		{
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
			swap_(a, res);
		}
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
	{
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
			rotate_reverse_(a, res);
		}
	}
	else if (two > one && two > three && one > three)
		swap_(a, res);
	else if (three > one && three > two && one > two)
	{
		if (get_size(*a) == 3)
			rotate_reverse_(a, res);
		else
		{
			rotate_(a, res);
			swap_(a, res);
			rotate_reverse_(a, res);
			swap_(a, res);
		}
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
		else
			(*a)->value == pivot && push_(a, b, res) >= 0 ? rotate_(b, res) :
			++(size[0]) && rotate_(a, res);
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
	int prev;

	if (high <= 1 || (high == 2 && ((*a)->value > (*a)->next->value ?
	swap_(a, res) : 1)) || (high == 3 && third_sort(a, res)))
		return ;
	size[0] = 0;
	size[1] = 0;
	pivot  = find_median(*a, high - 1, 0);
	while (high--)
		if ((*a)->value < pivot && ++(size[1]))
			push_(a, b, res);
		else
			(*a)->value == pivot && push_(a, b, res) >= 0 ? rotate_(b, res) :
			++(size[0]) && rotate_(a, res);
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

	if (!(strings[1] = (char *)malloc(sizeof(char) * 100000)))
		return(1);
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
	stacks[1] = NULL;
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
		labeler(&stacks[A], argc - 2);
		quicksort_ascending(&stacks[0], &stacks[1], argc - 1, &strings[1]);
		*(strings[1]) = 0;
		ft_printf("%s", strings[0]);
	}
	else
		ft_printf("\n");
	return (0);
}
