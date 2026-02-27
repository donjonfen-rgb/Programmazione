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
	//incomplete
	if(e == 0)
		ft_nerror(num);
	else if (1)
	{}
	else if (2)
		ft_duploerror(num);
}
void ft_duploerror(long)
{
	printf("Error\n This number was already read: %ld\n");
}

void ft_nerror(long n)
{
	printf("Error\n This is not an int: %ld\n");
}
// void exit_error(void)
// {
//     fprintf(stderr, "Error\n");
//     exit(EXIT_FAILURE);
// }