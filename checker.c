/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:11:01 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/11 17:30:59 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char *line;

    while (get_next_line(0, &line) == 1)
        printf("%s\n", line);
    return (0);
}