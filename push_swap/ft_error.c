/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:59:14 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/26 23:32:07 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*• In case of error, it must display "Error" followed by an ’\n’ 
on the standard error.
Errors include, for example: some arguments not being integers, 
some arguments exceeding the integer limits, and/or the presence 
of duplicates*/
void ft_duploerror(long)
{
	printf("Error\n This number was already read: %ld\n");
}

void ft_nerror(long n)
{
	printf("Error\n This is not an int: %ld\n");
}
