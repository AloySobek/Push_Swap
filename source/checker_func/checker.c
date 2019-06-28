/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:04:50 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/28 16:20:50 by vrichese         ###   ########.fr       */
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

void		buituful_print_stacks(t_stack **stacks, char *str,
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

void		command_handler(t_stack **st, char **line, size_t *flags, int max)
{
	*flags & (COL | DEB) ? system("clear") : 0;
	*flags & COL ? buituful_print_stacks(&st[A], "xxx", flags, max) : 0;
	*flags & DEB ? boring_print_stacks(&st[A], flags, "xxx") : 0;
	while (get_next_line(_FILE__, line) == 1)
	{
		if (ft_strcmp(*line, "sa") == 0 || ft_strcmp(*line, "sb") == 0)
			*(*line + 1) == 'a' ? swap(&st[A]) : swap(&st[B]);
		else if (ft_strcmp(*line, "pa") == 0 || ft_strcmp(*line, "pb") == 0)
			*(*line + 1) == 'a' ? push(&st[B], &st[A]) : push(&st[A], &st[B]);
		else if (ft_strcmp(*line, "ra") == 0 || ft_strcmp(*line, "rb") == 0)
			*(*line + 1) == 'a' ? rotate(&st[A]) : rotate(&st[B]);
		else if (ft_strcmp(*line, "rra") == 0 || ft_strcmp(*line, "rrb") == 0)
			*(*line + 2) == 'a' ? reverse(&st[A]) : reverse(&st[B]);
		else if (ft_strcmp(*line, "rr") == 0 && rotate(&st[A]) >= 0)
			rotate(&st[B]);
		else if (ft_strcmp(*line, "rrr") == 0 && reverse(&st[A]) >= 0)
			reverse(&st[B]);
		else if (ft_strcmp(*line, "ss") == 0 && swap(&st[A]) >= 0)
			swap(&st[B]);
		else if (ft_printf("Error\n"))
			exit(1);
		*flags & DEB ? boring_print_stacks(&st[A], flags, *line) : 0;
		*flags & COL ? buituful_print_stacks(&st[A], *line, flags, max) : 0;
		free(*line);
	}
}

void		main_cycle(int argc, char **argv, t_stack **stacks, size_t *flags)
{
	char	**args;
	char	**tmp;

	flags_picker(*argv, flags);
	if (*flags & (DEB | COL | INT | DES) && ++argv)
		*flags & DES ? argc -= 2 : --argc;
	while (--argc)
	{
		args = ft_strsplit(*argv++, ' ');
		tmp = args;
		while (*args)
		{
			if (!checking_args(*args))
				error_handler(0, 0);
			stacks[I]->value = ft_atoi(*args++);
			stacks[I]->next = new_elem_of_stack(0, stacks[I]->index + 1);
			stacks[I]->next->prev = stacks[I];
			stacks[I] = stacks[I]->next;
			free(*(args - 1));
		}
		free(tmp);
	}
	stacks[I]->prev->next = NULL;
	free(stacks[I]);
}

int			main(int argc, char **argv)
{
	t_stack	*stacks[3];
	size_t	flags;
	char	**tmp;
	char	*line;

	flags = 0;
	if (argc == 1)
		error_handler(0, 1);
	stacks[A] = new_elem_of_stack(0, 0);
	stacks[B] = NULL;
	stacks[I] = stacks[A];
	main_cycle(argc, ++argv, &stacks[0], &flags);
	if (!check_duplicate(&stacks[A]))
		error_handler(0, 0);
	labeler(&stacks[A], stacks[I]->index);
	command_handler(&stacks[A], &line, &flags, get_max(stacks[A]));
	if (is_sorted(stacks[A]) && stacks[B] == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(&stacks[A]);
	stacks[B] ? free_list(&stacks[B]) : 0;
	return (0);
}
