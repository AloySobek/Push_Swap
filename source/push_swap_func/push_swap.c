/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/28 21:24:51 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		zetter(char **strings)
{
	*(strings[A])++ = 'z';
	*(strings[A])++ = 'z';
	*(strings[A])++ = 'z';
	*(strings[A])++ = 'z';
	*(strings[A]) = 'z';
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
			!checking_args(*args) ? error_handler(0, 0) : 0;
			stacks[I]->value = ft_atoi(*args);
			stacks[I]->next = new_elem_of_stack(0, stacks[I]->index + 1);
			stacks[I]->next->prev = stacks[I];
			stacks[I] = stacks[I]->next;
			free(*args++);
			++size;
		}
		free(tmp);
	}
	stacks[I]->prev->next = NULL;
	free(stacks[I]);
	!check_duplicate(&stacks[A]) ? error_handler(0, 0) : 0;
	return (size * size);
}

int			main(int argc, char **argv)
{
	t_stack	*stacks[3];
	char	*strings[3];
	int		size;

	argc == 1 ? error_handler(0, 1) : 0;
	stacks[A] = new_elem_of_stack(0, 0);
	stacks[A]->prev = NULL;
	stacks[B] = NULL;
	stacks[I] = stacks[A];
	size = main_cycle(argc, ++argv, &(stacks[0]));
	if (!is_sorted(stacks[0]))
	{
		if (get_size(stacks[A]) == 100)
			labeler(&stacks[A], 100);
		strings[A] = NULL;
		if (!(strings[A] = (char *)malloc(sizeof(char) * (size * size))))
			error_handler(0, 0);
		strings[I] = strings[A];
		zetter(&(strings[A]));
		strings[B] = strings[A];
		if (get_size(stacks[A]) == 100)
			sort_100(&stacks[A], &stacks[B], 100, &(strings[A]));
		else
			quicksort_ascending(&(stacks[A]), &(stacks[B]), argc - 1, &(strings[A]));
		*(strings[A]) = 0;
		ft_printf("%s", strings[B]);
		free_list(&stacks[A]);
		stacks[B] ? free_list(&stacks[B]) : 0;
		free(strings[I]);
	}
	return (0);
}
