/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:27:44 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/27 17:34:21 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		print_usage(void)
{
	ft_printf("Usage: Give a numeric sequence that needs to be sorted\n");
	ft_printf("       [-v] displaing stacks during the processing\n       ");
	ft_printf("[-c] dispalaying with colour\n");
	return (1);
}

void	free_list(t_stack **a)
{
	while ((*a)->next)
	{
		*a = (*a)->next;
		free((*a)->prev);
		(*a)->prev = NULL;
	}
	free(*a);
	*a = NULL;
}

int		get_size(t_stack *a)
{
	int count;

	count = 0;
	if (a)
	{
		if ((a->next) == NULL)
			while (a)
			{
				++count;
				a = a->prev;
			}
		else
			while (a)
			{
				++count;
				a = a->next;
			}
	}
	return (count);
}
