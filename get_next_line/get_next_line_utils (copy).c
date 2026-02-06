/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:01:36 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/02 11:27:38 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinami (char *buffo, char *residuo)
{
	char	*joinedstr;
	char	*puntame;
	unsigned int	stringslength;

	if (!buffo || !residuo)
		return (NULL);
	stringslength = ft_strlengmi(buffo) + ft_strlengmi(residuo);
	joinedstr = (char *) ft_callocami(stringslength + 1, sizeof(char));
	if (!joinedstr)
		return (NULL);
	while (*buffo)
		*joinedstr++ = *buffo++;
	//o puntare qui +1, o puntare appena si aggiunge la seconda str
	puntame = joinedstr;
	while (*residuo)
		*joinedstr++ = *residuo++;
	return (joinedstr);
}

size_t	ft_strchrcami(char *str)// unisci con strelengmi
{
	unsigned int	cf;

	cf = 0;
	if (str)
	{
		while(str[cf] && str[cf] != '\n')
			cf++;
		// if (str[cf] == '\n')
		// 	cf = 1;
		printf("contraflag:%d\n",cf);
	}
	return (cf);
}

size_t	ft_strlengmi(char *lookintome)
{
	int	i;

	i = 0;
	if (lookintome[i] != 0)
	{
		while(lookintome[i] && lookintome[i] != '\n')
			i++;
	}
	printf("strlen:[%d]\n",i );
	return (i);
}

void	*ft_callocami(size_t emmn, size_t ueit)
{
	void	*alloc;
	unsigned char	*tempo_allocatio;

	if (emmn != 0 && ueit >= ((size_t)-1 / emmn))
		return (NULL);
	alloc = malloc(emmn * ueit);
	if (!alloc)
		return (NULL);
//you need this to visit and set 
//every single byte to 0, since we're moving 1by1
	tempo_allocatio = (unsigned char *)alloc;
	while (emmn-- != 0)
		tempo_allocatio[emmn] = '\0';
	//alloc = tempo_allocatio;
	return (alloc);
}
char	*ft_substringami(char *s, unsigned int start,size_t lungth)
{
	size_t	starter;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlengmi(s))
		return (ft_callocami(1,1));
	sub = (char *) ft_callocami((lungth + 1), sizeof(char));
	if (!sub)
		return (NULL);
	starter = 0;
	while (starter < lungth && *s)
	{
		sub[starter] = s[starter];
		starter++;
	}
	sub[starter] = '\0';
	return (sub);
}
