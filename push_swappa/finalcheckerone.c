/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalcheckerone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:00:00 by ggaritta          #+#    #+#             */
/*   Updated: 2026/05/03 23:27:23 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Silent primitives from ft_moves.c (no write() inside).
** gnl + ft_strchr from your get_next_line files.
** ft_strcmp to be added to ft_libft.c (see companion snippet below).
*/
void	swp(t_queue *q);
void	push(t_queue *from, t_queue *to);
void	scroll_up(t_queue *q);
void	scroll_down(t_queue *q);
char	*get_next_line(int fd);
int		ft_strchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);

static int	apply_swaps(t_stacks *s, char *op)
{
	if (!ft_strcmp(op, "sa"))
		return (swp(&s->a), 0);
	if (!ft_strcmp(op, "sb"))
		return (swp(&s->b), 0);
	if (!ft_strcmp(op, "ss"))
		return (swp(&s->a), swp(&s->b), 0);
	return (1);
}

static int	apply_pushes(t_stacks *s, char *op)
{
	if (!ft_strcmp(op, "pa"))
		return (push(&s->b, &s->a), 0);
	if (!ft_strcmp(op, "pb"))
		return (push(&s->a, &s->b), 0);
	return (1);
}

static int	apply_rots(t_stacks *s, char *op)
{
	if (!ft_strcmp(op, "ra"))
		return (scroll_up(&s->a), 0);
	if (!ft_strcmp(op, "rb"))
		return (scroll_up(&s->b), 0);
	if (!ft_strcmp(op, "rr"))
		return (scroll_up(&s->a), scroll_up(&s->b), 0);
	if (!ft_strcmp(op, "rra"))
		return (scroll_down(&s->a), 0);
	if (!ft_strcmp(op, "rrb"))
		return (scroll_down(&s->b), 0);
	if (!ft_strcmp(op, "rrr"))
		return (scroll_down(&s->a), scroll_down(&s->b), 0);
	return (1);
}

static int	apply_op(t_stacks *s, char *op)
{
	if (!apply_swaps(s, op))
		return (0);
	if (!apply_pushes(s, op))
		return (0);
	if (!apply_rots(s, op))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	*s;
	char		*line;
	int			i;

	if (ac < 2)
		return (0);
	s = create_stacks();
	if (!s || !alltheknots(s, ac, av))
		return (exit_error(s));
	if (s->a.size < 2)
		return (decappler_two_point_o(s), 0);
	while ((line = get_next_line(0)) != NULL)
	{
		i = ft_strchr(line, '\n');
		if (i >= 0)
			line[i] = '\0';
		if (apply_op(s, line))
			return (free(line), write(2, "Error\n", 6),
				decappler_two_point_o(s), 1);
		free(line);
	}
	if (check_if_sortdimamt(s->a) && qie(s->b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (decappler_two_point_o(s), 0);
}
