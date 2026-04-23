#include "push_swap.h"

int	chunk_size(int n)
{
	int size;

	size = 2 * ft_sqrt(n);
	if (size < 5)
		size = 5;
	return (size);
}

int	ft_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int ch_malcolm_in_the_middle(int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	return (mid);
}

//ifchuart or chuend  == maxn bool dnot ++;
bool ceiling(t_stacks s, int *chs, int *che)
{
	int n;
	int min;
	int chsize;

	chsize = *chs - *che;
	n = s.a.size - s.a.lis->valis + s.b.size;
	min = n - chsize;
	if ((*chs == min && *che == n))
		return (true);
	else
	{
		(*chs)++;
		(*che)++;
		return (false);
	}
}

//greedy
int nrotcost(t_queue q, t_node *n)
{
	t_node *k;
	int i;
	
	i = 0;
	k = q.head;
	while(k->sval != n->sval)
	{
		k = k->next;
		i++;
	}
	return (i);
}

//greedy
int protcost(t_queue q, t_node *p)
{
	t_node *k;
	int i;
	
	i = 0;
	k = q.tail;
	while(k->sval != p->sval)
	{
		k = k->prev;
		i++;
	}
	return (i + 1);
}

void	findbestrottenknot(t_stacks *s, int *chus, int *chue)
{
	t_node *p;
	t_node *n;

	p = prnktp(s->a, *chus, *chue);
	n = nrnktp(s->a, *chus, *chue);
	if (nrotcost(s->a, n) <= protcost(s->a, p))
		reachnexttop(&s->a,n);
	else
		reachprevtop(&s->a,p);
	if (s->a.head == p || s->a.head == n)
		push_me_knot(s,chus,chue);
}

void save_me_nrotmin(t_stacks *s, t_node *p, t_node *n, int *cs, int *ce)
{
	if (nrotcost(s->a, n) < protcost(s->a, p))
	{
		if ((n->sval <= (*cs + *ce) / 2) && (n->sval > s->b.head->sval))
			rr(s);
		else if ((n->sval <= (*cs + *ce) / 2) && (n->sval < s->b.head->sval))
		{
			reachnexttop(&s->a, n);
			push_me_knot(s, cs, ce);
			rb(&s->b);
			rb(&s->b);
		}
	}
}

//find best node with preference to the simple rotate elements
void save_me_nroteq(t_stacks *s, t_node *p, t_node *n, int *cs, int *ce)
{
	if (nrotcost(s->a, n) == protcost(s->a, p))
	{
		if ((n->sval <= (*cs + *ce) / 2) || (p->sval <= (*cs + *ce) / 2))
		{
			if ((n->sval < p->sval) && (n->sval < s->b.head->sval))
				reachnexttop(&s->a, n);
			else if ((n->sval > p->sval) && (p->sval < s->b.head->sval))
				reachprevtop(&s->a, p);
			push_me_knot(s, cs, ce);
			rb(&s->b);
			rb(&s->b);
		}
		else if ((n->sval > (*cs + *ce) / 2))
			rr(s);
	}
}

void push_me_knot(t_stacks *s, int *chus, int *chue)
{
	pb(s);
	ceiling(*s,chus,chue);
}

//func that will fav rr rotations if possible by equal cost.
void	predict_me_Knot(t_stacks *s, int *cs, int *ce)
{
	int rot_k[4];
	int best_next;
	int best_prev;

	rot_k[0] = nextrotmormid(s->a, *cs, *ce);
	rot_k[1] = nextrotlessmid(s->a, *cs, *ce);
	rot_k[2] = prevrotmormid(s->a, *cs, *ce);
	rot_k[3] = prevrotlessmid(s->a, *cs, *ce);
	if ((rot_k[1] <= rot_k[0]) && (rot_k[3] <= rot_k[2]))
		save_me_rot(s, fifpk(*s, rot_k[3]), fifnk(*s, rot_k[1]), cs, ce);
	else if (rot_k[0] < rot_k[1] && (rot_k[2] <= rot_k[3]))
		save_me_rot(s, fifpk(*s, rot_k[2]), fifnk(*s, rot_k[0]), cs, ce);
	else
	{
		if (rot_k[1] <= rot_k[0])
			best_next = rot_k[1];
		else
			best_next = rot_k[0];
		if (rot_k[3] <= rot_k[2])
			best_prev = rot_k[3];
		else
			best_prev = rot_k[2];
		save_me_rot(s, fifpk(*s, best_prev), fifnk(*s, best_next), cs, ce);
	}
}

void save_me_rot(t_stacks *s, t_node *p, t_node *n, int *cs, int *ce)
{
	save_me_nroteq(s, p, n, cs, ce);
	save_me_nrotmin(s, p, n, cs, ce);
}

//from int find next node
t_node *fifnk(t_stacks s, int i)
{
	t_node *k;
	
	k = s.a.head;
	while (i > 0)
	{
		k = k->next;
		i--;
	}
	return (k);
}

//from int find prev node
t_node *fifpk(t_stacks s, int i)
{
	t_node *k;
	
	k = s.a.tail;
	while (i > 0)
	{
		k = k->prev;
		i--;
	}
	return (k);
}

int	nextrotmormid(t_queue q, int cs, int ce)
{
	t_node *k;
	int i;
	
	i = 0;
	k = q.head;
	// while (k != q.tail && !k)
	while (!((k->sval > (cs + ce) / 2) && k->sval <= ce)
		|| am_i_into_Lisa(k, q.lis))
	{
		i++;
		k = k->next;
	}
	return (i);
}

int	nextrotlessmid(t_queue q, int cs, int ce)
{
	t_node *nod;
	int j;
	j = 0;
	nod = q.head;
	while (!(nod->sval <= (cs + ce) / 2) || am_i_into_Lisa(nod, q.lis))
	{
		j++;
		nod= nod->next;
	}
	return (j);
}
int	prevrotmormid(t_queue q, int cs, int ce)
{
	t_node *k;
	int i;
	
	i = 0;
	k = q.tail;
	while (!((k->sval > (cs + ce) / 2) && k->sval <= ce)
		|| am_i_into_Lisa(k, q.lis))
	{
		i++;
		k = k->prev;
	}
	return (i + 1);
}

int prevrotlessmid(t_queue q, int cs, int ce)
{
	t_node *nod;
	int j;
	
	nod = q.tail;
	j = 0;
	while (!(nod->sval <= (cs + ce) / 2) || am_i_into_Lisa(nod, q.lis))
	{
		j++;
		nod = nod->prev;
	}
	return (j + 1);
}

t_node *nrotk(t_queue *q, t_node *reach_me)//useless
{
	t_node *k;
	
	k = q->head;
	while (q->head != reach_me)
	{
		ra(q);
		k = k->next;
	}
	return (k);
}

t_node *protk(t_queue *q, t_node *reach_me)//useless
{
	t_node *k;
	
	k = q->head;
	while (k != reach_me)
	{
		rra(q);
		k = k->prev;
	}
	return (k);
}


//strangely enough i found the reason for this code in the greedy when working on the chunk after changed it a bit
void	findrotation(t_queue q, t_node *k)//useless bad code
{
	if (nrotcost(q, k) <= protcost(q, k))
		reachnexttop(&q, k);//nexto or give me bool true 
	else
		reachprevtop(&q, k);//previo and false
}






































//USELESS SO FAR
// int findnextbest(t_queue q, int chart, int chend)
// {
// 	int i;
// 	int j;
// 	i = nextrotlessmid(q,chart,chend);
// 	j = nextrotmormid(q,chart,chend);
// 	if (i <= j)
// 		return i;
// 	return j;
// }
// int findprevbest(t_queue q, int chart, int chend)
// {
// 	if (prevrotlessmid(q,chart,chend) <= prevrotmormid(q,chart,chend))
// 		k = ;
// }
// bool whatIsBehindChunkNorrisChinBeard(t_stacks *s, int mezzo_churro)
// {
	// 	t_node *k;
	// 	//throguh nextrot and prevrot withing the current chunk and not intoLisa
	// 	if (nrnktp(s->a,mezzo_churro) <= prnktp(s->a,mezzo_churro))
	// 	{
// 		k = nrotk(s->a,);
// 		if (k = )
// 	}
// }
// ////
// aggiungi ad una func che riutorna nodo
// 	if (nrnktp(q,churro) <= prnktp(q,churro))
// 		return (&rr);
// 	return (&rb);
// ////
// func calcola se prossimo knot sia minore del knot appena inserito
// 	 e debba essere messo nella stessa posizione <midchunk (nel bottom)
// 	 e provenga da prevrotation altrimenti esegui rb o rr
// 	 cosi da tenere piu ordinato lo stack
// typedef t_node *(*t_rotfunc)(t_node **, t_node *);
// t_rotfunc findrotation(t_stacks *s, t_node *p, t_node *n)
// {
// 	if (nrotcost(s->a, n) <= protcost(s->a, p))
// 	return reachnextop;
// 	else
// 	return reachprevtop;
// }









































/*↓↓ useless stuff ↓↓*/
//calcolare next node to push that is into current chucnk and its cost.
// int howmuchisnextchunk(t_queue q, int cc, int range)
// {
// 	t_node *k;
	
// 	k=q.head;
// 	while (k > ccmin && k < ccmax)
// 	{
		
// 	}
// }
// //calcolo della size dei chunk in base alla size?
// int sizeChonkolatechipscookie()
// {
// 	nchunks = q.size / ;
// 	if (< chunksizesofar )
// 	chunksize = n - 1;
// }
// //ceiling() checks for both
// int checkchuendnotgreaterthanN(t_stacks s, int chuend)
// {
// 	return (chuend <= (s.a.size+s.b.size));
// }





