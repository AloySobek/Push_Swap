/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/27 20:58:50 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		zetter(char **strings)
{
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
	*(strings[1])++ = 'z';
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

int			main_cycle(int argc, char **argv, t_stack **stacks)
{
	char	**args;
	char	**tmp;
	int		size;

	size = 0;
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
			++size;
		}
		free(tmp);
	}
	stacks[I]->prev->next = NULL;
	free(stacks[I]);
	if (!check_duplicate(&stacks[A]))
		error_handler(0, 0);
	return (size);
}

int			main(int argc, char **argv)
{
	t_stack	*stacks[3];
	char	*strings[3];
	int		size;

	if (argc == 1)
		error_handler(0, 1);
	stacks[A] = new_elem_of_stack(0, 0);
	stacks[B] = NULL;
	stacks[I] = stacks[A];
	size = main_cycle(argc, ++argv, &stacks[0]);
	if (!is_sorted(stacks[0]))
	{
		labeler(&stacks[A], argc - 1);
		if (!(strings[1] = (char *)malloc(sizeof(char) * (size * size))))
			return (1);
		strings[2] = strings[1];
		zetter(&strings[0]);
		strings[0] = strings[1];
		quicksort_ascending(&stacks[A], &stacks[B], argc - 1, &strings[1]);
		*(strings[1]) = 0;
		ft_printf("%s", strings[0]);
		free_list(&stacks[A]);
		stacks[B] ? free_list(&stacks[B]) : 0;
		free(strings[2]);
	}
	return (0);
}
