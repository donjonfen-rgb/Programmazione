/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:52:37 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/08 16:57:26 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			str[i] = 0; migliore((char *)s)[i++] = 0;
			i++;
		}
	}
}*/
/*ft_memset(s, 0, n);
((char *)s)[i++] = 0;
*/
