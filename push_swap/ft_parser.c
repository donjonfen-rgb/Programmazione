/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:27 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/26 22:58:31 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool ft_pastramiOrSalami(char *str)
{
	while(*str)
		if(!isN(str) || !isWS(str))
			return false;
		str++;
}
bool isN(char c)
{
	return ((c >= 48 && c <= 57));
}

void ft_no_duplo(int *vals)
{
	int j,i = 0;
	//check if number appeared in list
	while (vals[i]!= NULL)
	{
		j = 1;
		while (vals[j])
			if(vals[i] == vals[j])
				return (false);
	}
	return (true);
}

void ft_afterPastrami()
{
	
}