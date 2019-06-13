/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:11:01 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/13 21:10:17 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>

typedef struct		s_stack
{
	int				value;
	int 			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}                   t_stack;

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

void    print_stacks(t_stack *a, t_stack *b)
{
    while (a)
    {
        printf("%d | ", a->value);
        b ? printf("%d\n", b->value) : printf("\n");
        b ? b = b->next : 0;
        a = a->next;
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

int main(int argc, char **argv)
{
    t_stack *a;
	t_stack *b;
	t_stack *iter;
    char    *line;
    int     count;
    int		size;
	int     i;

	a = new_elem_of_stack(0, 0);
    b = NULL;
	count = 0;
	iter = a;
	i = 1;
	while (i < argc)
	{
		iter->value = atoi(argv[i++]);
		i != argc ? iter->next = new_elem_of_stack(0, iter->index + 1) : 0;
		i != argc ? iter->next->prev = iter : 0;
		i != argc ? iter = iter->next : 0;
	}
	size = iter->index + 1;
    while (get_next_line(0, &line) == 1)
    {
        if (ft_strcmp(line, "sa") == 0)
            count += swap(&a);
        else if (ft_strcmp(line, "sb") == 0)
            count += swap(&b);
        else if (ft_strcmp(line, "ss") == 0)
        {
            count += swap(&a);
            swap(&b);
        }
        else if (ft_strcmp(line, "pa") == 0)
            count += push(&b, &a);
        else if (ft_strcmp(line, "pb") == 0)
            count += push(&a, &b);
        else if (ft_strcmp(line, "ra") == 0)
            count += rotate(&a);
        else if (ft_strcmp(line, "rb") == 0)
            count += rotate(&b);
        else if (ft_strcmp(line, "rr") == 0)
        {
            count += rotate(&a);
            rotate(&b);
        }
        else if (ft_strcmp(line, "rra") == 0)
            count += rotate_reverse(&a);
        else if (ft_strcmp(line, "rrb") == 0)
            count += rotate_reverse(&b);
        else if (ft_strcmp(line, "rrr") == 0)
        {
            count += rotate_reverse(&a);
            rotate_reverse(&b);
        }
    }
	printf("☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟☟\n");
	print_stacks(a, b);
	printf("☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝☝\n");
    //rotate_reverse(&a);
    if (is_sorted(a))
    {
        printf("\n🎪 🎪 🎪 🎪 🎪 \033[0;36mOK\033[0m🎪 🎪 🎪 🎪 🎪 🎪\n");
        printf("\n%d Tallys sorted for %d moves... so bad👎 👎 👎\n", size, count);
    }
    else
    {
        printf("\n🚽 🚽 🚽 🚽 🚽 \033[0;31mKO\033[0m🚽 🚽 🚽 🚽 🚽 🚽\n");
        printf("\nNOT SORTED. AHAHAHAH. LLLUUUSSSEEERRR.😂 😂 😂 😂 😂 😂 😂 😂 😂 😂 😂 😂\n");
    }
    return (0);
}