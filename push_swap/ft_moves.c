/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:39:41 by ggaritta          #+#    #+#             */
/*   Updated: 2026/03/13 16:33:13 by ggaritta         ###   ########.fr       */
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

void swp(t_queue q)
{// controls missing
	int val = 0;
	val = q.head->value;
	q.head->value = q.head->next->value;
	q.head->next->value = val;
}

void sa(t_queue q)
{
	swp(q);
	write(1, "sa\n", 3);
}

void sb(t_queue q)
{
	swp(q);
	write(1, "sb\n", 3);
}

void ss(t_queue a, t_queue b)
{
	sa(a);
	sb(b);
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
void push(t_queue from, t_queue to)
{// controls missing
	t_node *newbhead;

	newbhead = from.head->next;
	from.head->next = to.head;
	from.head = newbhead;
	from.size--;
	to.size++;
}

void	pa(t_queue b, t_queue a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void pb(t_queue a, t_queue b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void scroll_up(t_queue q)
{// controls missing
	t_node	*newHead;
	newHead = q.head->next;
	q.tail->next = q.head;
	q.tail = q.head;
	q.head = newHead;
	q.tail->next = NULL;
}

t_node *get_alas(t_node *e)
{
	if (!e || !e->next)
		return NULL;

	while (e->next->next)
		e = e->next;
	return e;
}

void scroll_down(t_queue q)
{
	t_node *alast;
	alast = get_alas(q.head);
	alast->next = NULL;
	q.tail->next = q.head;
	q.head = q.tail;
	q.tail = alast;
}

void ra(t_queue a)
{
	scroll_up(a);
	write(1, "ra\n", 3);
}
void rb(t_queue b)
{scroll_up(b);	write(1, "rb\n", 3);}
void rr(t_stacks s)
{scroll_up(s.a);scroll_up(s.b);	write(1, "rr\n", 3);}
void rra(t_queue a)
{scroll_down(a);	write(1, "rra\n", 4);}
void rrb(t_queue b)
{scroll_down(b);	write(1, "rrb\n", 4);}
void rrr(t_stacks s)
{scroll_down(s.a);scroll_down(s.b);	write(1, "rrr\n", 4);}
