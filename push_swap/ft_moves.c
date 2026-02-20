/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:39:41 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/20 18:21:26 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void sa(t_queue *q, t_node *a, t_node *b)
// {
// 	int val;

// 	if (q->head == NULL)
// 		return NULL;
// 	val = 0;
// 	val = a->value;
// 	a->value = b->value;
// 	b->value = val;
// }

void sa(t_queue *q)
{// controls missing
	int val = 0;
	val = q->head->value;
	q->head->value = q->head->next->value;
	q->head->next->value = val;
}

void sb(t_queue *q)
{
	sa(q);
}

void ss(t_queue *a, t_queue *b)
{
	sa(a);
	sb(b);
}

// void sb(t_queue *q, t_node *a, t_node *b)
// {
// 	sa(q,a,b);
// }
// void ss(t_queue *q, t_node *a, t_node *b, t_node *c, t_node *d)
// {
// 	sa(q,a,b);
// 	sb(q,c,d);
// }
void push(t_queue *from, t_queue *to)
{// controls missing
	t_node *newbhead;

	newbhead = from->head->next;
	from->head->next = to->head;
	from->head = newbhead;
	from->size--;
	to->size++;
}

void	pa(t_queue *b, t_queue *a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void pb(t_queue *a, t_queue *b)
{
	push(a,b);
	write(1, "pb\n", 3);
}

void scrollup(t_queue *q)
{// controls missing
	t_node	*newHead;
	newHead = q->head->next;
	q->tail->next = q->head;
	q->tail = q->head;//?
	q->head = newHead;
	q->tail->next = NULL;
}

void scrolldown()
{
	
}
void ra(t_queue *a)
{scrollup(a);	write(1, "ra\n", 3);}
void rb(t_queue *b)
{scrollup(b);	write(1, "rb\n", 3);}
void rr(t_queue *a, t_queue *b)
{scrollup(a);scrollup(b);	write(1, "rr\n", 3);}
void rra(t_queue *a)
{scrolldown(a);	write(1, "rra\n", 4);}
void rrb(t_queue *b)
{scrolldown(b);	write(1, "rrb\n", 4);}
void rrr(t_queue *a, t_queue *b)
{scrolldown(a);scrolldown(b);	write(1, "rrr\n", 4);}