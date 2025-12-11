/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:40:06 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/03 12:41:07 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	size_t				i;
	unsigned char		*ptrd;
	const unsigned char	*ptrs;

	ptrd = (unsigned char *) dest_str;
	ptrs = (const unsigned char *) src_str;
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return ((void *)ptrd);
}
/*
int main()
{
	char *dest = "asdf";
	char *src = "qwertyuiop";
	int n = 5;
	int m = 3;
	ft_memcpy(dest,src,n);
	printf("%s",dest);
	
	char *dest1 = "asdf";
	char *src = "qwertyuiop";
}*/
