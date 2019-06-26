/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:28:50 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/26 20:21:10 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_optimizer(t_stack **a, char **res)
{
	if ((*a)->stack == 0)
	{
		if (*((*res) - 2) == 'a' && *((*res) - 4) == '\n' && *((*res) - 3) == 'p')
			*res -= 3;
		else
		{
			**res = 'p';
			*res += 1;
			**res = 'b';
			*res += 1;
			**res = '\n';
			*res += 1;
		}
	}
	else
	{
		if (*((*res) - 2) == 'b' && *((*res) - 4) == '\n' && *((*res) - 3) == 'p')
			*res -= 3;
		else
		{
			**res = 'p';
			*res += 1;
			**res = 'a';
			*res += 1;
			**res = '\n';
			*res += 1;
		}
	}
}

void		swap_optimizer(t_stack **a, char **res)
{
	if ((*a)->stack == 0)
	{
		if (*(*res - 2) == 'a' && *(*res - 4) == '\n' && *(*res - 3) == 's')
			*res -= 3;
		else
		{
			if (*(*res - 2) == 'b' && *(*res - 4) == '\n' && *(*res - 3) == 's')
			{
				*res -= 3;
				ss(a, res);
			}
			else
			{
				**res = 's';
				*res += 1;
				**res = 'a';
				*res += 1;
				**res = '\n';
				*res += 1;
			}
		}
	}
	else
	{
		if (*(*res - 2) == 'b' && *(*res - 4) == '\n' && *(*res - 3) == 's')
			*res -= 3;
		else
		{
			if (*(*res - 2) == 'a' && *(*res - 4) == '\n' && *(*res - 3) == 's')
			{
				*res -= 3;
				ss(a, res);
			}
			else
			{
				**res = 's';
				*res += 1;
				**res = 'b';
				*res += 1;
				**res = '\n';
				*res += 1;
			}
		}
	}
}

void		rotate_optimizer(t_stack **a, char **res)
{
	if ((*a)->stack == 0)
	{
		if (*(*res - 2) == 'a' && *(*res - 4) == 'r' && *(*res - 3) == 'r')
			*res -= 4;
		else
		{
			if (*(*res - 2) == 'b' && *(*res - 4) == '\n' && *(*res - 3) == 'r')
			{
				*res -= 3;
				rr(a, res);
			}
			else
			{
				**res = 'r';
				*res += 1;
				**res = 'a';
				*res += 1;
				**res = '\n';
				*res += 1;
			}
		}
	}
	else
	{
		if (*(*res - 2) == 'b' && *(*res - 4) == 'r' && *(*res - 3) == 'r')
			*res -= 4;
		else
		{
			if (*(*res - 2) == 'a' && *(*res - 4) == '\n' && *(*res - 3) == 'r')
			{
				*res -= 3;
				rr(a, res);
			}
			else
			{
				**res = 'r';
				*res += 1;
				**res = 'b';
				*res += 1;
				**res = '\n';
				*res += 1;
			}
		}
	}
}

void		reverse_optimizer(t_stack **a, char **res)
{
	if ((*a)->stack == 0)
	{
		if (*(*res - 2) == 'a' && *(*res - 4) == '\n' && *(*res - 3) == 'r')
			*res -= 3;
		else
		{
			if (*(*res - 2) == 'b' && *(*res - 5) == '\n' && *(*res - 3) == 'r' && *(*res - 4) == 'r')
			{
				*res -= 4;
				rrr(a, res);
			}
			else
			{
				**res = 'r';
				*res += 1;
				**res = 'r';
				*res += 1;
				**res = 'a';
				*res += 1;
				**res = '\n';
				*res += 1;
			}
		}
	}
	else
	{
		if (*(*res - 2) == 'b' && *(*res - 4) == '\n' && *(*res - 3) == 'r')
			*res -= 3;
		else
		{
			if (*(*res - 2) == 'a' && *(*res - 5) == '\n' && *(*res - 3) == 'r' && *(*res - 4) == 'r')
			{
				*res -= 4;
				rrr(a, res);
			}
			else
			{
				**res = 'r';
				*res += 1;
				**res = 'r';
				*res += 1;
				**res = 'b';
				*res += 1;
				**res = '\n';
				*res += 1;
			}
		}
	}
}