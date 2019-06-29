/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:28:50 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 19:11:44 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_optimizer(int where, char **act)
{
	if (*(*act - 3) == 'p' && *(*act - 2) == (!where ? 'a' : 'b'))
		*act -= 3;
	else
	{
		*(*act)++ = 'p';
		*(*act)++ = !where ? 'b' : 'a';
		*(*act)++ = '\n';
	}
}

void		swap_optimizer(int where, char **act)
{
	if (*(*act - 3) == 's' && *(*act - 2) == (!where ? 'a' : 'b'))
		*act -= 3;
	else
	{
		if (*(*act - 3) == 's' && *(*act - 2) == (!where ? 'b' : 'a'))
		{
			*act -= 3;
			*(*act)++ = 's';
			*(*act)++ = 's';
			*(*act)++ = '\n';
		}
		else
		{
			*(*act)++ = 's';
			*(*act)++ = !where ? 'a' : 'b';
			*(*act)++ = '\n';
		}
	}
}

void		rotate_optimizer(int where, char **act)
{
	if (*(*act - 4) == 'r' && *(*act - 2) == (!where ? 'a' : 'b'))
		*act -= 4;
	else
	{
		if (*(*act - 4) == '\n' && *(*act - 3) == 'r' &&
		*(*act - 2) == (!where ? 'b' : 'a'))
		{
			*act -= 3;
			*(*act)++ = 'r';
			*(*act)++ = 'r';
			*(*act)++ = '\n';
		}
		else
		{
			*(*act)++ = 'r';
			*(*act)++ = !where ? 'a' : 'b';
			*(*act)++ = '\n';
		}
	}
}

void		reverse_optimizer(int where, char **act)
{
	if (*(*act - 2) == (!where ? 'a' : 'b')
	&& *(*act - 4) == '\n' && *(*act - 3) == 'r')
		*act -= 3;
	else
	{
		if (*(*act - 4) == 'r' && *(*act - 2) == (!where ? 'b' : 'a'))
		{
			*act -= 4;
			*(*act)++ = 'r';
			*(*act)++ = 'r';
			*(*act)++ = 'r';
			*(*act)++ = '\n';
		}
		else
		{
			*(*act)++ = 'r';
			*(*act)++ = 'r';
			*(*act)++ = !where ? 'a' : 'b';
			*(*act)++ = '\n';
		}
	}
}
