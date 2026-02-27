/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:45:06 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/27 20:36:13 by ggaritta         ###   ########.fr       */
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
	int		id;
	int		value;
	int		cost;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_queue
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_queue;

typedef struct s_stacks
{
	t_queue	a;
	t_queue	b;
} t_stacks;

//qops.c
void	ft_createStacks();
void	push_swap(t_queue *nums);
int		decappler(t_queue *q);
void	knot_me(t_queue *q, int val);
bool	qie(t_queue *q);
t_queue	*createQ();
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
int findWords(char *s);
int ft_strtololol(char *num);
int *split(char *s);

//parser.c
bool	ft_pastramiOrSalami(char *str);
bool	isN(char c);
bool	ft_no_duplos(int *vals)




#endif
// ./pushwap numeri | ./checker  stessa lista numeri