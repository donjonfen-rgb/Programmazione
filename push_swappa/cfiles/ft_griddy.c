
#include "push_swap.h"

// func calcolate cost
//	viene da chunk
// xy = (t_coord){NULL,NULL,0,0,0,0,0,0,INT_MAX};	//xy = (t_coord){0};//x resetting, which can also be used for the init. which is better?

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

void mc_griddy(t_stacks *s)
{
	t_coord	xy;
	t_coord	zd;

	while (!qie(s->b))
	{
		zd = (t_coord){s->a.head, s->b.head, 0, '\0', 0, '\0', INT_MAX, 0};
		xy = zd;
		while (zd.bk)
		{
			tinder(s->a, &zd);
			scrooge_mcrot(s, &zd);
			if (xy.totc > zd.totc)
				xy = zd;
			zd.bk = zd.bk->next;
		}
		blind_date(s, &xy);
	}
	final_sortami(s);
}

//find the total cost of rotations
//calcolare le rotazioni ed acquisire di a e b knots sia in prev che in next //calcolo dei tre casi: //k1 k2 concordi -> 2 casi: prendere il max rot val per next e prev //k1 k2 discordi -> quindi uno andra prev laltro next e sommare i due vals
//how to find the lowest cost? maybe disgiunte rotations are better ?? how to do?
//rotk[4] to add the values of the differents a+b(discord) of which there are two cases
void scrooge_mcrot(t_stacks *s, t_coord *xy)
{
	int	*rotk;
	int	i;

	rotk = remaining_rich_by_being_the_most_miserable(s, xy);
	if (!rotk)
		return ;
	xy->totc = rotk[0];
	xy->strat = RR;
	i = 1;
	while (i < 4)
	{
		if (xy->totc > rotk[i])
		{
			xy->totc = rotk[i];
			xy->strat = (t_strat)i;
		}
		i++;
	}
	free(rotk);
	setmeup(s, xy);
}

/*if ((rotk[0] <= rotk[1]) && (rot_k[2] <= rot_k[3]))
	call loop for rr for the amount of absolute rotk and then based on which one was greater keep doing that other one
	else if ((rotk[0] >= rotk[1]) && (rot_k[2] >= rot_k[3]))
	call for loop rrr same as above
	//if directions are discordants
	else if
		rotk[];
*/
/*
find if rotations have the same directions
the node on top is the cheapest to send, where to put it?
cercare il nodo da piazzare proveniente da B in A che costa meno e che sia il 
*/
