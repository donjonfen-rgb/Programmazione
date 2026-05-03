/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chonkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:26:26 by ggaritta          #+#    #+#             */
/*   Updated: 2026/05/02 22:27:31 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//movements prev nd next
//next knot inside the chunk cost to push by next rotation and isn't in lis
t_node *nrnktp(t_stacks *s, int cs, int ce)
{
	int		i;
	int		j;
	t_node	*k;
	t_node	*nod;

	i = nextrotmormid(s->a, cs, ce);
	j = nextrotlessmid(s->a, cs, ce);
	k = fifnk(*s, i);
	nod = fifnk(*s, j);
	if (!k)
		return (nod);
	if (!nod)
		return (k);
	if (i < j)
		return (k);
	return (nod);
}
t_node *prnktp(t_stacks *s, int cs, int ce)
{
	int		i;
	int		j;
	t_node	*k;
	t_node	*nod;

	i = prevrotmormid(s->a, cs, ce);
	j = prevrotlessmid(s->a, cs, ce);
	k = fifpk(*s, i);
	nod = fifpk(*s, j);
	if (!k && !nod)
		return (NULL);
	if (!k)
		return (nod);
	if (!nod)
		return (k);
	if (i < j)
		return (k);
	return (nod);
}

// t_node *nrnktp(t_queue q, int ce)
// {
// 	t_node *k;

// 	k = q.head;
// 	while (k)
// 	{
// 		if (r_u_chuck_schumer(k, ce))
// 			return (k);
// 		k = k->next;
// 	}
// 	return (NULL);
// }

// t_node *prnktp(t_queue q, int ce)
// {
// 	t_node *k;

// 	k = q.tail;
// 	while (k)
// 	{
// 		if (r_u_chuck_schumer(k, ce))
// 			return (k);
// 		k = k->prev;
// 	}
// 	return (NULL);
// }

//prnktp next knot cost to push by prev rotation which is not into lis
// t_node *prnktp(t_queue q, int cs, int ce)
// {
// 	int		i;
// 	int		j;
// 	t_node	*k;
// 	t_node	*nod;
// 	i = prevrotmormid(q, cs, ce);
// 	j = prevrotlessmid(q, cs, ce);
// 	k = step_from_tail(q, i);
// 	nod = step_from_tail(q, j);
// 	if (!k)
// 		return (nod);
// 	if (!nod)
// 		return (k);
// 	if (i < j)
// 		return (k);
// 	return (nod);
// }

void	findbestrottenknot(t_stacks *s, int *chus, int *chue)
{
	t_node *p;
	t_node *n;

	p = prnktp(s, *chus, *chue);
	n = nrnktp(s, *chus, *chue);
	if (!p && !n)
	{
		if (isqmadeonlyoflisskeletonelements(s->a))
			return ;
		ceiling(*s, chus, chue);
		return ;
	}
	else if (!p)
		reachnexttop(&s->a, n);
	else if (!n)
		reachprevtop(&s->a, p);
	else
		findrotation(&s->a, p, n);
	if (s->a.head == p || s->a.head == n)
		push_me_knot(s, chus, chue);
	// printf("after pushmeknot");
	//print_stacks(s);
	givemefunction(s, chus, chue);
	// printf("Found node sval: %d, moving to top\n", n->sval);
}

//func that will fav rr rotations if possible by equal cost.
void	predict_me_Knot(t_stacks *s, int *cs, int *ce)
{
	int rot_k[4];
	int best_next;
	int best_prev;

	rot_k[0] = nextrotmormid(s->a, *cs, *ce);
	rot_k[1] = nextrotlessmid(s->a, *cs, *ce);
	rot_k[2] = prevrotmormid(s->a, *cs, *ce);
	rot_k[3] = prevrotlessmid(s->a, *cs, *ce);
	if ((rot_k[1] <= rot_k[0]) && (rot_k[3] <= rot_k[2]))
		save_me_rot(s, fifpk(*s, rot_k[3]), fifnk(*s, rot_k[1]), cs, ce);
	else if (rot_k[0] < rot_k[1] && (rot_k[2] <= rot_k[3]))
		save_me_rot(s, fifpk(*s, rot_k[2]), fifnk(*s, rot_k[0]), cs, ce);
	else
	{
		if (rot_k[1] <= rot_k[0])
			best_next = rot_k[1];
		else
			best_next = rot_k[0];
		if (rot_k[3] <= rot_k[2])
			best_prev = rot_k[3];
		else
			best_prev = rot_k[2];
		save_me_rot(s, fifpk(*s, best_prev), fifnk(*s, best_next), cs, ce);
	}
	//print_stacks(s);
}

void inversa_lafinestra_intelligente(t_stacks *s)
{
	int	cs;
	int	ce;

	
	cs = 0;
	ce = chunk_size(s->a.size);
	// printf("ce%d chsize:%d\n",ce,chunk_size(s->a.size));
	// return ;
	while (!isqmadeonlyoflisskeletonelements(s->a))
	{
		// if (s->b.head && (s->b.head->sval <= (cs - 1 + ce - 1) / 2))
		// 	predict_me_Knot(s, &cs, &ce);
		findbestrottenknot(s, &cs, &ce);
		// printf("after findbestrottenknot s.a.size: %d\n",s->a.size);
		// //print_stacks(s);
		if (s->b.head && (s->b.head->sval <= (cs - 1 + ce - 1) / 2))
			predict_me_Knot(s, &cs, &ce);
		// printf("after predictmenot s.a.size: %d\n",s->a.size);
		// //print_stacks(s);
	}
}

/*
che e sta merda

void findbestrottenknot(t_stacks *s, int *chus, int *chue)
{
	t_coord xy[2];
	t_coord best;
	int     mid;
	int     next_n_cost;
	int     next_p_cost;

	// 1. Gather candidates from both directions
	xy[0].ak = nrnktp(s->a, *chus, *chue);
	xy[1].ak = prnktp(s->a, *chus, *chue);

	// Safety Net: If no nodes are found, slide the window and exit this iteration
	if (!xy[0].ak && !xy[1].ak)
	{
		(*chus)++;
		(*chue)++;
		return ;
	}

	// 2. Assign costs and directions (Use INT_MAX if node is NULL)
	xy[0].ac = xy[0].ak ? nrotcost(s->a, xy[0].ak) : INT_MAX;
	xy[0].adir = 'n';
	xy[1].ac = xy[1].ak ? protcost(s->a, xy[1].ak) : INT_MAX;
	xy[1].adir = 'p';

	// 3. Determine the cheapest node
	if (xy[0].ac <= xy[1].ac)
		best = xy[0];
	else
		best = xy[1];

	// 4. Execute rotations to bring the best node to the top of A
	if (best.adir == 'n')
		reachnexttop(&s->a, best.ak); // Assuming this loops 'ra' until ak is head
	else
		reachprevtop(&s->a, best.ak); // Assuming this loops 'rra' until ak is head

	// 5. Push to B (This executes 'pb' and handles the ceiling logic)
	push_me_knot(s, chus, chue);

	// 6. The Concrete Lookahead & Routing Logic
	mid = ch_malcolm_in_the_middle(*chus, *chue);
	if (s->b.head && s->b.head->sval <= mid)
	{
		// The node we just pushed belongs at the bottom of B. 
		// We MUST rotate B. Let's see if we can do an `rr` to help stack A.
		
		xy[0].ak = nrnktp(s->a, *chus, *chue);
		xy[1].ak = prnktp(s->a, *chus, *chue);
		
		next_n_cost = xy[0].ak ? nrotcost(s->a, xy[0].ak) : INT_MAX;
		next_p_cost = xy[1].ak ? protcost(s->a, xy[1].ak) : INT_MAX;

		// If there is a next node, AND it prefers 'ra' (next direction), AND it isn't already on top (> 0)
		if (xy[0].ak && next_n_cost <= next_p_cost && next_n_cost > 0)
			rr(s); // Executes BOTH rb (which we need) and ra (which helps A for the next loop)
		else
			rb(&s->b); // No optimization possible, just route the B node to the bottom
	}
}
*/
/*how to remove from chunk count the lis elements, how to avoid from the calculation the lis elements.*/
// comportamento_pushin_Boromir
// void push_in_Boromir()//give_me_the_ring_Boromir , push_in_Boromir
// {
// 	while (i=1 <= maxchunk)//with sliding window no need for maxchunks but need to keep checked the chuend to max n
// 	chunkrange = i * chunksize OR chunkrange+=chunksize; either way if(chunkrange > listelements) chunkrange -> n OR n-1. as it is now, works as n anyway if it starts from 1 it is <= as always. // must apply sliding window
// 	while(currentchunk=0 < chunkrange) is it 0 cause we working with indexes and it equals it
// 	if k found (controllare quale dei due e minore ) is entro range (range will be chunkrange(it is the ceiling) OR chuart < k.sval < chuend)
// 	if (value >= midchunk(midchunk = chuart + chuend /2))
// 	push b
// 	start and end ++;
// 	else
// 	push b but you need to rotateb after having checked nextknotina
// 		before rotating check for next element in astack if it needs to be rotated also and do them both which means next has to be prioritized in equal cases
// 	currentchunk++;
// 	i++;
// }
// movement that prefers the repetition of the rotate instead of the simple pushb
/*↓↓ useless stuff ↓↓*/
//findnextmincostbyprevrotation
// int fnxtmincostprevrot(t_queue *q, t_node *lookforme)//sostituita?? sbagliata!!!
// {
// 	t_node *k;
// 	k = q->tail;
// 	lookforme = pikmin(q);
// 	while(k->prev != lookforme)
// 	k = k->prev;
// 	return (k->idx);
// }
//GREEDY - funzione che controlla quante ripetizioni sono in comune