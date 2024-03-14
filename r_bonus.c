/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:42:47 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/14 12:43:10 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2)
		return ;
	rotate(ps->a);
	write(1, "ra\n", 3);
}

void	rb(t_pushswap *ps)
{
	if (!ps->b || ps->b->size < 2)
		return ;
	rotate(ps->b);
	write(1, "rb\n", 3);
}

void	rr(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2 || !ps->b || ps->b->size < 2)
		return ;
	ra(ps);
	rb(ps);
	write(1, "rr\n", 3);
}
