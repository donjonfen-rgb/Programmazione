/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:23:55 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/03 11:33:50 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		s[i] = ch;
		i++;
	}
	return ((void *)s);
}
