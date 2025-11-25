/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:23:55 by ggaritta          #+#    #+#             */
/*   Updated: 2025/11/25 11:38:26 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *str, int ch, size_t counter)
{
	size_t i;
	unsigned char *s;
	s = (unsigned char *) str;

	i = 0;
	while(i < counter)
	{
		s[i] = ch;
		i++;
	}
	return (s);
}
