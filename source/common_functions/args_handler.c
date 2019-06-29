/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:09:16 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 21:31:47 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		error_handler(int usage, int none)
{
	if (usage)
	{
		ft_printf("Usage: Give a numeric sequence that needs to be sorted\n");
		ft_printf("       [-v] displaing stacks during the processing\n");
		ft_printf("       [-c] dispalaying with colour\n");
	}
	else if (!none)
		ft_printf("Error\n");
	exit(1);
}

static int	check_overflow(char *str, int minus)
{
	int		check;

	minus ? *--str = '-' : 0;
	check = ft_atoi(str);
	if (*str == '-')
	{
		if (check > 0)
			return (0);
	}
	else if (check < 0)
		return (0);
	return (1);
}

int			check_duplicate(t_stack **a)
{
	t_stack	*iter_1;
	t_stack	*iter_2;

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

int			checking_args(char *str)
{
	int		minus;

	minus = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str) == 1)
			++str;
		if (*str == '+' || *str == '-')
			*str++ == '-' ? minus = 1 : 0;
		while (*str && *str == '0')
			++str;
		if (ft_strlen(str) > 10)
			return (0);
		if (ft_strlen(str) == 10)
			if (*str > '2' || check_overflow(str, minus) == 0)
				return (0);
		while (*str && *str >= '0' && *str <= '9')
			++str;
		if (*str)
			return (0);
	}
	return (1);
}
