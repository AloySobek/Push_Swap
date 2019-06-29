/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:04:50 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 19:42:12 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		boring_print_stacks(t_stack **stacks, size_t *flags, char *str)
{
	t_stack	*iter[2];
	int		breadth;

	iter[A] = stacks[A];
	iter[B] = stacks[B];
	breadth = 10;
	system("clear");
	ft_printf("📊 𝌃𝌃𝌃𝌃 STACK_A:𝌃𝌃𝌃𝌃 📊 𝌃𝌃𝌃𝌃𝌃 STACK_B:𝌃𝌃𝌃𝌃 📊\n");
	while (iter[A] || iter[B])
	{
		if (iter[A])
			ft_printf("⫸         %-*d", breadth, iter[A]->value);
		else
			ft_printf("⫸         %-*.0d", breadth, 0);
		if (iter[B])
			ft_printf("䷀         %-*d⫷\n", breadth, iter[B]->value);
		else
			ft_printf("䷀         %-*.0d⫷\n", breadth, 0);
		iter[A] ? iter[A] = iter[A]->next : 0;
		iter[B] ? iter[B] = iter[B]->next : 0;
	}
	ft_printf("𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃 Command:%3s ", str);
	ft_printf("𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃𝌃\n");
	!(*flags & INT) ? usleep((int)_TIME__ * 100000) : 0;
}

void		beautiful_print_stacks(t_stack **stacks, char *str,
									size_t *flags, int max)
{
	t_stack	*iter[2];
	int		i;

	iter[A] = stacks[A];
	iter[B] = stacks[B];
	!(*flags & INT) ? ft_printf("\e[?25l\e[H") : system("clear");
	ft_printf("@{magenta}Command: 📈%5s 📈@{eoc}\n", str);
	while ((iter[A] || iter[B]) && !(i = 0))
	{
		while (i++ < max)
			iter[A] && i <= iter[A]->index ? P_G : ft_printf(" ");
		if (!(i = 0) && !ft_strcmp(str, "pa"))
			ft_printf("@{cyan}  ╷ ⇚ ╷  @{eoc}");
		else if (!ft_strcmp(str, "pb"))
			ft_printf("@{cyan}  ╷ ⇛ ╷  @{eoc}");
		else if (ft_strcmp(str, "xxx"))
			ft_printf("@{cyan}  ╷ ↺ ╷  @{eoc}");
		while (i++ < max)
			iter[B] && i <= iter[B]->index ? P_R : ft_printf(" ");
		ft_printf("\n");
		iter[A] ? iter[A] = iter[A]->next : 0;
		iter[B] ? iter[B] = iter[B]->next : 0;
	}
	!(*flags & INT) ? usleep((int)_TIME__ * 100000) : 0;
	ft_printf("\e[?25h\e[s\e[J");
}

void		acts_handler(t_stack **st, char **act, size_t *flags, int max)
{
	*flags & (COL | DEB) ? system("clear") : 0;
	*flags & COL ? beautiful_print_stacks(&st[A], "xxx", flags, max) : 0;
	*flags & DEB ? boring_print_stacks(&st[A], flags, "xxx") : 0;
	while (get_next_line(_FILE__, act) == 1)
	{
		if (ft_strcmp(*act, "sa") == 0 || ft_strcmp(*act, "sb") == 0)
			*(*act + 1) == 'a' ? swap(&st[A]) : swap(&st[B]);
		else if (ft_strcmp(*act, "pa") == 0 || ft_strcmp(*act, "pb") == 0)
			*(*act + 1) == 'a' ? push(&st[B], &st[A]) : push(&st[A], &st[B]);
		else if (ft_strcmp(*act, "ra") == 0 || ft_strcmp(*act, "rb") == 0)
			*(*act + 1) == 'a' ? rotate(&st[A]) : rotate(&st[B]);
		else if (ft_strcmp(*act, "rra") == 0 || ft_strcmp(*act, "rrb") == 0)
			*(*act + 2) == 'a' ? reverse(&st[A]) : reverse(&st[B]);
		else if (ft_strcmp(*act, "rr") == 0 && rotate(&st[A]) >= 0)
			rotate(&st[B]);
		else if (ft_strcmp(*act, "rrr") == 0 && reverse(&st[A]) >= 0)
			reverse(&st[B]);
		else if (ft_strcmp(*act, "ss") == 0 && swap(&st[A]) >= 0)
			swap(&st[B]);
		else
			error_handler(0, 0);
		*flags & DEB ? boring_print_stacks(&st[A], flags, *act) : 0;
		*flags & COL ? beautiful_print_stacks(&st[A], *act, flags, max) : 0;
		free(*act);
	}
}

void		main_cycle(int argc, char **argv, t_stack **stack, size_t *flags)
{
	char	**args;
	char	**tmp;

	flags_picker(*argv, *(argv + 1), flags);
	if (*flags & (DEB | COL | INT | DES) && ++argv)
		*flags & DES ? (argc -= 2) && ++argv : --argc;
	while (--argc)
	{
		args = ft_strsplit(*argv++, ' ');
		tmp = args;
		while (*args)
		{
			!checking_args(*args) ? error_handler(0, 0) : 0;
			stack[I]->value = ft_atoi(*args);
			stack[I]->next = new_elem_of_stack(0, stack[I]->index + 1);
			stack[I]->next->prev = stack[I];
			stack[I] = stack[I]->next;
			free(*args++);
		}
		free(tmp);
	}
	stack[I] = stack[I]->prev;
	free(stack[I]->next);
	stack[I]->next = NULL;
}

int			main(int argc, char **argv)
{
	t_stack	*stack[3];
	size_t	flags_cv;
	char	*line;

	argc == 1 ? error_handler(0, 1) : 0;
	flags_cv = 0;
	stack[A] = new_elem_of_stack(0, 0);
	stack[B] = NULL;
	stack[I] = stack[A];
	main_cycle(argc, ++argv, &stack[A], &flags_cv);
	!check_duplicate(&stack[A]) ? error_handler(0, 0) : 0;
	labeler(&stack[A], stack[I]->index);
	acts_handler(&stack[A], &line, &flags_cv, get_max(stack[A]));
	free(line);
	if (is_sorted(stack[A]) && stack[B] == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(&stack[A]);
	stack[B] ? free_list(&stack[B]) : 0;
	return (0);
}
