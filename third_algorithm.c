#include "push_swap.h"

#include <stdio.h>

int	check_range(t_stack *stack, int *array, int start, int end)
{
	int	i;

	while (stack)
	{
		i = start - 1;
		while (++i <= end)
			if (stack->index == array[i])
				return (1);
		stack = stack->next;
	}
	return (0);

}

void	third_algorithm(t_pushswap *ps, int size)
{
	int range = set_range(size);

	int *array = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, array, size);

	int start = ((size / 2)) - range;
	int end = ((size / 2) + (size % 2)) + (range - 1);

	while (ps->a->next)
	{
		int index = -1;
		int size_a = stack_size(ps->a);
		while (check_range(ps->a, array, start, end) && ++index < size_a)
		{
			int i = start - 1;
			while (++i <= end)
				if (ps->a->index == array[i])
					pb(ps);
			if (i > end)
			{
				if (stack_size(ps->b) > 1
					&& ps->b->index < ps->b->next->index)
					rr(ps);
				else
					ra(ps);
			}
			//print_stacks(ps);
		}
		start -= range;
		if (start < 0)
			start = 0;
		end += range;
		if (end > size - 1)
			end = size - 1;
	}
}
