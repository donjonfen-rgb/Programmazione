/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:27 by ggaritta          #+#    #+#             */
/*   Updated: 2026/03/13 19:46:51 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
bool check_if_sortdimamt(t_queue q)
{
	int min;
	min = INT_MIN;
	while(q.head->next)
	{
		//qwertyuiop
	}
}

bool ft_pastramiOrSalami(char *str)
{
	while(*str)
		if(!isN(str) || !isWS(str))
			return false;
		str++;
}
bool isN(char c)
{
	return ((c >= 48 && c <= 57));
}

bool ft_no_duplos(int *vals)
{
	int j,i = 0;
	//check if number appeared in list
	while (vals[i]!= NULL)
	{
		j = 1;
		while (vals[j])
			if(vals[i] == vals[j])
				return (false);
	}
	return (true);
}

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
		if(k->id == INT_MIN && k->value < min)
		{
			min = k->value;
			l_k = k;
		}
		k = k->next;
	}
	return (l_k);
}

/* assign costs/ids: set everynode as un-indexed so to -1. after, you need to start indexing, 
searching from those that are still not indexed, searching for min value you start from max*/
void ft_howMuchisPastrami(t_queue q)
{
	int id;
	t_node *little_knot;
	t_node *node;

	node = q.head;
	while (node->id != INT_MIN)
	{
		node->id = INT_MIN;
		node = node->next;
	}
	id = 0;
	while(id < q.size)
	{
		little_knot = ft_schivoPeterMinum(q);
		if (little_knot)
			little_knot->id = id;
		id++;
	}
}


