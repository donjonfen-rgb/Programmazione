/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:02:03 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/04 17:49:19 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strleng(char *s)
{
	size_t	i;
	
	if (!s)
		return (0);
	i = 0;
	while(s[i])
		i++;
	return (i);
}
char *ft_strchr(const char *s,int c)
{
	int	i;
	
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (*s == (char )c)
			return (++i);
		s++;
	}
	return (-1);
}

char	*ft_join(char *ss, char	*sl)
{
	char	*r;
	int		i;
	int		j;

	i = -1;
	j = -1;
	r = (char *) ft_calloc((ft_strleng(ss) + ft_strleng(sl) + 1), sizeof(char));
	if (!r)
		return (NULL);
	while (ss[i++])
		r[i] = ss[i];
	free(ss);
	while (sl[j++])
		r[i + j] = sl[j];
	r[i + j] = '\0';
	return (r);
}

void	*ft_calloc(size_t n, size_t w)
{
	void			*a;
	unsigned char	*t;

	if (n != 0 && w >= ((size_t)-1 / n))
		return (NULL);
	a = malloc(n * w);
	if (!a)
		return (NULL);
	t = (unsigned char *)a;
	while (n-- != 0)
		t[n] = '\0';
	return (a);
}

char	*ft_substr(char *s, unsigned int index, size_t len)
{
	size_t	i;
	char	*sub;
	
	if (!s)
		return (NULL);
	sub = (char *) ft_calloc(len - i + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while(i < len && *s)
	{
		sub[i] = s[i+index];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}




