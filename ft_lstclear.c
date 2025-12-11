/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:47:04 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/08 22:15:45 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tempme;

	tempme = *lst;
	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		tempme = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tempme;
	}
	*lst = NULL;
}
/* void	del(void *content)
{
	free(content);
} */
/*	if (lst && del) tutto qui dentro oppure ^
ft_lstdelone(*lst, del);no need for the free(lst)
valgrind --leak-check=full ./a.out
*/
