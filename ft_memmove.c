/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:56:56 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/03 14:30:03 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_str, const void *src_str, size_t n)
{
	size_t					i;
	unsigned char			*ptrd;
	const unsigned char		*ptrs;

	ptrd = (unsigned char *) dest_str;
	ptrs = (unsigned char *) src_str;
	if (ptrd == NULL && ptrs == NULL)
		return (ptrd);
	if (ptrd > ptrs)
	{
		while (n--)
			*(ptrd + n) = *(ptrs + n);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	return (ptrd);
}
/* 
int main ()
{
	char ptr[] = "qwertyuiop";
	
	ft_memmove(ptr,ptr,8);
	printf("%s",ptr);
} */
	//char *stmp1 = ft_memmove(ptr+1,ptr+5,3);
	//int i=0;while(stmp[i]){printf("[%c]\n",stmp[i]);i++;}
//int j=0;while(stmp1[j]){printf("[%c]\n",stmp1[j]);j++;}
//}

/*void *ft_memmove(void *dest_str, const void *src_str, size_t n)
{
	unsigned char *ptrd;
	const unsigned char *ptrs;
	size_t i;
	
	ptrd = (unsigned char *) dest_str;
	ptrs = (const unsigned char *) src_str;
	
	if (ptrd > ptrs)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ptrd[i] = ptrs[i];

		}
	}
	else
	{
		i = 0;	
		while(i < n)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	return ((void *)ptrd);
}*/
