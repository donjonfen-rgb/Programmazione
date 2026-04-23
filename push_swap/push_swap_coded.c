/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_coded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:13:11 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/23 17:33:04 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_dup(t_queue q, int v)
{
	t_node	*k;

	k = q.head;
	while (k)
	{
		if (k->value == v)
			return (1);
		k = k->next;
	}
	return (0);
}

static int	append_value(t_stacks *s, int value, int *idx)
{
	t_node	*k;

	if (is_dup(s->a, value))
		return (1);
	k = knot_me(value, *idx);
	if (!k)
		return (1);
	k2q(&s->a, k);
	(*idx)++;
	return (0);
}

static int	parse_arg(t_stacks *s, char *arg, int *idx)
{
	char	*end;
	long	v;

	while (*arg)
	{
		while (*arg && isWS(*arg))
			arg++;
		if (!*arg)
			break ;
		v = strtol(arg, &end, 10);
		if (arg == end || v < INT_MIN || v > INT_MAX)
			return (1);
		if (append_value(s, (int)v, idx))
			return (1);
		arg = end;
	}
	return (0);
}

static int	load_inputs(t_stacks *s, int ac, char **av)
{
	int	i;
	int	idx;

	i = 1;
	idx = 0;
	while (i < ac)
	{
		if (parse_arg(s, av[i], &idx))
			return (1);
		i++;
	}
	return (0);
}

static int	exit_error(t_stacks *s)
{
	write(2, "Error\n", 6);
	decappler_two_point_o(s);
	return (1);
}

void precontrols()
{
	
}

void push_swap(t_stacks *s)
{
	if (!s || s->a.size < 2)
		return ;
	ft_howMuchisPastrami(s->a);
	if (s->a.size <= 5)
		lesortdimamt(s);
}

int main(int ac, char **av)
{
	t_stacks *s;
	int i;
	
	i = 1;
	// if (ac == 2)
	// 	return (error(0));
	
	if (ac == 2 && ft_pastramiOrSalami(av[i]))
		s.a.head = ft_split(av[1]);// check me knot me up fillinmg
	else if (ac > 2)
	{
		while (i < ac)
			if (ft_pastramiOrSalami(av[i]))
				s.a.head = ft_split(av[i++]);
	}
	if (ft_no_duplos(s.a.head))
	{
		ft_duploerror(2);
		return (0);
	}
	// if (ac < 2)
	// 	return (0);
	// s.a = (t_queue){NULL, NULL, NULL, 0};
	// s.b = (t_queue){NULL, NULL, NULL, 0};
	// if (load_inputs(&s, ac, av))
	// 	return (exit_error(&s));
	s = create_stacks();
	push_swap(&s);
	decappler_two_point_o(&s);
	return (0);
}
// int main(int ac, char **av)
// {
// 	int *vals;
// 	int i;
// 	i = 1;
// 	if (ac < 2)
// 		return (error(0));
// 	if (ac == 2 && ft_pastramiOrSalami(av[i]))
// 		vals = ft_split(av[1]);
// 		if (ft_no_duplos(vals))
// 			return (ft_duploerror(2));
// 	else if (ac >2)
// 	{
// 		while (i < ac)
// 			if (ft_pastramiOrSalami(av[i]))
// 				vals[i-1] = ft_split(av[i++]);
// 		if (ft_no_duplos(vals))
// 			return (ft_duploerror(2));
// 	}
	
// 	push_swap(vals);
// 	free(vals);
// 	return 0;
// }
