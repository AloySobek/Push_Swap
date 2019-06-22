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

void		boring_print_stacks(t_stack **a, t_stack **b)
{
	return ;
}

int			buituful_print_stacks(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int value;
	int i;

	system("sleep 0.5");
	system("clear");
	i = 300;
	tmp = *a;
	while (tmp)
	{
		value = tmp->value;
		while (value--)
			ft_printf("@{blue}█@{eoc}");
		ft_printf("->@{green}%d@{eoc}\n", tmp->value);
		tmp = tmp->next;
	}
	tmp = *b;
	while (tmp)
	{
		value = tmp->value;
		while (value--)
			ft_printf("@{magenta}█@{eoc}");
		ft_printf("->@{green}%d@{eoc}\n", tmp->value);
		tmp = tmp->next;
	}
	return (1);
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

void	command_handler(t_stack **a, t_stack **b, char **line, unsigned *flags, int *count)
{
	while (get_next_line(0, line) == 1 && (*flags & COL ? buituful_print_stacks(a, b) : 1))
		if (ft_strcmp(*line, "sa") == 0)
            *count += swap(a);
        else if (ft_strcmp(*line, "sb") == 0)
        	*count += swap(b);
        else if (ft_strcmp(*line, "ss") == 0 && swap(a))
        	*count += swap(b);
        else if (ft_strcmp(*line, "pa") == 0)
        	*count += push(b, a);
        else if (ft_strcmp(*line, "pb") == 0)
        	*count += push(a, b);
        else if (ft_strcmp(*line, "ra") == 0)
        	*count += rotate(a);
        else if (ft_strcmp(*line, "rb") == 0)
            *count += rotate(b);
        else if (ft_strcmp(*line, "rr") == 0 && (rotate(a)))
            *count += rotate(b);
        else if (ft_strcmp(*line, "rra") == 0)
            *count += rotate_reverse(a);
        else if (ft_strcmp(*line, "rrb") == 0)
            *count += rotate_reverse(b);
        else if (ft_strcmp(*line, "rrr") == 0 && rotate_reverse(a))
            *count += rotate_reverse(b);
}

int		checking_args(int argc, char **argv, int i)
{
	int j;

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

void    print_stack(t_stack *st)
{
    static int count = 1;

    ft_printf("\n-----------%d-----------\n", count++);
    while (st)
    {
        ft_printf("%d ", st->value);
        st = st->next;
    }
}

int		print_usage(void)
{
	ft_printf("Usage: Give a numeric sequence that needs to be sorted\n       ");
	ft_printf("[-v] displaing stacks during the processing\n       ");
	ft_printf("[-c] dispalaying with colour\n");
	return (1);
}

void 			flags_picker(char **argv, unsigned *flags, int *i)
{
	if (ft_strcmp(argv[1], "-v") == 0 && ++(*i))
		*flags |= COL;
	else if (ft_strcmp(argv[1], "-c") == 0 && ++(*i))
		*flags |= GRE;
	else if (ft_strcmp(argv[1], "-i") == 0 && ++(*i))
		*flags |= LIF;
	else if (ft_strcmp(argv[1], "-f") == 0 && ++(*i))
		*flags |= OUF;
}

int				main(int argc, char **argv)
{
    t_stack		*a;
	t_stack		*b;
	t_stack		*iter;
	char		**args;
    char		*line;
	unsigned int	flags;
	int			i;
	int			count;

	a = new_elem_of_stack(0, 0);
    b = NULL;
	iter = a;
	i = 1;
	flags = 0;
	count = 0;
	if (argc == 1 && print_usage())
		return (0);
	flags_picker(argv, &flags, &i);
	if (!checking_args(argc, argv, i) && ft_printf("Error\n"))
		return (0);
	while (i < argc)
	{
		args = ft_strsplit(argv[i++], ' ');
		while (*args)
		{
			iter->value = ft_atoi(*args++);
			if (iter->prev && iter->value == iter->prev->value && ft_printf("Error\n"))
				return (0);
			iter->next = new_elem_of_stack(0, iter->index + 1);
			iter->next->prev = iter;
			iter = iter->next;
			free(*(args - 1));
		}
	}
	iter->prev->next = NULL;
	command_handler(&a, &b, &line, &flags, &count);
	flags & COL ? buituful_print_stacks(&a, &b) : 0;
	is_sorted(a) ? ft_printf("OK\n") : ft_printf("KO\n");
	//print_stack(a);
	//ft_printf("\n%d", count);
	return (0);
}