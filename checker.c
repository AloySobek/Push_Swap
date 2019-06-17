/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:11:01 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/17 21:37:24 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "Push_Swap.h"
#include <stdio.h>

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

void	command_handler(t_stack **a, t_stack **b, char **line, int *count)
{
	while (get_next_line(0, line) == 1)
    {
		if (ft_strcmp(*line, "sa") == 0)
            *count += swap(a);
        else if (ft_strcmp(*line, "sb") == 0)
            *count += swap(b);
        else if (ft_strcmp(*line, "ss") == 0)
        {
            *count += swap(a);
            swap(b);
        }
        else if (ft_strcmp(*line, "pa") == 0)
            *count += push(b, a);
        else if (ft_strcmp(*line, "pb") == 0)
            *count += push(a, b);
        else if (ft_strcmp(*line, "ra") == 0)
            *count += rotate(a);
        else if (ft_strcmp(*line, "rb") == 0)
            *count += rotate(b);
        else if (ft_strcmp(*line, "rr") == 0)
        {
            *count += rotate(a);
            rotate(b);
        }
        else if (ft_strcmp(*line, "rra") == 0)
            *count += rotate_reverse(a);
        else if (ft_strcmp(*line, "rrb") == 0)
            *count += rotate_reverse(b);
        else if (ft_strcmp(*line, "rrr") == 0)
        {
            *count += rotate_reverse(a);
            rotate_reverse(b);
        }
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
	t_stack *b;
	t_stack *iter;
    char    *line;
    int     count;
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
	command_handler(&a, &b, &line, &count);
	if (is_sorted(a))
		printf("OK\n");
	else
		printf("KO\n");
	//print_stacks(a, b);
	//printf("||%d||\n", count);
    return (0);
}