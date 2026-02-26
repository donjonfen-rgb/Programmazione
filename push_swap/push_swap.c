/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:13:11 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/26 23:29:57 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void read_me(char *inputs)
{
	
}

void	ft_creation()
{
	t_queue *a;
	t_queue *b;

	a = createQ();
	b = createQ();
}

void push_swap(int *nums)
{
	//chiama split return parole ft creation acquisisce ogni nodo
	ft_creation();
}

int main(int ac, char **av)
{
	int *vals;
	int i;
	int e;
	i = 1;
	if (ac < 2)
		return (error(0));
	
	if (ac == 2 && ft_pastramiOrSalami(av[i]))
		vals = ft_split(av[1]);
		if (e = ft_no_duplos(vals))
			return (ft_duploerror(e));
	else if (ac >2)
	{
		while (i < ac)
			if (ft_pastramiOrSalami(av[i]))
				vals[i-1] = ft_split(av[i++]);
		if (ft_no_duplos(vals))
			return (error(2));
	}
	push_swap(vals);
	free(vals);
	return 0;
}
