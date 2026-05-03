/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:27 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/30 15:02:01 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool check_if_sortdimamt(t_queue q)
{
	t_node *k;

	if (!q.head || !q.head->next)
		return (true);
	k = q.head;
	while (k->next)
	{
		if (k->sval < k->next->sval)
			k = k->next;
		else
			return (false);
	}
	if (k == q.tail)
		return (true);
	return (false);
}

bool isN(char c)
{
	return ((c >= 48 && c <= 57));
}

bool ft_pastramiOrSalami(char *str)
{
	int	seen_digit;

	seen_digit = 0;
	while (*str)
	{
		if (isN(*str))
			seen_digit = 1;
		else if (!isWS(*str) && *str != '+' && *str != '-')
			return (seen_digit);
		str++;
	}
	return (seen_digit);
}

//findmin in queue
t_node *ft_schivoPeterMinum(t_queue q)
{
	int min;
	t_node	*k;
	t_node	*l_k;

	l_k = NULL; //why does it have to be set as null. because you might never use it ofc
	min = INT_MAX;
	k = q.head;
	while (k != NULL)
	{
		if(k->sval == -1 && k->value < min)
		{
			min = k->value;
			l_k = k;
		}
		k = k->next;
	}
	return (l_k);
}

/* assign costs/ids: set everynode as un-indexed so to -1. after, you need to start indexing,
 searching from those that are still not indexed, searching for min value you start from max */
void ft_howMuchisPastrami(t_queue *q)
{
	int		sval;
	t_node	*little_knot;

	sval = 0;
	while(sval < q->size)
	{
		little_knot = ft_schivoPeterMinum(*q);
		if (little_knot)
			little_knot->sval = sval;
		sval++;
	}
}

t_stacks *assignidxs(t_stacks *s)// never used, maybe used only once?
{
	t_node *k;
	int i;

	i = 0;
	k = s->a.head;
	while (k)
	{
		k->idx = i++;
		k = k->next;
	}
	k = s->b.head;
	i = 0;
	while (k)
	{
		k->idx = i++;
		k = k->next;
	}
	return (s);
}

static bool	duped(t_queue q, int v)
{
	t_node	*k;

	k = q.head;
	while (k)
	{
		if (k->value == v)
			return (true);
		k = k->next;
	}
	return (false);
}

static int	append_parsed(t_stacks *s, int v, int *idx)
{
	t_node	*k;

	if (duped(s->a, v))
		return (1);
	k = knot_me(v, *idx);
	if (!k)
		return (1);
	k2q(&s->a, k);
	(*idx)++;
	return (0);
}

static int	parse_one_arg(t_stacks *s, char *arg, int *idx)
{
	int	v;

	while (*arg)
	{
		while (*arg && isWS(*arg))
			arg++;
		if (!*arg)
			break ;
		if (ft_strtolol(&arg, &v))
			return (1);
		if (append_parsed(s, v, idx))
			return (1);
	}
	return (0);
}

//func about the whole filling the stack from inputs
t_queue *alltheknots(t_stacks *s, int argc, char **argv)
{
	int	i;
	int	idx;

	if (!s)
		return (NULL);
	i = 1;
	idx = 0;
	while (i < argc)
	{
		if (parse_one_arg(s, argv[i], &idx))
			return (NULL);
		i++;
	}
	ft_howMuchisPastrami(&s->a);
	if (s->a.size == 0)
		return (NULL);
	return (&(s->a));
}
