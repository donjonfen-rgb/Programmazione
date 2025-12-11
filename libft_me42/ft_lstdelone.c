/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:25:41 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/08 22:16:17 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
/* void *del(void *node_content)
{
	free(node_content);
} */
/*	(*del)(lst->content); it's explicit that del is a 
function pointer, but they're equivalent*/
/* int main()
{
	t_list **list;
	t_list *newNode;
	newNode = malloc(sizeof(struct t_list));
	newNode->content = "qwertyuiop";
	newNode->next = head;
	head = newNode;
} */
/* 
int main()
{
	t_list *a = ft_lstnew("ciao");
	t_list *c = ft_lstnew("hello");
	t_list *b = ft_lstnew("world");
	ft_lstadd_front(&a, c);
	ft_lstadd_front(&c, b);
	ft_lstdelone(a,del(*c));
	printf("%s", (char *) b->next->content);
} */
