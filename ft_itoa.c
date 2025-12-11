/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:15:27 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/09 15:03:12 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(long n)
{
	int	plusplusme;

	plusplusme = 0;
	if (n <= 0)
	{
		plusplusme = 1;
		n = n * -1;
	}
	while (n != 0)
	{
		n /= 10;
		plusplusme++;
	}
	return (plusplusme);
}

static char	*do_me(char *str, int nlen, long lnum)
{
	while (lnum > 0)
	{
		str[--nlen] = (lnum % 10) + '0';
		lnum /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	long	lnum;

	lnum = (long) n;
	nlen = numlen(lnum);
	str = malloc((nlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (lnum < 0)
	{
		str[0] = '-';
		lnum *= -1;
	}
	if (lnum == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = do_me(str, nlen, lnum);
	str[nlen] = '\0';
	return (str);
}

/* int main ()
{
	int num = 124567890;
	char *ptr;

	ptr = ft_itoa(num);
	printf("%s\n",ptr);
} */

/*
static void		lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		len;
	int			weight;
	size_t		cur;
	char		*str;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	str[cur] = '\0';
	return (str);
}
	*/