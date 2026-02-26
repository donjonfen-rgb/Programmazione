/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:45:06 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/26 22:29:35 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node	t_node;

struct s_node
{
	int		value;
	t_node	*next;
};

typedef struct s_queue
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_queue;

void read_me(char *inputs);
//qops.c
void	ft_creation();
void push_swap(char *nums);
int decappler(t_queue *q);
void knot_me(t_queue *q, int val);
bool qie(t_queue *q);
t_queue *createQ();
//moves.c
void	sa(t_queue *q);
void	sb(t_queue *q);
void	ss(t_queue *a, t_queue *b);
void	push(t_queue *from, t_queue *to);
void	pa(t_queue *b, t_queue *a);
void	pb(t_queue *a, t_queue *b);
void	scroll_up(t_queue *q);
t_node	*get_alas(t_node *e);
void	scroll_down(t_queue *q);
void	ra(t_queue *a);
void	rb(t_queue *b);
void	rr(t_queue *a, t_queue *b);
void	rra(t_queue *a);
void	rrb(t_queue *b);
void	rrr(t_queue *a, t_queue *b);

//ftsplit.c
bool isWS(char c);

//parser.c
bool ft_pastramiOrSalami(char *str);



#endif
// ./pushwap numeri | ./checker  stessa lista numeri