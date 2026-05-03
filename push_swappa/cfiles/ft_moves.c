/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:39:41 by ggaritta          #+#    #+#             */
/*   Updated: 2026/05/02 15:40:18 by ggaritta         ###   ########.fr       */
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

void	swp(t_queue *q)
{
	t_node	*k;

	if (!q || !q->head || !q->head->next)
		return;
	k = q->head;
	q->head = q->head->next;
	q->head->prev = NULL;
	k->prev = q->head;
	if (q->head->next)
	{
		q->head->next->prev = k;
		k->next = q->head->next;
	}
	else
	{
		q->tail = k;
		k->next = NULL;
	}
	q->head->next = k;
}

void sa(t_queue *q)
{
	swp(q);
	write(1, "sa\n", 3);
}

void sb(t_queue *q)
{
	swp(q);
	write(1, "sb\n", 3);
}

void ss(t_stacks *s)
{
	swp(&s->a);
	swp(&s->b);
	write(1, "ss\n", 3);
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
	t_node *newhead;

	if (!from || !to || !from->head)
		return;
	newhead = from->head->next;
	from->head->next = to->head;
	if (to->head)
		to->head->prev = from->head;
	to->head = from->head;
	from->head = newhead;
	if (from->head)
		from->head->prev = NULL;
	else
		from->tail = NULL;
	if (!to->tail)
		to->tail = to->head;
	from->size--;
	to->size++;
}

void	pa(t_stacks *s)
{
	push(&s->b, &s->a);
	write(1, "pa\n", 3);
}

void pb(t_stacks *s)
{
	push(&s->a, &s->b);
	write(1, "pb\n", 3);
}

void scroll_up(t_queue *q)
{// controls missing //prev behaviour missing>aggiornati
	t_node	*newHead;

	if (!q || !q->head || !q->head->next)
		return;
	newHead = q->head->next;
	newHead->prev = NULL;
	q->tail->next = q->head;
	q->head->prev = q->tail;
	q->tail = q->head;
	q->head = newHead;
	q->tail->next = NULL;
}

void scroll_down(t_queue *q)
{//prev behaviour missing
	t_node *alast;

	if (!q || !q->head || !q->head->next)
		return;
	alast = q->tail->prev;
	if (!alast)
		return;
	alast->next = NULL;
	q->tail->next = q->head;
	q->head->prev = q->tail;
	q->head = q->tail;
	q->head->prev = NULL;
	q->tail = alast;
	q->tail->next = NULL;
}

void ra(t_queue *a)
{
	scroll_up(a);
	write(1, "ra\n", 3);
	
}

void rb(t_queue *b)
{
	scroll_up(b);
	write(1, "rb\n", 3);
}

void rr(t_stacks *s)
{
	scroll_up(&s->a);
	scroll_up(&s->b);
	write(1, "rr\n", 3);
}

void rra(t_queue *a)
{
	scroll_down(a);
	write(1, "rra\n", 4);
}

void rrb(t_queue *b)
{
	scroll_down(b);
	write(1, "rrb\n", 4);
}

void rrr(t_stacks *s)
{
	scroll_down(&s->a);
	scroll_down(&s->b);
	write(1, "rrr\n", 4);
}

t_node *get_alas(t_node *e)
{
	if (!e || !e->next)
		return NULL;
	while (e->next->next)
		e = e->next;
	return e;
}

void	reachnexttop(t_queue *q, t_node *reachme)
{
	if (!q || !q->head || !reachme)
		return;
	while (q->head != reachme)
		ra(q);
}

void	reachprevtop(t_queue *q, t_node *reachme)
{
	if (!q || !q->head || !reachme)
		return;
	while (q->head != reachme)
		rra(q);
}

void	reachprevbot(t_queue *q, t_node *reachme)
{
	if (!q || !q->tail || !reachme)
		return;
	while (q->tail != reachme)
		rra(q);
}

//this works mostly as a checker though this move will never happen if not something falling from the top and yeah it's a step forward to the 
void	reachnextbot(t_queue *q, t_node *reachme)
{
	if (!q || !q->tail || !reachme)
		return;
	while (q->tail != reachme)
		ra(q);
}

