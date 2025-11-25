/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:40:05 by ggaritta          #+#    #+#             */
/*   Updated: 2025/11/25 13:03:00 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(const char *str, int ch_needle)
{
	char *ptr;
	char *sub;

	sub = (char *)str;
	while (*sub)
	{
		if(sub == ch_needle)
			ptr = sub;
		sub++;
	}
	if (ptr)
		return (ptr);
	return(sub);
}
