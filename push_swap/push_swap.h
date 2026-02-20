/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:45:06 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/20 18:37:28 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node	t_node;

struct s_node
{
	int		value;
	t_node	*next;
};

typedef struct s_queue
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_queue;

t_queue	createQ(void);

#endif
// ./pushwap numeri | ./checker  stessa lista numeri