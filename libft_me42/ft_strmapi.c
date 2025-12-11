/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 23:21:08 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/06 16:01:35 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
/*char funzione(unsigned int index, char charrino)
{
	(void) index;
	return (charrino-32);
}*/
/*
int main ()
{
	char *str = "qwertyuiop";
	char *mapato = ft_strmapi(str, funzione);

    printf("result: %s\n", mapato);
    free(mapato);
}
*/