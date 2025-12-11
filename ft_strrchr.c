/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:40:05 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/08 13:55:09 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch_needle)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (((unsigned char *)str)[i] == (unsigned char) ch_needle)
		{
			return ((char *)(str + i));
		}
		i--;
	}
	return (NULL);
}

/* {
	char	*ptr;
	char	*sub;

	sub = (char *)str;
	while (*sub)
	{
		if (*sub == (char)ch_needle)
			ptr = sub;
		sub++;
	}
	if (ptr)
		return (ptr);
	return (sub);
} */
