/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:50:17 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/20 17:41:00 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

t_queue *createQ()
{
	t_queue *q;
	q = malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	return (q);
}

bool qie(t_queue *q)
{
	return q->size == 0;
}
void knot_me(t_queue *q, int val)
{
	/*creare il nodo, verificare, */
	t_node *newNod = {0};
	newNod = malloc(sizeof(t_node));
	if (!newNod)
		return;
	newNod->value = val;
	newNod->next = NULL;
	if (q->head == NULL)
	{
		q->head = newNod;
		q->tail = newNod;
	}
	else
	{
		q->tail->next = newNod;
		q->tail = newNod;
	}
	q->size++;
}
int decappler(t_queue *q)
{
	int oVal;
	t_node *oNod;
	oVal = 0;
	if (q->head == NULL)
		return false;
	q->head = q->head->next;
	oNod = q->head;
	oVal = q->head->value;
	free(oNod);
	q->size--;
	return (oVal);
}
