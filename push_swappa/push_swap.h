/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:45:06 by ggaritta          #+#    #+#             */
/*   Updated: 2026/05/02 16:02:27 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node	t_node;
typedef struct s_coord	t_coord;
typedef struct s_queue	t_queue;
typedef enum e_strat	t_strat;
typedef void (*t_op)(t_queue *);

struct s_node
{
	int		idx;//pos? anche se iniziale, ti aggiorno ogni volta a questo punto
	t_node	*idsubseq;
	int		valis;
	int		sval;
	int		value;
	t_node	*next;
	t_node	*prev;
};

struct s_queue
{
	t_node	*head;
	t_node	*tail;
	t_node	*lis;
	int		size;
};

typedef struct s_stacks
{
	t_queue	a;//controllare se serve mandare come ptr
	t_queue	b;
}	t_stacks;

typedef enum e_strat
{
	RR,
	RRR,
	RA_RRB,
	RRA_RB
} t_strat;

struct s_coord
{
	t_node	*ak;
	t_node	*bk;
	// char	eorivl;//-1 int, 1 ext e i
	int		ac;
	char	adir;// 0 or 1 n p
	int		bc;
	char	bdir;// 0 or 1 n p
	int		totc;
	t_strat	strat;
};

/* push_swap.c */
void		precontrols(void);
void		push_swap(t_stacks *s);

/* ft_qops.c */
t_stacks	*create_stacks(void);
bool		qie(t_queue q);
t_node		*knot_me(int val, int id);
void		k2q(t_queue *q, t_node *newNod);
void		knot_of_interest(t_queue q);
void		decappler_two_point_o(t_stacks *s);

/* ft_moves.c */
void		swp(t_queue *q);
void		sa(t_queue *q);
void		sb(t_queue *q);
void		ss(t_stacks *s);
void		push(t_queue *from, t_queue *to);
void		pa(t_stacks *s);
void		pb(t_stacks *s);
void		scroll_up(t_queue *q);
void		ra(t_queue *a);
void		rb(t_queue *b);
void		rr(t_stacks *s);
void		scroll_down(t_queue *q);
void		rra(t_queue *a);
void		rrb(t_queue *b);
void		rrr(t_stacks *s);
t_node		*get_alas(t_node *e);
void		reachprevbot(t_queue *q, t_node *reachme);
void		reachnextbot(t_queue *q, t_node *reachme);
void		reachprevtop(t_queue *q, t_node *reachme);
void		reachnexttop(t_queue *q, t_node *reachme);

/* ft_split.c */
bool		isWS(char c);
int		findWords(char *s);
int		ft_strtolol(char **num, int *out);
int		*split(char *s);

/* ft_parser.c */
bool		check_if_sortdimamt(t_queue q);
bool		isN(char c);
bool		ft_pastramiOrSalami(char *str);
bool		ft_no_duplos(int *vals);
t_node		*ft_schivoPeterMinum(t_queue q);
void		ft_howMuchisPastrami(t_queue *q);
t_stacks	*assignidxs(t_stacks *s);
t_queue		*alltheknots(t_stacks *s, int argc, char **argv);

/* ft_error.c */
void		ft_errors(long num, int e);
void		ft_duploerror(long num);
void		ft_nerror(long n);
int		exit_error(t_stacks *s);

/* ft_libft.c */
void		*ft_helloitsmecalloc(size_t n, size_t w, char c);

/* ft_lis.c */
t_node		*fat_lisa(t_queue q);
void		theTamingoftheShrewLisa(t_queue *q);
bool		isqmadeonlyoflisskeletonelements(t_queue q);
void		lizCheney(t_queue *q);
bool		am_i_into_Lisa(t_node *k, t_node *lk);
int		LookIn_my_gapeS(t_node *k);
void		lisEandataVia(t_queue *q);
void		lis_phase(t_queue *q);

/* ft_sorting_utilities.c */
int		ft_sval_pippino(t_queue q);
t_node		*pikmin(t_queue q);
t_node		*pokmon(t_queue q);

/* ft_sortini.c */
void		sort_too(t_stacks *s);
void		sort_thee(t_stacks *s);
void		sort_flour(t_stacks *s);
void		sort_faiv(t_stacks *s);
void		lesortdimamt(t_stacks *s);
void	print_stacks(t_stacks *s);

/* ft_chonkers.c */
t_node		*nrnktp(t_stacks *s, int cs, int ce);
t_node		*prnktp(t_stacks *s, int cs, int ce);
void		inversa_lafinestra_intelligente(t_stacks *s);

/* ft_chonkers_utils.c */
int		chunk_size(int n);
int		ft_sqrt(int n);
int		ch_malcolm_in_the_middle(int start, int end);
bool		ceiling(t_stacks s, int *chs, int *che);
int		nrotcost(t_queue q, t_node *n);
int		protcost(t_queue q, t_node *p);
void		findbestrottenknot(t_stacks *s, int *chus, int *chue);
void		save_me_nrotmin(t_stacks *s, t_node *n, int *cs, int *ce);
void		save_me_nroteq(t_stacks *s, t_node *p, t_node *n, int *cs, int *ce);
void		push_me_knot(t_stacks *s, int *chus, int *chue);
void		predict_me_Knot(t_stacks *s, int *cs, int *ce);
void		save_me_rot(t_stacks *s, t_node *p, t_node *n, int *cs, int *ce);
t_node		*fifnk(t_stacks s, int i);
t_node		*fifpk(t_stacks s, int i);
int		nextrotmormid(t_queue q, int cs, int ce);
int		nextrotlessmid(t_queue q, int cs, int ce);
int		prevrotmormid(t_queue q, int cs, int ce);
int		prevrotlessmid(t_queue q, int cs, int ce);
t_node		*nrotk(t_queue *q, t_node *reach_me);
t_node		*protk(t_queue *q, t_node *reach_me);
void		findrotation(t_queue *q, t_node *p, t_node *n);
bool r_u_chuck_schumer(t_node *k, int ceiling);
void givemefunction(t_stacks *s, int *chus, int *chue);

/* ft_griddy.c */
void		mc_griddy(t_stacks *s);
void		scrooge_mcrot(t_stacks *s, t_coord *xy);

/* ft_griddy_utils.c */
void		calldoublespin(t_stacks *s, t_node *ak, t_node *bk, int rot);
int		maxvalo(int n, int m);
int		minvalo(int i, int j);
int		*remaining_rich_by_being_the_most_miserable(t_stacks *s, t_coord *xy);
void		blind_date(t_stacks *s, t_coord *xy);
void		tinder(t_queue a, t_coord *zd);
void		reachtop(t_stacks *s, t_coord *xy);
void		concord(t_stacks *s, t_coord *xy);
void		remainingroots(t_stacks *s, t_coord *xy);
void		setmeup(t_stacks *s, t_coord *xy);
void		final_sortami(t_stacks *s);

#endif
// ./pushwap numeri | ./checker  stessa lista numeri