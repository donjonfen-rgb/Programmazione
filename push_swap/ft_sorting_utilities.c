#include "push_swap.h"

int ft_id_pippino(t_queue q)
{
	int minpo;
	int minid;
	t_node *k;
	int p;
	
	k = q.head;
	p = 0;
	minpo = 0;
	minid = k->id;
	while (k)
	{
		if (k->id < minid)
		{
			minid = k->id;
			minpo = p;
		}
		p++;
		k = k->next;
	}
	return (minpo);
}

t_node *pikmin(t_stacks s)
{}

t_node *pokemon(t_stacks s)
{}
