/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:32:41 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/23 20:10:18 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *fat_lisa(t_queue q)
{
	int blis;
	int jalisse;
	t_node *k;

	k = q.head;
	blis = 0;
	while (blis <= (q.size - 1 - k->idx) && k != q.tail) // sinonimo di k.next !=NULL
	{
		jalisse = k->valis;
		if (blis < jalisse) // check best lis so far, to compare to the one it had preciously found
			blis = jalisse;
	}
	return (k);
}

void theTamingoftheShrewLisa(t_queue *q)
{
	t_node *k;
	t_node *rk;

	k = q->head->next;
	while (k && k->idx < q->size) // check size and elaborate if normal cases then ... /
	{
		rk = q->head;
		while (rk != k)
		{
			if (rk->sval < k->sval && rk->valis + 1 >= k->valis)
			{
				if (k->idsubseq == NULL || rk->sval < k->idsubseq->sval)
				{
					k->valis = rk->valis + 1;
					k->idsubseq = rk;
				}
			}
			rk = rk->next;
		}
		k = k->next;
	}
}

/*lizcheney returns the knot with the greatest lis taking into account the bestSpread*/
t_node *lizCheney(t_queue *q)
{
	t_node *k;
	t_node *rk;
	int bestlis;
	int max_spread;

	bestlis = 0;
	k = NULL;
	rk = q->head;
	max_spread = 0;
	while (rk->idx <= q->size - 1)
	{
		if (bestlis <= rk->valis && LookIn_my_gapeS(rk) >= max_spread)
		{
			bestlis = rk->valis;
			
			if(max_spread < LookIn_my_gapeS(rk))
				max_spread = LookIn_my_gapeS(rk);
			k = rk;
		}
		rk = rk->next;
	}
	q->lis = k;
	return (k);
}

int LookIn_my_gapeS(t_node *k)//y
{
	// calcolo delle lis piu' spalmate e diramate nello stack
	int gape;

	gape = k->idx;
	while (k->idsubseq)
		k = k->idsubseq;
	if (!k->idsubseq)
		gape -= k->idx;
	return (gape);
}

//used to keep the skeleton in a
bool am_i_into_Lisa(t_node *rk, t_node *lk)
{
	while (lk) //verra' sempre considerato il primo elemento di lis' come non appartenente alla coda. cercare nuovo comando o eseguire tramite il -1 affibbiato a tutti gli elementi non lis e anche li'' il comando non funziona. dovrebbe essere aggiustato (lk) from (lk->idsubseq)
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
			rk->valis = -1;
		rk = rk->next;
	}
}

bool isqmadeonlyoflisskeletonelements(t_queue q)//y
{
	return (q.size == q.lis->valis);
}

void	lis_phase(t_queue *q)
{
	if (!q || !q->head || q->size < 2)
		return ;
	ft_howMuchisPastrami(*q);
	theTamingoftheShrewLisa(q);
	lizCheney(q);
	lisEandataVia(q);
}