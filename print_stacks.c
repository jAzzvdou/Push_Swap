/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:38:50 by jazevedo          #+#    #+#             */
/*   Updated: 2024/02/06 14:40:10 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	print_stacks(t_pushswap *ps)
{
	t_stack	*a;
	t_stack	*b;

	a = ps->a;
	b = ps->b;
	while (a || b)
	{
		if (a) 
		{
			printf("%11d", a->value);
			a = a->next;
		}
		if (b)
		{
			printf("%11d", b->value);
			b = b->next;
		}
		printf("\n");
	}
	return (0);
}