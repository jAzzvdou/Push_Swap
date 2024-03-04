/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:18:32 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/04 13:18:33 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int	i;
	int	size;
	int	*array;

	size = stack_size(stack);
	array = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		array[i] = stack->value;
		stack = stack->next;
	}
	return (array);
}

int	*bubblesort(int *stack, int size)
{
	int	i;
	int	ii;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		ii = i;
		while (++ii < size)
		{
			if (stack[i] > stack[ii])
			{
				tmp = stack[i];
				stack[i] = stack[ii];
				stack[ii] = tmp;
			}
		}
	}
	return (stack);
}

void	set_index(t_stack *stack, int *array, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == array[i])
				stack->index = i;
			i++;
		}
		stack = stack->next;
	}
}
