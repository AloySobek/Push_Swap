/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:11:01 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/18 14:08:17 by vrichese         ###   ########.fr       */
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

void			buituful_print_stacks(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int value;
	int i;

	//system("sleep 0.1");
	system("clear");
	i = 300;
	tmp = *a;
	while (tmp)
	{
		value = tmp->value;
		while (value--)
			ft_printf("@{blue}█@{eoc}");
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	tmp = *b;
	while (tmp)
	{
		value = tmp->value;
		while (value--)
			ft_printf("@{red}█@{eoc}");
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
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
		{
            *count += swap(a);
			//buituful_print_stacks(a, b);
		}
        else if (ft_strcmp(*line, "sb") == 0)
		{
            *count += swap(b);
			//buituful_print_stacks(a, b);
		}
        else if (ft_strcmp(*line, "ss") == 0)
        {
            *count += swap(a);
            swap(b);
			//buituful_print_stacks(a, b);
        }
        else if (ft_strcmp(*line, "pa") == 0)
		{
            *count += push(b, a);
			//buituful_print_stacks(a, b);
		}
        else if (ft_strcmp(*line, "pb") == 0)
		{
            *count += push(a, b);
			//buituful_print_stacks(a, b);
		}
        else if (ft_strcmp(*line, "ra") == 0)
		{
            *count += rotate(a);
			//buituful_print_stacks(a, b);
		}
        else if (ft_strcmp(*line, "rb") == 0)
		{
            *count += rotate(b);
			//buituful_print_stacks(a, b);
		}
        else if (ft_strcmp(*line, "rr") == 0)
        {
            *count += rotate(a);
            rotate(b);
			//buituful_print_stacks(a, b);
        }
        else if (ft_strcmp(*line, "rra") == 0)
		{
            *count += rotate_reverse(a);
			//buituful_print_stacks(a, b);
		}
        else if (ft_strcmp(*line, "rrb") == 0)
		{
            *count += rotate_reverse(b);
			//buituful_print_stacks(a, b);
		}
        else if (ft_strcmp(*line, "rrr") == 0)
        {
            *count += rotate_reverse(a);
            rotate_reverse(b);
			//buituful_print_stacks(a, b);
        }
    }
}

int		checking_args(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] && ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == ' '))
			j++;
		if (argv[i][j])
			return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
    t_stack *a;
	t_stack *b;
	t_stack *iter;
	char	**args;
    char    *line;
    int     count;
	int     i;
	int		flag;

	a = new_elem_of_stack(0, 0);
    b = NULL;
	count = 0;
	iter = a;
	i = 1;
	if (argc == 1)
	{
		ft_printf("Usage: Give a numeric sequence that needs to be sorted\n       [-v] displaing stacks during the processing\n       [-c] dispalaying with colour\n");
		return (0);
	}
	else if (!checking_args(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	//if (ft_strcmp(argv[1], "-v"))
	while (i < argc)
	{
		args = ft_strsplit(argv[i++], ' ');
		while (*args)
		{
			iter->value = ft_atoi(*args);
			if (iter->prev && iter->value == iter->prev->value)
			{
				ft_printf("Error\n");
				return (0);
			}
			iter->next = new_elem_of_stack(0, iter->index + 1);
			iter->next->prev = iter;
			iter = iter->next;
			++args;
		}
	}
	iter->prev->next = NULL;
	command_handler(&a, &b, &line, &count);
	//buituful_print_stacks(&a, &b);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
    return (0);
}