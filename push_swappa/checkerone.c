/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:00:00 by ggaritta          #+#    #+#             */
/*   Updated: 2026/05/03 23:22:14 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * WHY NOT USE sa/ra/pb/... DIRECTLY?
 *
 * Every op in ft_moves.c calls write(1, "xx\n", n) after executing.
 * Replaying ops through those functions would print the op names to stdout
 * alongside "OK"/"KO", corrupting the output.
 *
 * The silent primitives swp(), push(), scroll_up(), scroll_down() are already
 * defined in ft_moves.c and do the actual work without any write().
 * We call those instead.
 *
 * Declare them here so the compiler knows about them.
 */
void	swp(t_queue *q);
void	push(t_queue *from, t_queue *to);
void	scroll_up(t_queue *q);
void	scroll_down(t_queue *q);

/* ── minimal line reader ────────────────────────────────────────────────── */

static char	*ft_readline(int fd)
{
	static char	buf[4096];
	static int	buf_len = 0;
	static int	buf_pos = 0;
	char		*line;
	int			i;
	int			line_len;
	int			src;
	int			dst;

	i = buf_pos;
	line_len = 0;
	while (1)
	{
		if (buf_pos >= buf_len)
		{
			buf_len = (int)read(fd, buf, sizeof(buf));
			buf_pos = 0;
			i = 0;
			if (buf_len <= 0)
				return (NULL);
		}
		while (i < buf_len && buf[i] != '\n')
			i++;
		line_len += i - buf_pos;
		if (i < buf_len)
			break ;
		buf_pos = buf_len;
	}
	line = ft_helloitsmecalloc(line_len + 1, sizeof(char), '\0');
	if (!line)
		return (NULL);
	src = buf_pos;
	dst = 0;
	while (src < i)
		line[dst++] = buf[src++];
	line[dst] = '\0';
	buf_pos = i + 1;
	return (line);
}

/* ── ft_strcmp ──────────────────────────────────────────────────────────── */

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/* ── silent operation dispatcher ───────────────────────────────────────── */

/*
 * Calls the silent primitives from ft_moves.c.
 * No write() calls happen, so stdout stays clean for "OK\n" / "KO\n".
 */
static int	apply_op(t_stacks *s, char *op)
{
	if (!ft_strcmp(op, "sa"))
		swp(&s->a);
	else if (!ft_strcmp(op, "sb"))
		swp(&s->b);
	else if (!ft_strcmp(op, "ss"))
	{
		swp(&s->a);
		swp(&s->b);
	}
	else if (!ft_strcmp(op, "pa"))
		push(&s->b, &s->a);
	else if (!ft_strcmp(op, "pb"))
		push(&s->a, &s->b);
	else if (!ft_strcmp(op, "ra"))
		scroll_up(&s->a);
	else if (!ft_strcmp(op, "rb"))
		scroll_up(&s->b);
	else if (!ft_strcmp(op, "rr"))
	{
		scroll_up(&s->a);
		scroll_up(&s->b);
	}
	else if (!ft_strcmp(op, "rra"))
		scroll_down(&s->a);
	else if (!ft_strcmp(op, "rrb"))
		scroll_down(&s->b);
	else if (!ft_strcmp(op, "rrr"))
	{
		scroll_down(&s->a);
		scroll_down(&s->b);
	}
	else
		return (1);
	return (0);
}

/* ── main ───────────────────────────────────────────────────────────────── */

int	main(int ac, char **av)
{
	t_stacks	*s;
	char		*line;

	if (ac < 2)
		return (0);
	s = create_stacks();
	if (!s)
		return (1);
	if (!alltheknots(s, ac, av))
		return (exit_error(s));
	if (s->a.size < 2)
	{
		decappler_two_point_o(s);
		return (0);
	}
	while ((line = ft_readline(0)) != NULL)
	{
		if (apply_op(s, line))
		{
			free(line);
			write(2, "Error\n", 6);
			decappler_two_point_o(s);
			return (1);
		}
		free(line);
	}
	if (check_if_sortdimamt(s->a) && qie(s->b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	decappler_two_point_o(s);
	return (0);
}
