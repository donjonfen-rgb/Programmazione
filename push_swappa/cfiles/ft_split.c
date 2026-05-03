/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:44:32 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/24 17:40:02 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool isWS(char c)
{
	return (c == ' ' || c == '	' || c == '\n' );
}

bool ft_no_duplos(int *vals)
{
	int	j;
	int	i;

	i = 0;
	while (vals[i] != INT_MIN)
	{
		j = i + 1;
		while (vals[j] != INT_MIN)
		{
			if (vals[i] == vals[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int findWords(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && isWS(s[i]))
			i++;
		if (s[i] && !isWS(s[i]))
			j++;
		while (s[i] && !isWS(s[i]))
			i++;
	}
	return (j);
}

int	ft_strtolol(char **num, int *out)
{
	long	n;
	long	lim;
	int		neg;
	int		d;

	n = 0;
	neg = 1;
	if (**num == '+' || **num == '-')
		if (*(*num)++ == '-')
			neg = -1;
	if (!isN(**num))
		return (1);
	lim = INT_MAX;
	if (neg == -1)
		lim = -(long)INT_MIN;
	while (isN(**num))
	{
		d = **num - '0';
		if (n > (lim - d) / 10)
			return (1);
		n = n * 10 + d;
		(*num)++;
	}
	if (**num && !isWS(**num))
		return (1);
	*out = (int)(n * neg);
	return (0);
}

int *split(char *s)
{
	size_t	len;
	int		*mat;
	char	*p;
	int		j;

	p = s;
	j = 0;
	len = findWords(s);
	mat = (int *)malloc((len + 1) * sizeof(int));
	if (!mat)
		return (NULL);
	while (*p)
	{
		while (*p && isWS(*p))
			p++;
		if (*p && !isWS(*p))
		{
			if (ft_strtolol(&p, &mat[j]))
			{
				free(mat);
				return (NULL);
			}
			j++;
		}
	}
	mat[j] = INT_MIN;
	return (mat);
}

