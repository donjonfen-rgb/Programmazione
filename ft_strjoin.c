/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:13:06 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/06 16:34:54 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	slen;
	char			*inizio;
	char			*strj;

	if (!s1 || !s2)
		return (NULL);
	slen = ft_strlen(s1) + ft_strlen(s2);
	strj = (char *) malloc((slen + 1) * sizeof(char));
	if (strj == NULL)
		return (NULL);
	inizio = strj;
	while (*s1)
	{
		*strj++ = *s1++;
	}
	while (*s2)
	{
		*strj++ = *s2++;
	}
	*strj = '\0';
	return (inizio);
}
/*
int main ()
{
	char s1[] ="qwertyuiop"; 
	char s2[] ="pai"; 
	char *joined = ft_strjoin(s1,s2);
	
	while(*joined){printf("[%c]",*joined);joined++;}
	//printf("%s\n",joined);
}*/
/*char *ft_strjoin(char const *s1, char const *s2)
{
	unsigned int slen;
	int i,j;
	i=0;j=0;
	slen = ft_strlen(s1) + ft_strlen(s2);
	printf("%u",slen);
	char *strj = (char *) malloc((slen+1)*sizeof(char));
	if(strj == NULL)
	{  
		printf("sono null");
		return NULL;
	}
	if (s1 == 0 || s2 == 0)
		return (0);
	//unsigned int s1l;
	//s1l = ft_strlen(str1);
	while (s1[i])
	{   
		printf("sono 1w");
		strj[i] = s1[i];i++;
	//  printf("s1[%c]",*strj);
	}
	while (s2[j])
	{    printf("sono 2w");
		strj[i+j] = s2[j];j++;
//      printf("s2[%c]",*strj);
	}
	strj[i+j] = '\0';
	return(strj);
}*/