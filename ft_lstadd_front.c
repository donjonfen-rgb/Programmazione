/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:14:15 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/08 22:18:24 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
/* 
int main()
{
	t_list *a = ft_lstnew("ciao");
	t_list *c = ft_lstnew("hello");
	t_list *b = ft_lstnew("world");
	ft_lstadd_front(&a, c);
	ft_lstadd_front(&c, b);
	printf("%s", (char *) b->next->content);
} */
/*(!*lst)removed line*/