/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_griddy_save_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:47:49 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/16 12:34:53 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void amajprevint(t_stacks *s, t_coord *xy)
{

}

void amajnextint(t_stacks *s, t_coord *xy)
{
	if (xy->ak->sval < xy->bk->sval && xy->adir == 'n' && xy->eorivl == 'i')
	{

	}
}

void amajprevext(t_stacks *s, t_coord *xy)
{

}

void amajnextext(t_stacks *s, t_coord *xy)
{

}

void aminprevint(t_stacks *s, t_coord *xy)
{
	if (xy->ak->sval < xy->bk->sval && xy->adir == 'p' && xy->eorivl == 'i')
	{//ak doesn't have to reach top but has to be tail -1rra and then pa
		if (xy->adir != xy->bdir)
		{
			reachprevbot(&s->a, xy->ak);
			reachnexttop(&s->b, xy->bk);
		}
		else
		{
			concord(s, xy);
		}
		pa(s);
	}
}

void aminnextint(t_stacks *s, t_coord *xy)
{

}

void aminprevext(t_stacks *s, t_coord *xy)
{

}

void aminnextext(t_stacks *s, t_coord *xy)
{

}

