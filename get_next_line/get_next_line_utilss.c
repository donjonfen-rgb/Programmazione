/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilss.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:01:36 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/04 14:48:40 by ggaritta         ###   ########.fr       */
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
		printf("contraflag:%d\n",cf);
	}
	return (cf);
}

size_t	ft_strlengmi(char *lookintome)
{
	int	i;

	i = 0;
size_t	ft_strlenchr(char *lookintome, int flag)
{
	int	i;

	i = 0;
	if (lookintome[i] != 0)
	{
		while(lookintome[i] && (lookintome[i] == '\n' + flag))
		{
			if (lookintome[i] != '\n')
				
			i++;
		}
	}
	printf("strlen:[%d]\n",i );
	return (i);
}
	if (lookintome[i] != 0)
	{
		while(lookintome[i] && lookintome[i] != '\n')
			i++;
	}
	printf("strlen:[%d]\n",i );
	return (i);

/*
size_t	ft_strlenchr(char *lookintome, int flag)
{
	int	i;

	i = 0;
	if (lookintome[i] != 0)
	{farsi passare una flag se devi cercare \n o meno cosi' da vedere se 
		cosa ti ritorna 0-1 | 0-2???
		while(lookintome[i] && (lookintome[i] == '\n' + flag))
		{
			if (lookintome[i] != '\n')
				
			i++;
		}
	}
	printf("strlen:[%d]\n",i );
	return (i);
}
*/

void	*ft_callocami(size_t emmn, size_t ueit)
{
	void			*alloc;
	unsigned char	*tempo_allocatio;

	if (emmn != 0 && ueit >= ((size_t)-1 / emmn))
		return (NULL);
	alloc = malloc(emmn * ueit);
	if (!alloc)
		return (NULL);
	tempo_allocatio = (unsigned char *)alloc;
	while (emmn-- != 0)
		tempo_allocatio[emmn] = '\0';
	return (alloc);
}

char	*ft_substringami(char *s, unsigned int start, size_t lungth)
{
	size_t	starter;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlengmi(s))
		return (ft_callocami(1, 1));
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
/*
#include "get_next_line.h"


size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
	if (!ss && *ss != '\n')
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
*/

480p 6,65 720p 15,05
