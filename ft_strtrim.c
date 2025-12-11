/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:42:34 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/09 16:11:24 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ami_in(char c, const char *set)
{
	int	k;

	k = 0;
	while (set[k])
	{
		if (c == set[k])
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	char	*nts;

	if (s1 == NULL)
		return ((char *)s1);
	if (!set)
		return ((char *)s1);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ami_in(s1[i], set) == 1)
		i++;
	while (j > i && ami_in(s1[j], set))
		j--;
	nts = (char *) malloc((j - i + 1) * sizeof(char));
	if (!nts)
		return (NULL);
	ft_memcpy(nts, s1 + i, j - i + 1);
	nts[j - i + 1] = '\0';
	return (nts);
}

/* int main ()
{
	char *str = "";
	char *set = "";
	printf("[%s]",ft_strtrim(str,set));
	printf("%s\n", ft_strtrim("   hello world   ", " "));
	printf("%s\n", ft_strtrim("xxx42xxx", "x"));
	printf("%s\n", ft_strtrim("no-trim", ""));
	printf("%s\n", ft_strtrim("xxxxx", "x"));
	printf("%s\n", ft_strtrim("abc", " "));
	printf("%s\n", ft_strtrim("123abc321", "123"));
	printf("%s\n", ft_strtrim(" \n\t...hello...\t", " .\n\t"));
	printf("%s\n", ft_strtrim("", " "));
	printf("%s\n", ft_strtrim("abc", "abc"));
	printf("%s\n", ft_strtrim("aaaaaaHELLOaaaaaa", "a"));
} */
// testare posizione del null

/*chiamare substr per accorciare
 malloc nts fino a return*/
/*char *ft_strtrim(const char *s1, const char *set)
{
	size_t starter;//idem as below
	size_t ender;//make them ptrs to the str to run
	char *nicely_trimmed_str;
	//char *inizio;
	starter = 0;
	ender = ft_strlen(s1);
	while (*s1 && ami_in(*s1,set))
	{
		starter++;
		s1++;
		printf("starter %zu\n",starter);
		printf("i'm set %c\n",*set);
	}
	*inizio = s1[starter];//da problemi anche se commentato
	//printf("l'inizio %c\n",*inizio);
	s1 +=  ft_strlen(s1)-1;
	while (*s1 && ami_in(*s1,set))
	{
		ender--;
		s1--;
		printf("ender %zu\n",ender);
	}
	printf("%zu %zu",ender,starter);
	nicely_trimmed_str = (char *) 
	malloc((ender-starter+1)*sizeof(char));
	if (!nicely_trimmed_str)
		return NULL;
	nicely_trimmed_str = ft_memcpy(nicely_trimmed_str, s1+starter, 
	(ender - starter + 1));
	return (nicely_trimmed_str);
}*/