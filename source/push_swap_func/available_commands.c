/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   available_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:38:10 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/21 21:39:00 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int			ss(t_stack **a, char **res)
{
	**res = 's';
	*res += 1;
	**res = 's';
	*res += 1;
	**res = '\n';
	*res += 1;
	return (0);
}

int 		rr(t_stack **a, char **res)
{
	**res = 'r';
	*res += 1;
	**res = 'r';
	*res += 1;
	**res = '\n';
	*res += 1;
	return (0);
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