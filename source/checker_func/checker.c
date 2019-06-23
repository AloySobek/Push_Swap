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

int				get_max(t_stack *a)
{
	t_stack		*iter;
	int			max;

	if (a)
	{
		iter = a;
		max = iter->value;
		while (iter)
		{
			if (iter->value > max)
				max = iter->value;
			iter = iter->next;
		}
		return (max);
	}
	return (0);
}

int		boring_print_stacks(t_stack *a, t_stack *b, unsigned int *flags)
{
	t_stack *iter_a;
	t_stack *iter_b;
	int size_a;
	int size_b;

	system("clear");
	iter_a = a;
	iter_b = b;
	ft_printf("📊  STACK_A: 📊  STACK_B:  📊\n");
	while (iter_a || iter_b)
	{
		size_a = 6;
		size_b = 6;
		ft_printf("⫸     ");
		iter_a ? size_a = 6 - ft_nbrlen(iter_a->value) : 0;
		iter_a ? ft_printf("%-*d", size_a, iter_a->value) : ft_printf("%*z", size_a, size_a);
		ft_printf("䷀     ");
		iter_b ? size_b = 6 - ft_nbrlen(iter_b->value) : 0;
		iter_b ? ft_printf("%-*d", size_b, iter_b->value) : ft_printf("%*z", size_b, size_b);
		ft_printf("⫷\n");
		iter_a ? iter_a = iter_a->next : 0;
		iter_b ? iter_b = iter_b->next : 0;
	}
	ft_printf("𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃\n");
	!(*flags & (LIV | LIC)) ? system("sleep 0.1") : 0;
	return (1);
}

int			buituful_print_stacks(t_stack **a, t_stack **b, char *str, int max, unsigned int *flags)
{
	t_stack *iter_a;
	t_stack *iter_b;
	int		i;

	iter_a = *a;
	iter_b = *b;
	system("clear");
	str ? ft_printf("@{magenta}Command: 📈  %s 📈@{eoc}\n", str) : 0;
	while (iter_a || iter_b)
	{
		i = 0;
		while (i++ < max)
			iter_a && i <= iter_a->value ? ft_printf("@{blue}█@{eoc}") : ft_printf(" ");
		if (str)
		{
			if (!ft_strcmp(str, "pa"))
				ft_printf("@{green} ⇚ @{eoc}");
			else if (!ft_strcmp(str, "pb"))
				ft_printf("@{green} ⇛ @{eoc}");
			else if (ft_strcmp(str, "Let's get start!"))
				ft_printf("@{green} ↺ @{eoc}");
		}
		i = 0;
		if (iter_b)
			while (i++ < iter_b->value)
				ft_printf("@{red}█@{eoc}");
		ft_printf("\n");
		iter_a ? iter_a = iter_a->next : 0;
		iter_b ? iter_b = iter_b->next : 0;
	}
	if (!str)
	{
		while (max--)
			ft_printf("@{green}✔@{eoc}");
		ft_printf("\n");
	}
	!(*flags & (LIV | LIC)) ? system("sleep 0.7") : 0;
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

void	command_handler(t_stack **a, t_stack **b, char **line, unsigned *flags, int *count, int max)
{
	while (get_next_line(0, line) == 1)
	{
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
		else if (ft_printf("Error\n"))
			exit(1);
		*flags & (COL | LIC) ? buituful_print_stacks(a, b, *line, max, flags) : 0;
		*flags & (GRE | LIV) ? boring_print_stacks(*a, *b, flags) : 0;
	}
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

int		print_usage(void)
{
	ft_printf("Usage: Give a numeric sequence that needs to be sorted\n       ");
	ft_printf("[-v] displaing stacks during the processing\n       ");
	ft_printf("[-c] dispalaying with colour\n");
	return (1);
}

void			fd_collector(char **argv, unsigned *flags, int *i)
{
	//int fd;

	//fd = open(argv[(*i)++])
}

void 			flags_picker(char **argv, unsigned *flags, int *i)
{
	if (ft_strcmp(argv[1], "-v") == 0 && ++(*i))
		*flags |= GRE;
	else if (ft_strcmp(argv[1], "-c") == 0 && ++(*i))
		*flags |= COL;
	else if (ft_strcmp(argv[1], "-ic") == 0 && ++(*i))
		*flags |= LIC;
	else if (ft_strcmp(argv[1], "-iv") == 0 && ++(*i))
		*flags |= LIV;
	//else if (ft_strcmp(argv[1], '-fd') == 0 && ++(*i))
	//	*flags |= REA;
}

int				main(int argc, char **argv)
{
    t_stack		*a;
	t_stack		*b;
	t_stack		*iter;
	char		**args;
    char		*line;
	unsigned	flags;
	int			i;
	int			count;
	int			max;

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
	max = get_max(a);
	if (flags & (LIV | LIC))
		flags & LIV ? boring_print_stacks(a, b, &flags) : buituful_print_stacks(&a, &b, "Let's get start!", max, &flags);
	command_handler(&a, &b, &line, &flags, &count, max);
	flags & COL ? buituful_print_stacks(&a, &b, NULL, max, &flags) : 0;
	is_sorted(a) ? ft_printf("OK\n") : ft_printf("KO\n");
	ft_printf("%d\n", count);
	return (0);
}