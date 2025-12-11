/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:58:49 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/06 16:20:38 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*copy;
	int		slen;
	int		i;

	i = 0;
	if (!string)
		return (NULL);
	slen = ft_strlen(string);
	copy = (char *) malloc((slen + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (string[i])
	{
		copy[i] = string[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
