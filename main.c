#include "push_swap.h"

void	free_everything(t_pushswap *ps)
{
	t_node	*tmp;

	while (ps->a->top)
	{
		tmp = ps->a->top;
		ps->a->top = ps->a->top->prev;
		free(tmp);
	}
	free(ps->a);
	while (ps->b->top)
	{
		tmp = ps->b->top;
		ps->b->top = ps->b->top->prev;
		free(tmp);
	}
	free(ps->b);
}

int	argvs_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	invalid_arguments(t_pushswap *ps, int argc, char **argv)
{
	if (argc < 2)
		return (1);
	argv++;
	if (!verify_argv(argv))
		return (write(2, "Error\n", 6));
	if (!is_int(argv))
		return (write(2, "Error\n", 6));
	if (is_duplicated(argv))
		return (write(2, "Error\n", 6));
	put_in_stack(ps, argc, argv);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	ps = (t_pushswap){0};
	if (invalid_arguments(&ps, argc, argv))
		return (1);
	if (!is_sorted(ps.a) || ps.b->size)
	{
		if (ps.a->size == 2 && ps.a->top->value > ps.a->top->prev->value)
			sa(&ps);
		else if (ps.a->size == 3)
			first_algorithm(&ps);
		else if (ps.a->size <= 5)
			second_algorithm(&ps);
		else
			third_algorithm(&ps);
	}
	free_everything(&ps);
	return (0);
}
