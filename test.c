/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:34:39 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/12 18:05:04 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(void)
{
    write(1, "pb\n", 3);
    write(1, "pb\n", 3);
    write(1, "pb\n", 3);
    write(1, "pb\n", 3);
    write(1, "pb\n", 3);
    write(1, "pb\n", 3);
    write(1, "pa\n", 3);
    write(1, "pa\n", 3);
    write(1, "pa\n", 3);
    write(1, "pa\n", 3);
    write(1, "pa\n", 3);
    write(1, "pa\n", 3);
    return (0);
}