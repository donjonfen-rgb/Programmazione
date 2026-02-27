/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:44:32 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/27 20:50:07 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool isWS(char c)
{
	return (c == ' ' || c == '	' || c == '\n' );
}

int findWords(char *s)
{
	int	i;
	int j;

	i = 0;
	while (s[i])
	{
		while(s[i] != NULL && isWS(s[i]))
			i++;
		if (s[i] != NULL && !isWS(s[i]))
			j++;
		while(s[i] && !isWS(s[i]))
			i++;
		}
	return (j);
}

// char *putWord(char *s)
// {
// 	int i;
// 	char *chnumeretto;

// 	i=0;
// 	while(s[i] && !isWS(s[i]))
// 		i++;
// 	chnumeretto = (char *) malloc((i+1) * sizeof(char));
// 	chnumeretto[i] = '\0';
// 	while (i >= 0)
// 	{
// 		chnumeretto[i] = s[i];
// 		i--;
// 	}
// 	return (chnumeretto);
// }
// char *split(char *s)
// {
// 	size_t len;
// 	char **mat;
// 	int i;
// 	int j;
// 	len = findWords(s);
// 	mat = (char **) malloc((len + 1) * sizeof(char *));
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		while(s[i] != NULL && isWS(s[i]))
// 			i++;
// 		if (s[i] != NULL && !isWS(s[i]))
// 		{
// 			mat[j] = putWord(&s[i]);
// 			j++;
// 		}
// 		while(s[i] && !isWS(s[i]))
// 			i++;
// 	}
// 	mat[j] = '\0';
// 	return (mat);
// }

int ft_strtololol(char *num)
{
	long n;

	n = 1;
	if(*num++ == 43)
		n *= (-1);
	while (*num && *num > 47 && *num < 58)//or isWS
	{
		n = n * 10 + (*num - 48);
		num++;
	}
	if (n < INT_MIN || n > INT_MAX)
		ft_nerror(n);
	return n;
}

int *split(char *s)
{
	size_t len;
	int **mat;
	int i;
	int j;
	len = findWords(s);
	mat = (int **) malloc((len + 1) * sizeof(int *));
	i = 0;
	j = 0;
	while (s[i])
	{
		while(s[i] != NULL && isWS(s[i]))
			i++;
		if (s[i] != NULL && !isWS(s[i]))
		{
			mat[j] = ft_strtololol(&s[i]);
			j++;
		}
		while(s[i] && !isWS(s[i]))
			i++;
	}
	mat[j] = '\0';
	return (mat);
}

