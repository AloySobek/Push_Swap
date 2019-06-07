/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrichese <vrichese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:04:56 by vrichese          #+#    #+#             */
/*   Updated: 2019/06/07 20:49:01 by vrichese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

void			push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*tmp).next;
		(*tmp).next = *b;
		*b = tmp;
	}
}

void			swap(t_stack **a)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		tmp = (**a).next;
		(**a).next = (*tmp).next;
		(*tmp).next = *a;
		*a = tmp;
	}
}

void			rotate(t_stack **a)
{
	t_stack *tmp;
	t_stack *iter;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (**a).next;
		iter = *a;
		while ((*iter).next)
			iter = (*iter).next;
		(*iter).next = tmp;
		(*tmp).next = NULL;
	}
}

void			rotate_reverse(t_stack **a)
{
	t_stack *iter;

	if (*a && (*a)->next)
	{
		iter = *a;
		while (iter->next->next)
			iter = iter->next;
		iter->next->next = *a;
		*a = iter->next;
		iter->next = NULL;
	}
}

t_stack			*new_elem_of_stack(int value)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	(*new).value = value;
	(*new).next = NULL;
	return (new);
}

int main(int argc, char **argv)
{
	t_stack *hello;
	t_stack *iter;
	int i;

	hello = new_elem_of_stack(0);
	iter = hello;
	i = 1;
	while (i < argc)
	{
		iter->value = atoi(argv[i++]);
		iter->next = new_elem_of_stack(0);
		iter = iter->next;
	}
	while (hello->next)
	{
		printf("%d\n", hello->value);
		hello = hello->next;
	}
	/* t_stack *one;
	t_stack *two;

	one = new_elem_of_stack(14);
	two = new_elem_of_stack(22);
	(*one).next = new_elem_of_stack(9);
	(*two).next = new_elem_of_stack(18);
	(*((*one).next)).next = new_elem_of_stack(17);
	//(*((*two).next)).next = new_elem_of_stack(4);
	//push(&two, &one);
	//swap(&one);
	//rotate(&two);
	//rotate_reverse(&two);
	while (one)
	{
		printf("%d\n", (*one).value);
		one = (*one).next;
	}
	printf("\n---\n\n");
	while (two)
	{
		printf("%d\n", (*two).value);
		two = (*two).next;
	}*/
	return (0);
}