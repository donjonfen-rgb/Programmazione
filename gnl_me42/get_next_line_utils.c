/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:02:03 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/09 18:35:56 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strleng(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
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
		return (free(ss), NULL);
	if (ss)
		while (ss[++i])
			r[i] = ss[i];
	if (sl)
		while (sl[++j])
			r[i + j] = sl[j];
	return (r);
}

void	*ft_calloc(size_t n, size_t w)
{
	void			*a;
	unsigned char	*t;
	size_t			tot;

	if (n != 0 && w >= ((size_t)-1 / n))
		return (NULL);
	a = malloc(n * w);
	if (!a)
		return (NULL);
	t = (unsigned char *)a;
	tot = n * w;
	while ((tot)-- != 0)
		t[tot] = '\0';
	return (a);
}

char	*ft_subs(char *s, unsigned int index, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	sub = (char *) ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[i + index] && index < ft_strleng(s))
	{
		sub[i] = s[i + index];
		i++;
	}
	return (sub);
}
