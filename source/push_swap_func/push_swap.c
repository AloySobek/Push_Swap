/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 14:24:58 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		extender(char **str, int size)
{
	while (size--)
		*(*str)++ = '!';
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
	t_stack	*stack[3];
	char	*string[3];
	int		length_s;
	int		quantity;

	argc == 1 ? error_handler(0, 1) : 0;
	stack[A] = new_elem_of_stack(0, 0);
	stack[B] = NULL;
	stack[I] = stack[A];
	length_s = main_cycle(argc, ++argv, &(stack[0]));
	if (!is_sorted(stack[A]))
	{
		quantity = get_size(stack[A]);
		labeler(&stack[A], quantity);
		!(string[MAJOR] = (char *)malloc(length_s)) ? error_handler(0, 0) : 0;
		string[FREED] = string[MAJOR];
		extender(&string[MAJOR], 5);
		string[PRINT] = string[MAJOR];
		quantity == 100 ? sort_100(&stack[A], &stack[B], 100, &(string[A])) :
		quicksort_ascending(&(stack[A]), &(stack[B]), argc - 1, &(string[A]));
		ft_printf("%s", string[PRINT]);
		free_list(&stack[A]);
		stack[B] ? free_list(&stack[B]) : 0;
		free(string[FREED]);
	}
	return (0);
}
