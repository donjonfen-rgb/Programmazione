/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_griddy_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:47:23 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/16 21:58:39 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void calldoublespin(t_stacks *s, t_node *ak, t_node *bk, int rot)//come funzichi? dimenticato totalmente
{
	int ai;
	int bi;

	ai = numrottotop(s,ak);
	bi = numrottotop(s,bk); //con la struttura possiamo conservare le coordinate e la direzione: true dx false sx;
	while (ai-- > 0 && bi-- > 0)
		if(rot > 0)
			rr(s);
		else
			rrr(s);

}

int maxvalo(int n, int m)
{
	if (n >= m)
		return (n);
	else
		return (m);
}

int minvalo(int i, int j)
{
	if (i <= j)
		return (i);
	else if (j < i)
		return (j);
}

//set the strat
int *remaining_rich_by_being_the_most_miserable(t_stacks *s, t_coord *xy)
{
	int *rotk;

	rotk = ft_helloitsmecalloc(4, sizeof(int), '\0');
	if (!rotk)
		return NULL;
	rotk[RR] = maxvalo(nrotcost(s->a,xy->ak), nrotcost(s->b,xy->bk));
	rotk[RRR] = maxvalo(protcost(s->a,xy->ak), protcost(s->b,xy->bk));
	rotk[RA_RRB] = (nrotcost(s->a,xy->ak) + protcost(s->b,xy->bk));
	rotk[RRA_RB] = (protcost(s->a,xy->ak) + nrotcost(s->b,xy->bk));
	return (rotk);
}
// set_coordir(s, xy);
// 	n = s->a.size + s->b.size;
// 	if (xy->ak->sval < xy->bk->sval)
// 		if ((xy->ak->sval - xy->bk->sval) < (n- xy->ak->sval + xy->bk->sval))
// 			xy->exorintval = -1;
// 			need to add the direction in order to choose the strat?
// 			if
// 		else
// 			xy->exorintval = 1;
// 	else if (xy->ak->sval > xy->bk->sval)
//lowval
// void	set_xy_vals(const t_stacks *s, t_coord *xy, int lv, int strat)
// {
// 	int	n;
// 	xy->totc = lv;
// 	xy->strat = (t_strat)strat;
// 	//doveva fare tantissime altre cose, tutte stralciate. bona.
// }

void	blind_date(t_stacks *s, t_coord *xy)
{
	reachtop(s, xy);
	pa(s);
}
//smallestdiffbothways setter for ab nodes
// void	*its_Not_The_Size_That_Counts(t_stacks *s, t_coord *abks)//riscritta che e' troppo sbagliata ma ben scritta christo
// {
// 	t_node	*bk;
// 	t_node	*ak;
// 	int		absval;
// 	int		mindiff;
// 	mindiff = INT_MAX;
// 	ak = s->a.head;
// 	while(ak)
// 	{
// 		bk = s->b.head;
// 		while (bk)
// 		{
// 			absval = get_me_minabsval(s, ak->sval, bk->sval);
// 			if (absval < mindiff)
// 			{//va aggiunto qualcos'altro?
// 				mindiff = absval;
// 				abks->bk = bk;
// 				abks->ak = ak;
// 			}
// 			bk = bk->next;
// 		}
// 		ak = ak->next;
// 	}
// }

//its_Not_The_Size_That_Counts
void	tinder(t_queue a, t_coord *zd)
{
	t_node	*k;

	k = a.head;
	zd->ak = NULL;
	while (k)
	{
		if (k->sval > zd->bk->sval)
			if (!zd->ak || k->sval < zd->ak->sval)
				zd->ak = k;
		k = k->next;
	}
	if (zd->ak == NULL)
		zd->ak = pikmin(a);
}
//useless???????
// int	get_me_minabsval(const t_stacks *s, int ak, int bk)// before pushing i have to find which diff has been applied a-b or n-a-b
// {
// 	int	n;
// 	n = s->a.size + s->b.size;
// 	if (ak < bk)
// 	{
// 		if (bk - ak < n - bk + ak)
// 			return(bk - ak);
// 		else
// 			return(n - bk + ak);
// 	}
// 	else if (bk < ak)
// 	if (ak - bk < n - ak + bk)
// 		return(ak - bk);
// 	else
// 		return(n - ak + bk);
// }

void reachtop(t_stacks *s, t_coord *xy)
{
	if (xy->adir == xy->bdir)
		concord(s, xy);
	remainingroots(s, xy);
}

// if (!(xy->adir == xy->bdir))	// 	discord(s, xy);
void concord(t_stacks *s, t_coord *xy)
{
	int i;
	int condiriso;

	i = 0;
	condiriso = minvalo(xy->ac, xy->bc);
	if (xy->adir == 'n' && xy->bdir == 'n')
	{
			while(i++ < condiriso)
				rr(s);
	}
	else if (xy->adir == 'p' && xy->bdir == 'p')
	{
			while(condiriso > i++)
				rrr(s);
	}
	xy->bc -= i;
	xy->ac -= i;
}

void	remainingroots(t_stacks *s, t_coord *xy)
{
	while(xy->ac--)
	{
		if(xy->adir == 'n')
			ra(&s->a);
		else
			rra(&s->a);
	}
	while(xy->bc--)
	{
		if(xy->bdir == 'n')
			rb(&s->b);
		else
			rrb(&s->b);
	}
}

void	setmeup(t_stacks *s, t_coord *xy)
{
	xy->adir = 'n';
	xy->bdir = 'n';
	if (xy->strat == RRR || xy->strat == RA_RRB)
		xy->bdir = 'p';
	else if (xy->strat == RRR || xy->strat == RRA_RB)
		xy->adir = 'p';
	if (xy->adir == 'n')
		nrotcost(s->a, xy->ak);
	else
		protcost(s->a, xy->ak);
	if (xy->bdir == 'p')
		nrotcost(s->b, xy->bk);
	else
		protcost(s->b, xy->bk);
}

void final_sortami(t_stacks *s)
{
	t_node	*k;

	k = pikmin(s->a);
	if(nrotcost(s->a, k) < protcost(s->a, k))
		while(s->a.head != k)
			ra(&s->a);
	else
		while(s->a.head != k)
			rra(&s->a);
}

//DEPRECATED STUFF
//deprecated
// t_node *mindiffval(t_stacks s, t_node *ak)//riadattata? no deprecata in favore di its_Not_The_Size_That_Counts agg 13/04
// {
// 	t_node	*bk;
// 	int		mindiff;
// 	int		absval;
// 	t_node	*bkf;
// 	mindiff = INT_MAX;
// 	bk = s.b.head;
// 	while(bk)
// 	{
// 		absval = get_me_minabsval(s, bk);
// 		if (absval < 0)
// 			absval *= -1;
// 		// function totalcostreachtotop();
// 		if (absval < mindiff)
// 		{
// 			mindiff = absval;
// 			bkf = bk;
// 		}
// 	}
// 	return (bkf);//if run from mindiffval also trying both prev and next anyway and check costs
// }
//useless //this func should only find the closest number between 
// t_node *maxdiffval(t_stacks s, t_node *ak)// deprecato
// {
// 	t_node	*bk;
// 	int mindiff;
// 	int	absval;
// 	t_node	*bkf;
// 	int n;
// 	mindiff = INT_MIN;
// 	bk = s.b.head;
// 	n = s.a.size + s.b.size;
// 	while(bk)
// 	{//maxdiff should be the thing i thought before so to grab either way the closest value from it using that behaviour of doing it 
// 		if (bk->sval > ak->sval)
// 			absval = (n - bk->sval) + ak->sval;
// 		absval = bk->sval-ak->sval;
// 		if (absval > mindiff)
// 			bkf = bk;
// 	}
// 	return (bkf);
// }
// get_me_minabsval coi nodi invece che int
// int	get_me_minabsval(t_stacks s, int ak, int bk)
// {
// 	int n;
// 	n = s.a.size + s.b.size;
// 	if (ak < bk)
// 		if (bk->sval - ak->sval < n - bk->sval + ak->sval)
// 			absval = bk->sval - ak->sval;
// 		else
// 			absval = n - bk->sval + ak->sval;
// 	else if (bk->sval < ak->sval)
// 		if (ak->sval - bk->sval < n - ak->sval + bk->sval)
// 			absval = ak->sval - bk->sval;
// 		else
// 			absval = n - ak->sval + bk->sval;
// 	return ();
// }
// if a < b -> b - a: 20 - 460 = 440	\	n-b+a: 500-460+20 = 60
// if a > b -> a - b: 480 - 20 = 460	\	n-a+b: 500-480+20 = 40
// 58 59 	-499 -1
// 20 360	
//vedi se ti serve che ritorni un nodo o l'int della pos, che sarebbe il num delle mosse necessarie
// t_node *bigger_pickmin(t_stacks s, int bksval)
// {
// 	int		min;
// 	t_node	*kmin;
// 	min = INT_MAX;
// 	kmin = s.a.head;
// 	while (kmin)
// 	{
// 		if(kmin->sval > bksval && kmin->sval < min)
// 			min = kmin->sval;
// 		kmin = kmin->next;
// 	}
// 	if (min == INT_MAX)
// 		return (pikmin(s.a));// how does this help me? check if equals pickmin after returned?
// 	return (kmin);
// }
// t_node *bigger_pokmon(t_stacks s, int bksval)
// {
// 	int		mon;
// 	t_node	*kmon;
// 	mon = INT_MIN;
// 	kmon = s.a.head;
// 	while (kmon)
// 	{
// 		if(kmon->sval > bksval && kmon->sval < mon)
// 			mon = kmon->sval;
// 		kmon = kmon->next;
// 	}
// 	if (mon == INT_MIN)
// 		return (pokmon(s.a));// how does this help me? check if equals pickmin after returned?
// 	return (kmon);
// }



