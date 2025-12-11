/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:21:08 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/08 21:51:55 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*alloc;

	if (nitems != 0 && size >= __SIZE_MAX__ / nitems)
		return (NULL);
	alloc = malloc(nitems * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, nitems * size);
	return (alloc);
}
/* 
int main ()
{
	int *ptr;
	int i=0;  100/3
	int n=5;
	ptr = (int *) ft_calloc(n, sizeof(int));
	if(ptr == NULL) {
		printf("Error! memory not allocated.");
		//exit(0);
  	}
  	while (i!=n){printf("int[%d]\n",ptr[i]);i++;}
	
	char *chr;
	int num=5;
	int j=0;
	chr = (char *) ft_calloc(num, sizeof(char));
		if(chr == NULL) {
				printf("Error! memory not allocated.");
				exit(0);
		}
		while (j!=num){printf("char[%c]\n",chr[j]);j++;}

		int k=0;
		int *ptr1; 
		int ni=5;
		ptr1 = (int *) calloc(ni, sizeof(int));
		if(ptr1 == NULL) {
				printf("Error! memory not allocated.");
				//exit(0);
		}
		while (k!=ni){printf("int1[%d]\n",ptr1[k]);k++;}

	int l=0;
		char *chr1;
		int nam = 5;
		chr1 = (char *) calloc(nam, sizeof(char));
		if(chr1 == NULL) {
				printf("Error! memory not allocated.");
				exit(0);
		}
		while (l!=nam){printf("char1[%c]\n",chr1[l]);l++;}
} */