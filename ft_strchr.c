/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:03:24 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/06 16:19:55 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch_needle)
{
	char	*sub;

	sub = (char *)str;
	while (*sub)
	{
		if (*sub == (char)ch_needle)
			return (sub);
		sub++;
	}
	if ((char)ch_needle == '\0')
		return (sub);
	return (0);
}
/* int main (){
	char *str = "qwertyuio";
	int c = 't';

	printf("%s",ft_strchr(str,c));
} */