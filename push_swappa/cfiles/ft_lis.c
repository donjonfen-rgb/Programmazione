/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:32:41 by ggaritta          #+#    #+#             */
/*   Updated: 2026/05/03 20:40:47 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check best lis so far, to compare to the one it had preciously found
t_node *fat_lisa(t_queue q)
{
	int blis;
	int jalisse;
	t_node *k;
	t_node	*rk;

	k = NULL;
	rk = q.head;
	blis = 0;
	while (rk)
	{
		jalisse = rk->valis;
		if (blis < jalisse)
		{
			k = rk;
			blis = jalisse;
		}
		rk = rk->next;
	}
	return (k);
}

// void tappami_levante()
// {
	// the middle of the taming;
// }

t_node	*am_i_next(t_queue q, t_node *n)
{
	if (n->next)
		return (n->next);
	else
		return (q.head);
}
void	theTamingoftheShrewLisa(t_queue *q)
{
	t_node	*k;
	t_node	*rk;
	t_node	*starto;

	starto = pikmin(*q);
	k = am_i_next(*q, starto);
	while (k != starto)//(k && k->idx < q->size)old
	{
		rk = starto;
		while (rk != k)
		{
			if (rk->sval < k->sval && rk->valis + 1 >= k->valis)
			{
				if (rk->valis + 1 > k->valis)
				{
					k->valis = rk->valis + 1;
					k->idsubseq = rk;
				}
				else if (k->idsubseq && rk->sval < k->idsubseq->sval)
					k->idsubseq = rk;
			}
			rk =am_i_next(*q, rk);
		}
		k =am_i_next(*q, k);
	}
}

/*lizcheney returns the knot with the greatest lis taking into account the bestSpread*/
void lizCheney(t_queue *q)
{
	t_node *k;
	t_node *rk;
	int bestlis;
	int max_spread;

	k = fat_lisa(*q);
	bestlis = k->valis;
	rk = q->head;
	max_spread = LookIn_my_gapeS(k);
	while (rk && rk->idx <= q->size - 1)
	{
		if (rk->valis == bestlis && LookIn_my_gapeS(rk) >= max_spread)
		{
			bestlis = rk->valis;
			if(max_spread < LookIn_my_gapeS(rk))
				max_spread = LookIn_my_gapeS(rk);
			k = rk;
		}
		rk = rk->next;
	}
	q->lis = k;
}

int LookIn_my_gapeS(t_node *k)//y
{
	// calcolo delle lis piu' spalmate e diramate nello stack
	int	gape;
	int	sval;

	if (!k)
		return (0);
	gape = k->sval;
	while (k->idsubseq)
	{
		sval = k->sval;
		k = k->idsubseq;
	}
	return (gape - sval);
}

//used to keep the skeleton in a
bool am_i_into_Lisa(t_node *rk, t_node *lk)
{
	while (lk)
	{
		if (rk->sval == lk->sval)
			return (true);
		if (lk->idsubseq)
			lk = lk->idsubseq;
		else
			return (false);
	}
	return (false);
}

/*it's a cleaning func, impostare tutti gli elementi non in q.lis a -1 cosi'
 da velocizzare successivamente i controlli per pushingB phase2 */
void lisEandataVia (t_queue *q)
{
	t_node *lk;
	t_node *rk;

	rk = q->head;
	lk = q->lis;
	//rush the queue and check if it's in amintolisa
	while(rk)
	{
		if (!(am_i_into_Lisa(rk,lk)))
		{
			rk->valis = -1;
			rk->idsubseq = NULL;
		}
		rk = rk->next;
	}
}

bool isqmadeonlyoflisskeletonelements(t_queue q)//y
{
	if (!q.head)
		return (false);
	return (q.size == q.lis->valis);
}

void	lis_phase(t_queue *q)
{
	if (!q || !q->head || q->size < 2)
		return ;
	ft_howMuchisPastrami(q);
	theTamingoftheShrewLisa(q);
	lizCheney(q);
	lisEandataVia(q);
}
