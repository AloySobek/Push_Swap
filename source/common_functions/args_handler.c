/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:09:16 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/26 20:24:43 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_overflow(char *str)
{
	int		check;

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

void		flags_picker(int *argc, char ***argv, size_t *flags)
{
	char	*args;

	args = *++(*argv);
	if (*args == '-')
		while (*args++)
		{
			if (*args == 'v' && (*flags |= DEB))
			{
				*flags <<= 24;
				*flags >>= 24;
				time_collector(args, flags);
			}
			else if (*args == 'c' && (*flags |= COL))
			{
				*flags <<= 24;
				*flags >>= 24;
				time_collector(args, flags);
			}
			else if (*args == 'i')
				*flags |= INT;
			else if (*args == 'f' && fd_collector(++(*argv), flags))
				*flags |= DES;
			else if (*args && (*args < '0' || *args > '9'))
				error_handler(1, 0);
		}
}

int			checking_args(int *argc, char ***argv, size_t *flags)
{
	char	*tmp_str;
	int		tmp;

	flags ? flags_picker(argc, argv, flags) : ++(*argv);
	if (flags && (*flags & (DEB | COL | INT | DES) && ++(*argv)))
		*flags & DES ? (*argc) -= 2 : --(*argc);
	tmp = *argc;
	tmp_str = **argv;
	while (--tmp)
	{
		if (ft_strlen(tmp_str) > 11)
			return (0);
		if (ft_strlen(tmp_str) >= 10 && (*tmp_str == '-' ? *(tmp_str + 1) >
		'2' : *tmp_str > '2'))
			return (0);
		if (ft_strlen(tmp_str) == 10 || ft_strlen(tmp_str) == 11)
			if (check_overflow(tmp_str) == 0)
				return (0);
		while (*tmp_str && ((*tmp_str >= '0' && *tmp_str <= '9') ||
		*tmp_str == ' ' || *tmp_str == '-'))
			tmp_str++;
		if (*tmp_str++)
			return (0);
	}
	return (1);
}
