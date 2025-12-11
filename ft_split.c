/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:58:16 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/09 14:44:27 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_me(char **ss, size_t p)
{
	size_t	i;

	if (!ss)
		return ;
	i = 0;
	while (i < p)
	{
		free(ss[i]);
		i++;
	}
	free(ss);
	ss = NULL;
}

static size_t	count_chars(const char *s, char c)
{
	size_t	wordlen;
	size_t	i;

	i = 0;
	wordlen = 0;
	while (s[i] && s[i] != c)
	{
		wordlen++;
		i++;
	}
	return (wordlen);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char	*str_filler(const char *s, char c, size_t len)
{
	size_t	j;
	char	*sm_str;

	j = 0;
	sm_str = (char *) malloc(len + 1 * sizeof(char));
	if (sm_str == NULL)
		return (NULL);
	while (s[j] && s[j] != c)
	{
		sm_str[j] = s[j];
		j++;
	}
	sm_str[j] = '\0';
	return (sm_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	wordlen;
	size_t	i;
	char	**ss;

	i = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	ss = (char **) malloc((words + 1) * sizeof(char *));
	if (ss == NULL)
		return (NULL);
	while (words--)
	{
		while (*s == c)
			s++;
		wordlen = count_chars(s, c);
		ss[i] = str_filler(s, c, wordlen);
		if (ss[i] == NULL)
			return (free_me(ss, i), NULL);
		s += wordlen;
		i++;
	}
	ss[i] = NULL;
	return (ss);
}
