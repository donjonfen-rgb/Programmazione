#include "push_swap.h"

int ft_sval_pippino(t_queue q)
{
	int minpo;
	int minid;
	t_node *k;
	int p;
	
	k = q.head;
	p = 0;
	minpo = 0;
	minid = k->sval;
	while (k)
	{
		if (k->sval < minid)
		{
			minid = k->sval;
			minpo = p;
		}
		p++;
		k = k->next;
	}
	return (minpo);
}

//churro is the chunk size so any value < than churro the first value would be good
// per ora scrivi tutto qui per pikmin che dovra' calcolare: dato lo stack, il minimo sval valutando anche la posizione, come effettuare la proporzione tra i due valori. individuando il costo della prossima mossa. Dunque partendo dallo sval piu' piccolo e individuandone la pos. Architecture of the minimum: be it costs or idx
t_node *pikmin(t_queue q)
{
	t_node *k;
	t_node *l_k;

	if (!q.head)
		return (NULL);
	k = q.head;
	l_k = k;
	while (k)
	{
		if (k->sval < l_k->sval)
			l_k = k;
		k = k->next;
	}
	return (l_k);
}

t_node *pokmon(t_queue q)
{
	t_node *k;
	t_node *b_k;

	if (!q.head)
		return (NULL);
	k = q.head;
	b_k = k;
	while (k)
	{
		if (k->sval > b_k->sval)
			b_k = k;
		k = k->next;
	}
	return (b_k);
}
