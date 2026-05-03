#include "push_swap.h"

int	chunk_size(int n)
{
	int size;

	size = 5 * ft_sqrt(n);
	if (size < 10)
		size = 10;
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

bool r_u_chuck_schumer(t_node *k, int ceiling)
{
	if (!k)
		return (false);
	else if (k->sval > ceiling)
		return (false);
	// if (am_i_into_Lisa(k, q.lis))
	else if (k->valis != -1)
		return (false);
	return (true);
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

	chsize = *che - *chs;
	n = s.a.size + s.b.size;
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
	t_node	*k;
	int		i;

	if (!n)
		return (q.size);
	i = 0;
	k = q.head;
	while (k && k->sval != n->sval)
	{
		k = k->next;
		i++;
	}
	if (!k)
		return (q.size);
	return (i);
}

//greedy
int protcost(t_queue q, t_node *p)
{
	t_node	*k;
	int		i;

	if (!p)
		return (q.size);
	// if (p == q.head)
	// 	return (0);
	i = 0;
	k = q.tail;
	while (k && k->sval != p->sval)
	{
		k = k->prev;
		i++;
	}
	if (!k)
		return (q.size);
	return (i + 1);
}

void givemefunction(t_stacks *s, int *chus, int *chue)
{
	int	mid;
	int ni;
	int pi;

	mid = ch_malcolm_in_the_middle(*chus, *chue);
	if (s->b.head && s->b.head->sval > mid)
		return ;
	ni = nextrotlessmid(s->a, *chus, *chue);
	pi = prevrotlessmid(s->a, *chus, *chue);
	if (ni <= pi && ni < s->a.size)
		rr(s);
	else
		rb(&s->b);
	// //print_stacks(s);
}

void save_me_nrotmin(t_stacks *s, t_node *n, int *cs, int *ce)
{
	int 	mid;

	// printf("b.head=%p\n", (void*)s->b.head);
	if (!n || !s->b.head)
		return ;
	mid = ch_malcolm_in_the_middle(*cs, *ce);
	if (nrotcost(s->a, n) < protcost(s->a, n))
	{
		if (n->sval <= mid && (n->sval > s->b.head->sval))
			rr(s);
		else if (n->sval <= mid && (n->sval < s->b.head->sval))
		{
			reachnexttop(&s->a, n);
			push_me_knot(s, cs, ce);
			//print_stacks(s);
			rb(&s->b);
			rb(&s->b);
			//print_stacks(s);
		}
		//print_stacks(s);
	}
	// printf("nrotcost not min than prot");
	//print_stacks(s);
}

//find best node with preference to the simple rotate elements
void save_me_nroteq(t_stacks *s, t_node *p, t_node *n, int *cs, int *ce)
{
	// printf("b.head=%p\n", (void*)s->b.head);
	if (!p || !n || !s->b.head)
		return ;
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
		// printf("saveroteq");
		//print_stacks(s);
	}
}

// void push_me_knot(t_stacks *s, int *chus, int *chue)
// {
// 	int mid;
// 	int pushed;
// 	if (!s || !s->a.head)
// 		return ;
// 	if (am_i_into_Lisa(s->a.head, s->a.lis))
// 		return ;
// 	pb(s);
// 	if (s->b.head && pushed <= mid)
// 		rb(&s->b);
// 	ceiling(*s, chus, chue);
// }
void push_me_knot(t_stacks *s, int *chus, int *chue)
{
	if (!s || !s->a.head)
		return ;
	if (am_i_into_Lisa(s->a.head, s->a.lis))
		return ;
	pb(s);
	ceiling(*s,chus,chue);
}

// if (xy->adir == xy->bdir)
// 	concord(s, xy);
// remainingroots(s, xy);
void save_me_rot(t_stacks *s, t_node *p, t_node *n, int *cs, int *ce)
{
	if (nrotcost(s->a, n) < protcost(s->a, p))
		save_me_nrotmin(s, n, cs, ce);
	else if (nrotcost(s->a, n) == protcost(s->a, p))
		save_me_nroteq(s, p, n, cs, ce);
}

//from int find next node
t_node *fifnk(t_stacks s, int i)
{
	t_node *k;

	k = s.a.head;
	while (i > 0 && k)
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
	while (i > 0 && k)
	{
		k = k->prev;
		i--;
	}
	return (k);
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

int	nextrotlessmid(t_queue q, int cs, int ce)
{
	t_node	*nod;
	int		j;
	int		mid;

	j = 0;
	mid = ch_malcolm_in_the_middle(cs, ce);
	nod = q.head;
	while (nod && !(nod->valis == -1 && nod->sval <= mid))
	{
		j++;
		nod = nod->next;
	}
	if (!nod)
		return (q.size);
	return (j);
}

int	prevrotlessmid(t_queue q, int cs, int ce)
{
	t_node	*nod;
	int		j;
	int		mid;

	nod = q.tail;
	j = 0;
	mid = ch_malcolm_in_the_middle(cs, ce);
	while (nod && !(nod->valis == -1 && nod->sval <= mid))
	{
		j++;
		nod = nod->prev;
	}
	if (!nod)
		return (q.size);
	return (j);
}

int	prevrotmormid(t_queue q, int cs, int ce)
{
	t_node	*k;
	int		i;
	int		mid;

	i = 0;
	mid = ch_malcolm_in_the_middle(cs, ce);
	k = q.tail;
	while (k && !(k->valis == -1 && k->sval > mid && k->sval <= ce))
	{
		i++;
		k = k->prev;
	}
	if (!k)
		return (q.size);
	return (i);
}

int	nextrotmormid(t_queue q, int cs, int ce)
{
	t_node	*k;
	int		i;
	int		mid;
	
	i = 0;
	mid = ch_malcolm_in_the_middle(cs, ce);
	k = q.head;
	while (k && !(k->valis == -1 && k->sval > mid && k->sval <= ce))
	{
		i++;
		k = k->next;
	}
	if (!k)
		return (q.size);
	return (i);
}

//strangely enough i found the reason for this code in the greedy when working on the chunk after changed it a bit
void	findrotation(t_queue *q, t_node *p, t_node *n)//useless bad code
{
	if (nrotcost(*q, n) <= protcost(*q, p))
		reachnexttop(q, n);//nexto or give me bool true 
	else
		reachprevtop(q, p);//previo and false
}

// USELESS SO FAR
//  int findnextbest(t_queue q, int chart, int chend)
//  {
//  	int i;
//  	int j;
//  	i = nextrotlessmid(q,chart,chend);
//  	j = nextrotmormid(q,chart,chend);
//  	if (i <= j)
//  		return i;
//  	return j;
//  }
//  int findprevbest(t_queue q, int chart, int chend)
//  {
//  	if (prevrotlessmid(q,chart,chend) <= prevrotmormid(q,chart,chend))
//  		k = ;
//  }
//  bool whatIsBehindChunkNorrisChinBeard(t_stacks *s, int mezzo_churro)
//  {
//  	t_node *k;
//  	//throguh nextrot and prevrot withing the current chunk and not intoLisa
//  	if (nrnktp(s->a,mezzo_churro) <= prnktp(s->a,mezzo_churro))
//  	{
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
