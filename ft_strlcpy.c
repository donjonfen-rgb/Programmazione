/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:29:58 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/06 16:25:44 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t size)
{
	size_t	i;
	size_t	ls;

	i = 0;
	if (size == 0)
		return (ft_strlen(s));
	if (size > 0)
	{
		while (i < (size - 1) && s[i] != '\0')
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	ls = ft_strlen(s);
	return (ls);
}
