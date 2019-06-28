/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:28:50 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/28 18:45:51 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_optimizer(t_stack **a, char **res)
{
	if (*(*res - 2) == ((*a)->stack == 0 ? 'a' : 'b') && *(*res - 3) == 'p')
		*res -= 3;
	else
	{
		*(*res)++ = 'p';
		*(*res)++ = ((*a)->stack == 0 ? 'b' : 'a');
		*(*res)++ = '\n';
	}
}

void		swap_optimizer(t_stack **a, char **res)
{
	if (*(*res - 2) == ((*a)->stack == 0 ? 'a' : 'b') && *(*res - 3) == 's')
		*res -= 3;
	else
	{
		if (*(*res - 2) == ((*a)->stack == 0 ? 'b' : 'a') && *(*res - 3) == 's')
		{
			*res -= 3;
			*(*res)++ = 's';
			*(*res)++ = 's';
			*(*res)++ = '\n';
		}
		else
		{
			*(*res)++ = 's';
			*(*res)++ = ((*a)->stack == 0 ? 'a' : 'b');
			*(*res)++ = '\n';
		}
	}
}

void		rotate_optimizer(t_stack **a, char **res)
{
	if (*(*res - 2) == ((*a)->stack == 0 ? 'a' : 'b')
	&& *(*res - 4) == 'r' && *(*res - 3) == 'r')
		*res -= 4;
	else
	{
		if (*(*res - 2) == ((*a)->stack == 0 ? 'b' : 'a')
		&& *(*res - 4) == '\n' && *(*res - 3) == 'r')
		{
			*res -= 3;
			*(*res)++ = 'r';
			*(*res)++ = 'r';
			*(*res)++ = '\n';
		}
		else
		{
			*(*res)++ = 'r';
			*(*res)++ = ((*a)->stack == 0 ? 'a' : 'b');
			*(*res)++ = '\n';
		}
	}
}

void		reverse_optimizer(t_stack **a, char **res)
{
	if (*(*res - 2) == ((*a)->stack == 0 ? 'a' : 'b')
	&& *(*res - 4) == '\n' && *(*res - 3) == 'r')
		*res -= 3;
	else
	{
		if (*(*res - 2) == ((*a)->stack == 0 ? 'b' : 'a')
		&& *(*res - 3) == 'r' && *(*res - 4) == 'r')
		{
			*res -= 4;
			*(*res)++ = 'r';
			*(*res)++ = 'r';
			*(*res)++ = 'r';
			*(*res)++ = '\n';
		}
		else
		{
			*(*res)++ = 'r';
			*(*res)++ = 'r';
			*(*res)++ = ((*a)->stack == 0 ? 'a' : 'b');
			*(*res)++ = '\n';
		}
	}
}
