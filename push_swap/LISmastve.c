/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LISmastve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 20:59:30 by ggaritta          #+#    #+#             */
/*   Updated: 2026/03/28 19:38:32 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // Find the node that starts the Longest Increasing Subsequence (LIS)
// t_node *find_lis_starter(t_node *head)
// {
	// 	t_node *curr, *start, *best_start = NULL;
	// 	int max_len = 0, curr_len, i = 0, best_idx = 0, idx = 0;
	// 	t_node *runner, *prev, *tmp;
	// 	int last_val;
	// 	int total_len = 0;
	// 	for (tmp = head; tmp; tmp = tmp->next)
	// 		total_len++;
	// 	for (start = head; start; start = start->next, idx++)
	// 	{
		// 		curr_len = 1;
		// 		last_val = start->value;
		// 		runner = start->next;
		// 		while (runner)
		// 		{
			// 			if (runner->value > last_val)
			// 			{
				// 				curr_len++;
				// 				last_val = runner->value;
				// 			}
				// 			runner = runner->next;
				// 		}
				// 		if (curr_len > max_len)
				// 		{
					// 			max_len = curr_len;
// 			best_start = start;
// 			best_idx = idx;
// 		}
// 		if (total_len - idx <= max_len)
// 			break;
// 	}
// 	return best_start;
// }
// // Helper to get list length
// int list_len(t_node *head)
// {
	// 	int len = 0;
	// 	while (head)
	// 	{
		// 		len++;
		// 		head = head->next;
		// 	}
		// 	return len;
		// }
// // Helper to get node at index
		// static t_node *node_at(t_node *head, int idx)
		// {
			// 	while (idx-- && head)
			// 		head = head->next;
			// 	return head;
			// }
// // Compute LIS lengths for each node
			// void lis_lengths(t_node *head, int *dp)
			// {
				// 	int n = list_len(head);
				// 	for (int i = 0; i < n; i++)
				// 	{
// 		dp[i] = 1;
// 		for (int j = 0; j < i; j++)
// 		{
	// 			if (node_at(head, j)->value < node_at(head, i)->value && dp[j] + 1 > dp[i])
	// 				dp[i] = dp[j] + 1;
	// 		}
	// 	}
	// }
// // Return LIS value (length)
	// int lis_value(t_node *head)
	// {
		// 	int n = list_len(head), max = 0;
		// 	int dp[1024]; // adjust size as needed
		// 	lis_lengths(head, dp);
		// 	for (int i = 0; i < n; i++)
		// 		if (dp[i] > max)
		// 			max = dp[i];
		// 	return max;
		// }
		// ######################################################################################
/*per trovare il lis il metodo del longest che cosa mi dovra' tornare?
		int del valore o id? da ritrovare o direttamente il node?*/

/*cercare il lis.
scorrere la lista a partire da head.
conservare il valore ottenuto per futuro paragone e il nodo di riferimento
aggiornare il punto di partenza e avanzare*/
/*need to change the struct of this one cause of it's better understanding and how it should work on the first layer*/
// t_node *fat_lisa(t_queue q)
// {
// 	int blis;
// 	int jalisse;
// 	t_node *k;

// 	k = q.head;
// 	blis = 0;
// 	while (blis <= (q.size - 1 - k->idx) && k != q.tail) // sinonimo di k.next !=NULL
// 	{
// 		// if (k->next->sval > k->sval)
// 		// 	blis++;
// 		// if (k->next)
// 		// 	k = k->next;
// 		jalisse = k->valis;
// 		if (blis < jalisse) // check best lis so far, to compare to the one it has just run
// 			blis = jalisse;
// 	}
// 	return (k);
// }

int runthrough(t_node *n, t_queue q)//DEPRECATED idx implemented
{ // scorrere la lista e calcolare la len dei rimanenti. scorrere la lista, questa e la len. sia q.size-counter or equivalence given that it has to receive the node we have started the run from.
	t_node *k;
	int i;

	k = q.head;
	i = 0;
	while (n->value != k->value)
	{
		k = k->next;
		i++;
	}
	return (i);
}

int toomuchLisa(t_node *node) // wrong and useless. DEPRECATED
{
	t_node *k;
	t_node *nk;
	int lissofar;

	k = node;
	lissofar = 0;
	nk = node->next;
	while (nk->next != NULL)
	{
		if (k->value < nk->value)
		{
			k = nk;
			lissofar++;
			if (nk->next)
				nk = nk->next;
		}
	}
	return (lissofar);
}

void findValReset(t_queue q, int nmb)
{
	/*from the number received run through the queue and look for */
}

// fromidfoundval obsolete with new architecture of the struct. DEPRECATED
int fiv(t_node *n, int id)
{
	int i;

	i = 0;
	// while(i == id)
	// 	n = n->next;
	while (n->idx != id)
		n = n->next;
	if (!(n->idx == id))
		return (0);
	return (n->sval);
}

//avvaloriamo attributo lis
// void theTamingoftheShrewLisa(t_queue *q)
// {
// 	t_node *k;
// 	t_node *rk;

// 	k = q->head->next;
// 	rk = q->head;
// 	while (k->idx < q->size) // check size and elaborate if normal cases then ... /
// 	{
// 		rk = q->head;
// 		while (rk != k)
// 		{
// 			if (rk->sval < k->sval && rk->valis + 1 >= k->valis)
// 			{
// 				if (k->idsubseq == NULL || rk->sval < k->idsubseq->sval)
// 				{
// 					k->valis = rk->valis + 1;
// 					k->idsubseq = rk;
// 				}
// 			}
// 			rk = rk->next;
// 		}
// 		k = k->next;
// 	}
// }

// t_node *lizCheney(t_queue *q)/*lizcheney returns the knot with the greatest lis taking into account the bestSpread*/
// {
// 	t_node *k;
// 	t_node *rk;
// 	int bestlis;
// 	int max_spread;

// 	bestlis = 0;
// 	k = NULL;
// 	rk = q->head;
// 	max_spread = 0;
// 	while (rk->idx <= q->size - 1)
// 	{
// 		if (bestlis <= rk->valis && LookIn_my_gapeS(rk) >= max_spread)
// 		{
// 			bestlis = rk->valis;
// 			max_spread = LookIn_my_gapeS(rk);
// 			k = rk;
// 		}
// 		rk = rk->next;
// 	}
// 	q->lis = k;
// 	return (k);
// }

// //used to keep the skeleton in a
// bool am_i_into_Lisa(t_node *rk, t_node *lk)
// {
// 	while (lk->idsubseq)
// 	{
// 		if (rk->sval == lk->sval)
// 			return (true);
// 		if (lk->idsubseq)
// 			lk = lk->idsubseq;
// 	}
// 	return (false);
// }

// /*impostare tutti gli elementi non in lis a -1 cosi'
//  da velocizzare successivamente i controlli*/
// void lisEandataVia (t_queue *q)
// {
// 	t_node *lk;
// 	t_node *rk;

// 	rk = q->head;
// 	lk = q->lis;
// 	//rush the queue and check if it's in amintolisa
// 	while(rk)
// 	{
// 		if (!(am_i_into_Lisa(rk,lk)))
// 			rk->valis = -1;
// 	}
// }

// int LookIn_my_gapeS(t_node *k)//y
// {
// 	// calcolo delle lis piu' spalmate e diramate nello stack
// 	int gape;

// 	gape = k->idx;
// 	while (k->idsubseq)
// 		k = k->idsubseq;
// 	if (!k->idsubseq)
// 		gape -= k->idx;
// 	return (gape);
// }

// bool isqmadeonlyoflisskeletonelements(t_queue q)//y
// {
// 	return (q.size == q.lis->valis);
// }

/*be clean and concise. how does the chunk algo work?
does the number of elements in each chunks increases by sheer amount of elements when an element is found and put into stackB example(0-34, 5 gets found and pushed into b, chunk is now looking for 0-35) or do they stick to those ranges and they get relatively bigger in sizes one after the other?*/
/*int main(void)
{
	t_queue q;
	t_node *nodes[10];
	int values[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
	int i;

	q.size = 10;
	q.head = NULL;
	q.tail = NULL;

	// Create linked list with test values
	for (i = 0; i < 10; i++)
	{
		nodes[i] = malloc(sizeof(t_node));
		nodes[i]->value = values[i];
		nodes[i]->sval = values[i];
		nodes[i]->idx = i;
		nodes[i]->valis = 1;
		nodes[i]->idsubseq = NULL;
		nodes[i]->next = NULL;
		if (i == 0)
			q.head = nodes[i];
		else
			nodes[i - 1]->next = nodes[i];
	}
	q.tail = nodes[9];

	// Test LIS algorithm
	theTamingoftheShrewLisa(q);
	t_node *lis_node = lizCheney(q);

	printf("LIS starts at index: %d, value: %d, length: %d\n",
		lis_node->idx, lis_node->sval, lis_node->valis);

	// Clean up
	for (i = 0; i < 10; i++)
		free(nodes[i]);

	return (0);
}*/
