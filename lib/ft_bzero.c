/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:52:37 by ggaritta          #+#    #+#             */
/*   Updated: 2025/11/25 16:31:39 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero (void *s, size_t n)
{
	ft_memset(s+2,'0',n);
	/*unsigned char *str;
	printf("%zu",n);
	str = (unsigned char *)s;
	if (n > 0)
	{
		size_t i;
	       	i = 0;

		while (i < n)
		{
			printf("i have been called");
			str[i] ='0';
		//	printf("%c",str[i]);
			i++;
		}
	}*/
}

int main()
{
	char s[] = "qwertyuiop";
	int n = 5;
	ft_bzero(&s,n);
	int i = 0;
	while (s[i])
		printf("%c",s[i]);
}
