#include "push_swap.h"

int	inside_stack(t_stack *stack, int index, int size)
{
	int		i;
	int		nb;
	t_node	*node;

	node = stack->top;
	nb = 0;
	i = 0;
	while (i < size && node)
	{
		nb = node->index;
		if (nb == index)
			return (i);
		i++;
		node = node->prev;
	}
	return (-1);
}

int	sort_a(t_pushswap *ps, int *up, int *down, int highest)
{
	if (ps->a->size == 0)
		return (0);
	if (inside_stack(ps->a, highest, *up) != -1)
	{
		*up = *up - 1;
		return (1);
	}
	else if (ps->a->size && ps->a->bot->index == highest)
	{
		rra(ps);
		*down = *down - 1;
		return (1);
	}
	return (0);
}

void	order(t_pushswap *ps, int *up, int *down)
{
	while (*up > 1)
	{
		ra(ps);
		*up = *up - 1;
		*down = *down + 1;
	}
	pa(ps);
	if (*up == 1)
		sa(ps);
}

int	canpush(t_pushswap *ps, int *up, int *down)
{
	if (!ps->b->size)
		return (0);
	if (ps->b->top->index < ps->a->top->index
		&& (*down == 0 || ps->b->top->index > ps->a->bot->index))
	{
		pa(ps);
		*up = *up + 1;
		return (1);
	}
	else if (*down == 0 || ps->b->top->index > ps->a->bot->index)
	{
		while (*up && ps->b->top->index > ps->a->top->index)
		{
			ra(ps);
			*up = *up - 1;
			*down = *down + 1;
		}
		pa(ps);
		*up = *up + 1;
		return (1);
	}
	return (0);
}

int	to_top(t_pushswap *ps, int highest)
{
	int	ihighest;

	if (ps->b->size == 0)
		return (0);
	ihighest = inside_stack(ps->b, highest, ps->b->size);
	if (ihighest != -1 && ihighest < (ps->b->size / 2))
	{
		rb(ps);
		ihighest--;
		return (1);
	}
	else if (ihighest != -1 && ihighest < ps->b->size)
	{
		rrb(ps);
		ihighest++;
		return (1);
	}
	else
		return (0);
}
