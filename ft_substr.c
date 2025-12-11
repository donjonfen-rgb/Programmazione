/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:36:39 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/06 16:03:13 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	starter;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	starter = 0;
	while (starter < len && s)
	{
		sub[starter] = s[start + starter];
		starter++;
	}
	sub[starter] = '\0';
	return (sub);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[]= "che mondo marcio";
	char b = 5;
	//printf("%d\n", ft_word_equal(a, b));
	printf("%s\n", ft_substr(a,b,10));
}*/