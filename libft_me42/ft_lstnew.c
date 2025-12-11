/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:47:57 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/08 22:17:59 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(struct s_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*void inserisci_in_testa(struct Nodo** testa, int nuovo_dato) {
    struct Nodo* nuovo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuovo_nodo->dato = nuovo_dato;
    nuovo_nodo->prossimo = *testa;
    *testa = nuovo_nodo;
}*/