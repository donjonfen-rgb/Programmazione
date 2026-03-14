/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:18:40 by ggaritta          #+#    #+#             */
/*   Updated: 2026/03/13 20:48:19 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_too(t_stacks s)//? do i need you
{
	int tmp;

	if (s.a.head->value > s.a.head->next->value)
	{
		tmp = s.a.head->value;
		s.a.head->value = s.a.head->next->value;
		s.a.head->next->value = tmp;
	}
}

void sort_thee(t_stacks s)
{
	int prime;
	int secund;
	int terzio;

	prime = s.a.head->value;
	secund = s.a.head->next->value;
	terzio = s.a.tail->value;
	if(prime > secund && secund < terzio && prime < terzio)/*ii*/
		sa(s.a);
	else if(prime < secund && secund > terzio && prime > terzio)/*iii*/
		rra(s.a);
	else if(prime > secund && secund > terzio && prime > terzio)/*iv*/
	{
		sa(s.a);
		rra(s.a);
	}
	else if(prime < secund && secund > terzio && prime < terzio)/*v*/
	{
		sa(s.a);
		ra(s.a);
	}
	else if(prime > secund && secund < terzio && prime > terzio)/*vi*/
		ra(s.a);
	else check_if_sortdimamt(s.a);//?
}

void sort_flour(t_stacks s)
{
	int minpo;
	
	minpo = ft_id_pippino(s.a);
	if (minpo == 1)
		sa(s.a);
	else if (minpo == 2)
	{
		ra(s.a);
		sa(s.a);
	}
	else if (minpo == 3)
		rra(s.a);
	pb(s.a,s.b);
	sort_thee(s);
	pa(s.b,s.a);
	//now it's already sorted
}

void sort_faiv(t_stacks s)
{
	int minpo;

	minpo = ft_id_pippino(s.a);
	while (minpo != 0)
	{
		if (minpo <= 2)
			ra(s.a);
		else
			rra(s.a);
		minpo = ft_id_pippino(s.a);
	}
	pb(s.a,s.b);
	sort_flour(s);
	pa(s.b,s.a);
}

void lesortdimamt(t_stacks s)
{
	if (2)
		sort_too;
	else if 3
		sort_thee;
	else if 4
		sort_flour;
	else if (5)
		sort_faiv;
	else
	while(size>3)
		pb();
	sort_thee;
}