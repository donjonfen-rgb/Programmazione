/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chonkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:26:26 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/06 23:00:20 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* how to set up different chunks, 100 at least 3 and 500 5, what if more? do i need to care? 
the chunks work on the sval, "while current chunk has unpushed elements" this seems to be an important condition, since you can't go on to the next chunk.
what does this mean: 
while current chunk has unpushed elements:
	if top of a belongs to current chunk:
		pb
		if top of b rank > chunk_midpoint:
			rb      ← sends it deeper, keeps larger ranks near top
	else:
		ra

too many chunks and the scanning process will cost way too much, keeping it simple and less chunks and decent chunksizes
------
int chunk_mid = chunk_start + (chunk_size / 2);

// after pb:
if (top_of_b->rank >= chunk_mid)
	rb();   // sink it, larger ranks go deeper within the chunk top region
```
This is what gives each chunk its internal descending order. Without this, elements within a chunk land in arbitrary order and greedy insertion pays higher `rb`/`rrb` costs.

**6. You do not need to complete one chunk before starting the next**

Some implementations scan `a` once per chunk. A more efficient approach scans `a` continuously and tracks which chunk is currently being filled, advancing to the next chunk automatically when the current one is full. This reduces total `ra` operations significantly because you make one pass over `a` per chunk rather than potentially multiple.

**7. b will not be perfectly sorted — and that is fine**

Chunking produces a rough descending order, not a perfect one. Greedy cost insertion handles the imperfection. Do not try to make `b` perfectly sorted during phase 1 — the cost of perfect ordering outweighs the benefit. Rough is enough.

**The state you are handing to greedy after phase 1**
```
a:  contains only LIS skeleton elements, in their original relative order
b:  contains all non-LIS elements, roughly descending by rank top to bottom
------
the chunk size remains a mistery but we can calculate if the sval is into the chunk by doing: 
- chunk start = chunk index * chunk size; <- greatest incognita eva so far
- chunk end = chunk start + chunk size-1
is the node into? -> CS < k.idx < CE;
fine LIS

WHAT IS THIS?
####
chunk_end = ft_min(chunk_start + chunk_size - 1, n - 1);
####

ALWAYS CONSIDER THE NON SKELETON NODES, calculate at each push how the next node is cheaper to push through ra or rra.
*/

// void chunk_norris(t_stacks *s, void doublerotation())//<-what is this doublerot?
// {
// 	//funzione finale contenente il chunk gen behaviour
// }

// typedef void (*func)(t_queue*, int);
	/*whenever i'm going to use it i'll call the name of the function and put it FirstUppercase and name var qualsiasi. expecting in (everything it needs to work)*/

//movements prev nd next
//next knot inside the chunk cost to push by next rotation and isn't in lis
t_node *nrnktp(t_queue q, int cs, int ce)
{
	t_node *k;
	t_node *nod;
	int i;
	int j;

	i = 0;
	k = q.head;
	while (!((k->sval > (cs + ce) / 2) && k->sval <= ce)
		|| am_i_into_Lisa(k, q.lis))//the last two are equivalent methods to 
	{
		i++;
		k = k->next;
	}
	j = 0;
	nod = q.head;
	while (!(nod->sval <= (cs + ce) / 2) || am_i_into_Lisa(nod, q.lis))
	{
		j++;
		nod = nod->next;
	}
	if (i < j)
		return (k);
	else if (j <= i)
		return (nod);
	//which is equal to k.idx; same for the prev, if i were to keep updating the idx at each movement
}

//prnktp next knot cost to push by prev rotation which is not into lis
t_node *prnktp(t_queue q, int cs, int ce)
{
	t_node *k;
	t_node *nod;
	int i;
	int j;

	i = 0;
	k = q.tail;
	while (!((k->sval > (cs + ce) / 2) && k->sval <= ce)
		|| am_i_into_Lisa(k, q.lis))
	{
		i++;
		k = k->prev;
	}
	nod = q.tail;
	j = 0;
	while (!(nod->sval <= (cs + ce) / 2) || am_i_into_Lisa(nod, q.lis))
	{
		j++;
		nod = nod->prev;
	}
	if (i < j)
		return (k);
	return (nod);
}

void inversa_lafinestra_intelligente(t_stacks *s)
{
	int *cs;
	int *ce;

	cs = 0;
	ce = chunk_size(s->a.size - s->a.lis->valis);
	while (!isqmadeonlyoflisskeletonelements(s->a))
	{
		findbestrottenknot(s, cs, ce);
		if ((s->b.head->sval <= (*cs - 1 + *ce - 1) / 2))
			predict_me_Knot(s, cs, ce);//if next knot happens to be on next then do rr other wise rb
	}
}
























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