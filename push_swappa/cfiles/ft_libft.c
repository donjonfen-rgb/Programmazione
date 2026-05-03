/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:21:52 by ggaritta          #+#    #+#             */
/*   Updated: 2026/03/20 19:54:43 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_helloitsmecalloc(size_t n, size_t w, char c)//get the char needed to call
{
	void			*a;
	unsigned char	*t;
	size_t			tot;

	if (n != 0 && w >= ((size_t)-1 / n))
		return (NULL);
	a = malloc(n * w);
	if (!a)
		return (free(a), NULL);
	t = (unsigned char *)a;
	tot = n * w;
	while ((tot)-- != 0)
		t[tot] = c;//'\0'
	return (a);
}

