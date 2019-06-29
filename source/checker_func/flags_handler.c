/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:19:57 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/29 16:49:57 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			fd_collector(char *str, size_t *flags)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd > 0)
		*flags |= fd;
	else
		error_handler(0, 0);
	return (1);
}

void		flags_picker(char *str, char *fd, size_t *flags)
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
			else if (*str == 'f' && fd_collector(fd, flags))
				*flags |= DES;
			else if (*str && (*str < '0' || *str > '9'))
				error_handler(1, 0);
		}
}
