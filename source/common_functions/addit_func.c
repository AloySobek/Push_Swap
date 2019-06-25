/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:58:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/25 21:45:56 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_stack		*new_elem_of_stack(int value, int stack)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	(*new).value = value;
	(*new).index = stack;
	(*new).next = NULL;
	(*new).prev = NULL;
	return (new);
}

int			is_sorted(t_stack *a)
{
	t_stack *iter;

	iter = a;
	if (iter && iter->next)
	{
		while (iter->next)
		{
			if (iter->value >= iter->next->value)
				return (0);
			iter = iter->next;
		}
	}
	return (1);
}

void		labeler(t_stack **a, int size)
{
	t_stack	*iter_tmp;
	t_stack	*iter_a;
	t_stack	*tmp;

	tmp = copy_stack(*a, size);
	quicksort(&tmp, 0, size - 1);
	iter_tmp = tmp;
	while (iter_tmp)
	{
		iter_a = *a;
		while (iter_a->value != iter_tmp->value)
			iter_a = iter_a->next;
		iter_a->index = iter_tmp->index + 1;
		iter_tmp = iter_tmp->next;
	}
}

void		time_collector(char **str, size_t *flags)
{
	size_t	time;

	(*str)++;
	if (**str >= '0' && **str <= '9')
	{
		*flags <<= 24;
		*flags >>= 24;
		*flags |= ((size_t)ft_atoi(*str) << 32);
	}
	_TIME__ == 0 ? *flags |= 3L << 32 : 0;
}

void 		flags_picker(int *argc, char **argv, size_t *flags)
{
	char	*args;

	args = *argv;
	if (*args++ == '-')
	{
		while (*args)
		{
			if (*args == 'v')
			{
				*flags |= DEB;
				*flags <<= 24;
				*flags >>= 24;
				time_collector(&args, flags);
			}
			else if (*args == 'c')
			{
				*flags |= COL;
				*flags <<= 24;
				*flags >>= 24;
				time_collector(&args, flags);
			}
			else if (*args == 'i')
				*flags |= INT;
			else if (*args == 'f')
				*flags |= DES;
			else if (*args < '0' || *args > '9')
				error_handler(1, 0);
			++args;
		}
	}
}

int			print_usage(void)
{
	ft_printf("Usage: Give a numeric sequence that needs to be sorted\n       ");
	ft_printf("[-v] displaing stacks during the processing\n       ");
	ft_printf("[-c] dispalaying with colour\n");
	return (1);
}

int			check_overflow(char *str)
{
	int check;

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

int			checking_args(int *argc, char ***argv, size_t *flags)
{
	char	*tmp_str;
	int		tmp;

	flags_picker(argc, (*argv)++ + 1, flags);
	if (*flags & (DEB | COL | INT | DES) && (*argv)++)
		(*argc)--;
	tmp = *argc;
	tmp_str = **argv;
	while (--tmp)
	{
		if (ft_strlen(tmp_str) > 11)
			return (0);
		if (ft_strlen(tmp_str) >= 10 && (*tmp_str == '-' ? *(tmp_str + 1) > '2' :
		*tmp_str > '2'))
			return (0);
		if (ft_strlen(tmp_str) == 10 || ft_strlen(tmp_str) == 11)
			if (check_overflow(tmp_str) == 0)
				return (0);
		while (*tmp_str && ((*tmp_str >= '0' && *tmp_str <= '9') ||
		*tmp_str == ' ' || *tmp_str == '-'))
			tmp_str++;
		if (*tmp_str)
			return (0);
		++tmp_str;
	}
	return (1);
}

void		error_handler(int code, int none)
{
	if (code)
		print_usage();
	else if (!none)
		ft_printf("Error\n");
	exit(1);
}