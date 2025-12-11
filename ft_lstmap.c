/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:07:03 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/09 09:45:31 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*listame;
	t_list	*new;

	if (!f || !del || !lst)
		return (NULL);
	listame = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			del(new->content);
			ft_lstclear(&listame, del);
			return (NULL);
		}
		ft_lstadd_back(&listame, new);
		lst = lst->next;
	}
	return (listame);
}
