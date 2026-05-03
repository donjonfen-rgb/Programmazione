/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:59:14 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/27 20:01:15 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*• In case of error, it must display "Error" followed by an ’\n’ 
on the standard error.
Errors include, for example: some arguments not being integers, 
some arguments exceeding the integer limits, and/or the presence 
of duplicates*/

void ft_errors(long num, int e)
{
	(void)num;
	(void)e;
	write(2, "Error\n", 6);
}

void ft_duploerror(long n)
{
	(void)n;
	write(2, "Error\n", 6);
}

void ft_nerror(long n)
{
	(void)n;
	write(2, "Error\n", 6);
}

int	exit_error(t_stacks *s)
{
	ft_errors(0, 0);
	decappler_two_point_o(s);
	return (1);
}
// void exit_error(void)
// {
//     fprintf(stderr, "Error\n");
//     exit(EXIT_FAILURE);
// }