#include "push_swap_bonus.h"

void	rra(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2)
		return ;
	reverse_rotate(ps->a);
}

void	rrb(t_pushswap *ps)
{
	if (!ps->b || ps->b->size < 2)
		return ;
	reverse_rotate(ps->b);
}

void	rrr(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2 || !ps->b || ps->b->size < 2)
		return ;
	rra(ps);
	rrb(ps);
}
