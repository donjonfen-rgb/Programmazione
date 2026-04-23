/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:18:40 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/23 20:04:45 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_too(t_stacks *s)//? do i need you
{
	if (!s || !s->a.head || !s->a.head->next)
		return ;
	if (s->a.head->value > s->a.head->next->value)
		sa(&s->a);
}

void sort_thee(t_stacks *s)
{
	int prime;
	int secund;
	int terzio;

	prime = s->a.head->value;
	secund = s->a.head->next->value;
	terzio = s->a.tail->value;
	if(prime > secund && secund < terzio && prime < terzio)/*ii*/
		sa(&s->a);
	else if(prime < secund && secund > terzio && prime > terzio)/*iii*/
		rra(&s->a);
	else if(prime > secund && secund > terzio && prime > terzio)/*iv*/
	{
		sa(&s->a);
		rra(&s->a);
	}
	else if(prime < secund && secund > terzio && prime < terzio)/*v*/
	{
		sa(&s->a);
		ra(&s->a);
	}
	else if(prime > secund && secund < terzio && prime > terzio)/*vi*/
		ra(&s->a);
	else check_if_sortdimamt(s->a);//?
}

void sort_flour(t_stacks *s)
{
	int minpo;
	
	minpo = ft_id_pippino(s->a);
	if (minpo == 1)
		sa(&s->a);
	else if (minpo == 2)
	{
		ra(&s->a);
		sa(&s->a);
	}
	else if (minpo == 3)
		rra(&s->a);
	pb(s);
	sort_thee(s);
	pa(s);
	//now it's already sorted
}

void sort_faiv(t_stacks *s)
{
	int minpo;

	minpo = ft_id_pippino(s->a);
	while (minpo != 0)
	{
		if (minpo <= 2)
			ra(&s->a);
		else
			rra(&s->a);
		minpo = ft_id_pippino(s->a);
	}
	pb(s);
	sort_flour(s);
	pa(s);
}

void lesortdimamt(t_stacks *s)
{
	
	if (s->a.size == 2)
		sort_too(s);
	else if (s->a.size == 3)
		sort_thee(s);
	else if (s->a.size == 4)
		sort_flour(s);
	else if (s->a.size == 5)
		sort_faiv(s);
}