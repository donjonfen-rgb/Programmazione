#include "push_swap.h"

void	precontrols(void)
{
}

static void	run_chunk_phase(t_stacks *s)
{
	(void)s;
}

static void	run_greedy_phase(t_stacks *s)
{
	(void)s;
}

void	push_swap(t_stacks *s)
{
	if (!s)
		return ;
	lis_phase(&s->a);
	if (check_if_sortdimamt(s->a))
		return ;
	if (s->a.size <= 5)
	{
		lesortdimamt(s);
		return ;
	}
	run_chunk_phase(s);
	run_greedy_phase(s);
}

int	main(int ac, char **av)
{
	t_stacks	*s;

	if (ac < 2)
		return (0);
	s = create_stacks();
	if (!s)
		return (1);
	if (!alltheknots(s, ac, av))
		return (exit_error(s));
	if (s->a.size < 2)
	{
		decappler_two_point_o(s);
		return (0);
	}
	push_swap(s);
	decappler_two_point_o(s);
	return (0);
}