/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:13:11 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/27 21:18:22 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stacks s)
{
	
}

int main(int ac, char **av)
{
	t_stacks s;
	int i;
	
	i = 1;
	if (ac < 2)
		return (error(0));
	if (ac == 2 && ft_pastramiOrSalami(av[i]))
		s.a.head = ft_split(av[1]);
		if (ft_no_duplos(s.a.head))
			return (ft_duploerror(2));
	else if (ac >2)
	{
		while (i < ac)
			if (ft_pastramiOrSalami(av[i]))
				s.a.head = ft_split(av[i++]);
		if (ft_no_duplos(s.a.head))
			return (ft_duploerror(2));
	}
	ft_howMuchisPastrami(s.a);
	push_swap(s);
	decappler(s.a);
	return 0;
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
