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

#include "Push_Swap.h"

int				get_max(t_stack *a)
{
	t_stack		*iter;
	int			max;

	if (a)
	{
		iter = a;
		max = iter->index;
		while (iter)
		{
			if (iter->index > max)
				max = iter->index;
			iter = iter->next;
		}
		return (max);
	}
	return (0);
}

void		boring_print_stacks(t_stack *a, t_stack *b, size_t *flags)
{
	t_stack *iter_a;
	t_stack *iter_b;
	int		width_;

	iter_a = a;
	iter_b = b;
	width_ = 10;
	system("clear");
	ft_printf("📊 𝌃𝌃𝌃𝌃 STACK_A:𝌃𝌃𝌃𝌃 📊 𝌃𝌃𝌃𝌃𝌃 STACK_B:𝌃𝌃𝌃𝌃 📊\n");
	while (iter_a || iter_b)
	{
		if (iter_a)
			ft_printf("⫸         %-*d", width_, iter_a->value);
		else
			ft_printf("⫸         %-*.0d", width_, 0);
		if (iter_b)
			ft_printf("䷀         %-*d⫷\n", width_, iter_b->value);
		else
			ft_printf("䷀         %-*.0d⫷\n", width_, 0);
		iter_a ? iter_a = iter_a->next : 0;
		iter_b ? iter_b = iter_b->next : 0;
	}
	ft_printf("𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃\n");
	!(*flags & INT) ? usleep((int)_TIME__ * 100000) : 0;
}

int			buituful_print_stacks(t_stack **a, t_stack **b, char *str, size_t *flags)
{
	t_stack *iter_a;
	t_stack *iter_b;
	int		i;

	iter_a = *a;
	iter_b = *b;
	!(*flags & INT) ? ft_printf("\e[?25l\e[H") : system("clear");
	str ? ft_printf("@{magenta}Command: 📈%5s 📈@{eoc}\n", str) : 0;
	while (iter_a || iter_b)
	{
		i = 0;
		while (i++ < get_max(*a))
			iter_a && i <= iter_a->index ? ft_printf("@{green}▄@{eoc}") : ft_printf(" ");
		if (str)
		{
			if (!ft_strcmp(str, "pa"))
				ft_printf("@{cyan}  ╷ ⇚ ╷  @{eoc}");
			else if (!ft_strcmp(str, "pb"))
				ft_printf("@{cyan}  ╷ ⇛ ╷  @{eoc}");
			else if (ft_strcmp(str, "xxx"))
				ft_printf("@{cyan}  ╷ ↺ ╷  @{eoc}");
		}
		i = 0;
		while (i++ < get_max(*a))
			iter_b && i <= iter_b->index ? ft_printf("@{red}▄@{eoc}") : ft_printf(" ");
		ft_printf("\n\e[s");
		iter_a ? iter_a = iter_a->next : 0;
		iter_b ? iter_b = iter_b->next : 0;
	}
	!(*flags & INT) ? usleep((int)_TIME__ * 100000) : 0;
	ft_printf("\e[?25h\e[s\e[J");
	return (1);
}

void	command_handler(t_stack **a, t_stack **b, char **line, size_t *flags)
{
	*flags & (INT | DEB) ? boring_print_stacks(*a, *b, flags) : 0;
	*flags & (INT | COL) ? buituful_print_stacks(a, b, *line, flags) && system("clear") : 0;
	while (get_next_line(_FILE__, line) == 1)
	{
		if (ft_strcmp(*line, "sa") == 0 || ft_strcmp(*line, "sb") == 0)
            *(*line + 1) == 'a' ? swap(a) : swap(b);
        else if (ft_strcmp(*line, "pa") == 0 || ft_strcmp(*line, "pb") == 0)
        	*(*line + 1) == 'a' ? push(b, a) : push(a, b);
        else if (ft_strcmp(*line, "ra") == 0 || ft_strcmp(*line, "rb") == 0)
        	*(*line + 1) == 'a' ? rotate(a) : rotate(b);
    	else if (ft_strcmp(*line, "rra") == 0 || ft_strcmp(*line, "rrb") == 0)
			*(*line + 2) == 'a' ? rotate_reverse(a) : rotate_reverse(b);
		else if (ft_strcmp(*line, "rr") == 0 && rotate(a) >= 0)
            rotate(b);
        else if (ft_strcmp(*line, "rrr") == 0 && rotate_reverse(a) >= 0)
            rotate_reverse(b);
        else if (ft_strcmp(*line, "ss") == 0 && swap(a) >= 0)
        	swap(b);
		else if (ft_printf("Error\n"))
			exit(1);
		*flags & DEB ? boring_print_stacks(*a, *b, flags) : 0;
		*flags & COL ? buituful_print_stacks(a, b, *line, flags) : 0;
	}
	*flags & COL ? buituful_print_stacks(a, b, NULL, flags) : 0;
}

void		fd_collector(char **argv, unsigned *flags, int *i)
{
	int		fd;

	fd = open(argv[(*i)++], O_RDONLY);
	if (fd > 0)
		*flags |= fd;
	else
		error_handler(0, 0);
}

int 			check_duplicate(t_stack **a)
{
	t_stack		*iter_1;
	t_stack		*iter_2;

	if (*a && (*a)->next)
	{
		iter_1 = *a;
		while (iter_1->next)
		{
			iter_2 = iter_1->next;
			while (iter_2)
			{
				if (iter_2->value == iter_1->value)
					return (0);
				iter_2 = iter_2->next;
			}
			iter_1 = iter_1->next;
		}
	}
	return (1);
}

void			main_cycle(int argc, char **argv, t_stack **stacks)
{
	char		**args;
	char		**tmp;

	while (--argc)
	{
		args = ft_strsplit(*argv++, ' ');
		tmp = args;
		while (*args)
		{
			stacks[I]->value = ft_atoi(*args++);
			stacks[I]->next = new_elem_of_stack(0, stacks[I]->index + 1);
			stacks[I]->next->prev = stacks[I];
			stacks[I] = stacks[I]->next;
			free(*(args - 1));
		}
		free(tmp);
	}
	stacks[I]->prev->next = NULL;
}

int				main(int argc, char **argv)
{
    t_stack		*stacks[3];
	char		**tmp;
    char		*line;
	size_t		flags;

	flags = 0;
	if (argc == 1 || !checking_args(&argc, &argv, &flags))
		argc == 1 ? error_handler(0, 1) : error_handler(0, 0);
	stacks[A] = new_elem_of_stack(0, 0);
	stacks[B] = NULL;
	stacks[I] = stacks[A];
	main_cycle(argc, argv, &stacks[0]);
	if (!check_duplicate(&stacks[A]))
		error_handler(0, 0);
	labeler(&stacks[A], stacks[I]->index);
	command_handler(&stacks[A], &stacks[B], &line, &flags);
	if (is_sorted(stacks[A]) && stacks[B] == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
