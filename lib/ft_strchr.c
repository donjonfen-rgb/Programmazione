/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:03:24 by ggaritta          #+#    #+#             */
/*   Updated: 2025/11/25 13:05:46 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strchr(const char *str, int ch_needle)
{
	char *sub;
	
	sub = (char *)str;
	while (*sub)
		if(sub == ch_needle)
			return(sub);
	return (sub);
}
