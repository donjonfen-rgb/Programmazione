#include "push_swap.h"

//0 4 12 2 10 6 9 13 3 11 7 15
void	push_swap(t_stacks *s)
{
	// printf();
	if (!s)
		return ;
	// printf("lis node: value=%d valis=%d\n", s->a.lis ? s->a.lis->value : -1, s->a.lis ? s->a.lis->valis : -1);
	// printf("a.size=%d b.size=%d\n", s->a.size, s->b.size);
	if (check_if_sortdimamt(s->a))
	return ;
	if (s->a.size <= 5)
	{
		lesortdimamt(s);
		return ;
	}
	lis_phase(&(s->a));
	// t_node *k = s->a.head;
	// while (k){printf("%d ",k->sval);k = k->next;}printf("\n");return;
	// while(k){printf("[idx=%d | val=%d | sval=%d | valis=%d | sub=%p | prev=%p | next=%p]\n", k->idx, k->value, k->sval, k->valis, (void *)k->idsubseq,(void *)k->prev,(void *)k->next);k = k->next;return ;
	inversa_lafinestra_intelligente(s);
	if (!qie(s->b))
		mc_griddy(s);
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
	// printf("sono min sval:%d.\n",ft_sval_pippino(s->a));
	// t_node *n = pikmin(s->a);
	// printf("sono pickmin id: %d\n", n->idx);
	// t_node *k = s->a.head;
	// while(k){printf("[idx=%d | val=%d | sval=%d | valis=%d | sub=%p]\n", k->idx, k->value, k->sval, k->valis, (void *)k->idsubseq);k = k->next;}
	decappler_two_point_o(s);
	return (0);
}

/*
#1 comment
	i believe something in lis is skeleton only elements doesn't work well everything finishes to be pushed in b


*/