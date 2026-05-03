/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:18:40 by ggaritta          #+#    #+#             */
/*   Updated: 2026/05/02 20:06:35 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_too(t_stacks *s)//? do i need you
{
	if (!s || !s->a.head || !s->a.head->next)
		return ;
	if (s->a.head->sval > s->a.head->next->sval)
		sa(&s->a);
}

void sort_thee(t_stacks *s)
{
	int prime;
	int secund;
	int terzio;

	prime = s->a.head->sval;
	secund = s->a.head->next->sval;
	terzio = s->a.tail->sval;
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
	t_node *minpo;

	minpo = pikmin(s->a);
	while (s->a.head != minpo)
	{
		if (nrotcost(s->a, minpo) <= 3)
			ra(&s->a);
		else
			rra(&s->a);
	}
	pb(s);
	//print_stacks(s);
	sort_thee(s);
	pa(s);
	//print_stacks(s);
	//now it's already sorted
}

void sort_faiv(t_stacks *s)
{
	t_node *minpo;

	minpo = pikmin(s->a);
	while (s->a.head != minpo)
	{
		if (nrotcost(s->a, minpo) <= 3)
			ra(&s->a);
		else
			rra(&s->a);
	}
	pb(s);
	//print_stacks(s);
	sort_flour(s);
	pa(s);
	//print_stacks(s);
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

void	print_stacks(t_stacks *s)
{
	t_queue	tmp_a = s->a;
	t_queue	tmp_b = s->b;

	printf("\n--- STACK STATE ---\n");
	printf("A\t\t\t\t\t|\tB\n");
	printf("--------------------------------------------------------------\n");

	while (tmp_a.head || tmp_b.head)
	{
		// STACK A
		if (tmp_a.head)
		{
			printf("[idx=%d | sval=%d | valis=%d | sub=%p]",
				tmp_a.head->idx,
				tmp_a.head->sval,
				tmp_a.head->valis,
				(void *)tmp_a.head->idsubseq);
			tmp_a.head = tmp_a.head->next;
		}
		else
			printf(" ");

		printf("\t|\t");

		// STACK B
		if (tmp_b.head)
		{
			printf("[idx=%d | sval=%d | valis=%d | sub=%p]",
				tmp_b.head->idx,
				tmp_b.head->sval,
				tmp_b.head->valis,
				(void *)tmp_b.head->idsubseq);
			tmp_b.head = tmp_b.head->next;
		}

		printf("\n");
	}

	printf("--------------------------------------------------------------\n");
}
// void	print_stacks(t_stacks *s)
// {
// 	t_queue tmp_a = s->a;
// 	t_queue tmp_b = s->b;

// 	printf("\n--- STACK STATE ---\n");
// 	printf("   A\t|\tB\n");
// 	printf("------------------------\n");

// 	while (tmp_a.head || tmp_b.head)
// 	{
// 		if (tmp_a.head)
// 		{
// 			printf("   %d", tmp_a.head->sval);
// 			tmp_a.head = tmp_a.head->next;
// 		}
// 		else
// 			printf("    ");

// 		printf("\t|\t");

// 		if (tmp_b.head)
// 		{
// 			printf("%d", tmp_b.head->sval);
// 			tmp_b.head = tmp_b.head->next;
// 		}

// 		printf("\n");
// 	}
// 	printf("------------------------\n");
// }