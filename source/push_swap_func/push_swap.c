/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 21:26:03 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	extender(char **str, int size)
{
	while (size--)
		*(*str)++ = '!';
	**str = 0;
}

static int	rot_last(t_stack *a)
{
	if (a)
	{
		if (a && a->prev)
			return (a->prev->index);
		while (a->next)
			a = a->next;
		return (a->index);
	}
	return (0);
}

static void	main_cycle(int argc, char **argv, t_stack **stack, int *size)
{
	char	**args;
	char	**tmp;
	int		size;

	*size = 0;
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
			++(*size);
		}
		free(tmp);
	}
	stack[I] = stack[I]->prev;
	free(stack[I]->next);
	stack[I]->next = NULL;
	!check_duplicate(&stack[A]) ? error_handler(0, 0) : 0;
}

static int	main(int argc, char **argv)
{
	t_stack	*stack[3];
	char	*string[3];
	int		length_s;
	int		quantity;

	argc == 1 ? error_handler(0, 1) : 0;
	stack[A] = new_elem_of_stack(0, 0);
	stack[B] = NULL;
	stack[I] = stack[A];
	main_cycle(argc, ++argv, &(stack[0]), &length_s);
	if (!is_sorted(stack[A]))
	{
		quantity = get_size(stack[A]);
		labeler(&stack[A], quantity);
		if (!(string[MAJOR] = (char *)malloc(length_s * length_s * length_s)))
			error_handler(0, 0);
		string[FREED] = string[MAJOR];
		extender(&string[MAJOR], 5);
		string[PRINT] = string[MAJOR];
		quantity >= 95 && quantity <= 100 ?
		sort_100(&stack[A], &stack[B], 100, &string[MAJOR]) :
		quicksort_ascending(&(stack[A]), &(stack[B]), argc - 1, &string[MAJOR]);
		*(string[MAJOR]) = 0;
		ft_printf("%s", string[PRINT]);
		free_list(&stack[A]);
		stack[B] ? free_list(&stack[B]) : 0;
		free(string[FREED]);
	}
	return (0);
}
