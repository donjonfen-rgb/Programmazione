/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:50:17 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/23 17:09:48 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_queue createQ(void)
// {
// 	return ((t_queue){NULL, NULL, 0});
// }
t_stacks *create_stacks(void)
{
	t_stacks *s;

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);
	s->a = (t_queue){NULL, NULL, NULL, 0};
	s->b = (t_queue){NULL, NULL, NULL, 0};
	return (s);
}

t_node *knot_me(int val, int id)
{
	/*creare il nodo, verificare, */
	t_node *newNod;
	newNod = malloc(sizeof(t_node));
	if (!newNod)
		return (NULL);
	newNod->value = val;
	newNod->sval = -1;
	newNod->valis = 1;
	newNod->idx = id;
	newNod->idsubseq = NULL;
	newNod->prev = NULL;
	newNod->next = NULL;
	/*
	t_node *n = knot_me(val, i); to use in the actual code or here to complete creation
	if (newNod)
	k2q(q, newNod);
	*/
	return (newNod);
}

void k2q(t_queue *q, t_node *newNod)
{
	if (q->head == NULL)
	{
		q->head = newNod;
		q->tail = newNod;
	}
	else
	{
		newNod->prev = q->tail;
		q->tail->next = newNod;
		q->tail = newNod;
	}
	// if (q->head == newNod)
	// 	newNod->prev = NULL;
	// else
	// 	newNod->prev = q->tail;
	q->size++;
}

static void	clear_queue(t_queue *q)
{
	t_node	*knot;
	t_node	*future_knot;

	knot = q->head;
	while (knot)
	{
		future_knot = knot->next;
		free(knot);
		knot = future_knot;
	}
	q->head = NULL;
	q->tail = NULL;
	q->lis = NULL;
	q->size = 0;
}

void decappler_two_point_o(t_stacks *s)
{
	if (!s)
		return ;
	clear_queue(&s->a);
	clear_queue(&s->b);
	free(s);
}

void	knot_of_interest(t_queue q)
{
	int		i;
	t_node	*k;

	k = q.head;
	i = 0;
	while (k)
	{
		k->idx = i;
		i++;
		k = k->next;
	}
	//filled all the nodes of the stack. idx is necessary for lis layer;
}

bool qie(t_queue q)
{
	return (q.size == 0);
}
