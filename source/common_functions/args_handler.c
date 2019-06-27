/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:09:16 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/27 20:35:23 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_overflow(char *str, int minus)
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

void		time_collector(char *str, size_t *flags)
{
	size_t	time;

	str++;
	if (*str >= '0' && *str <= '9')
	{
		*flags <<= 24;
		*flags >>= 24;
		*flags |= ((size_t)ft_atoi(str) << 32);
	}
	_TIME__ == 0 ? *flags |= 3L << 32 : 0;
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

void		flags_picker(char *str, size_t *flags)
{
	if (*str == '-')
		while (*str++)
		{
			if (*str == 'v' && (*flags |= DEB))
			{
				*flags <<= 24;
				*flags >>= 24;
				time_collector(str, flags);
			}
			else if (*str == 'c' && (*flags |= COL))
			{
				*flags <<= 24;
				*flags >>= 24;
				time_collector(str, flags);
			}
			else if (*str == 'i')
				*flags |= INT;
			else if (*str == 'f' && fd_collector(++str, flags))
				*flags |= DES;
			else if (*str && (*str < '0' || *str > '9'))
				error_handler(1, 0);
		}
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
