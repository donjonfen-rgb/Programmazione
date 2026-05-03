/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmeup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:00:00 by ggaritta          #+#    #+#             */
/*   Updated: 2026/05/03 23:13:34 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ── minimal line reader ────────────────────────────────────────────────── */

/*
 * Reads one '\n'-terminated line from fd.
 * Uses a static buffer so it survives across calls without gnl.
 * Returns a malloc'd string (newline stripped), or NULL on EOF / error.
 *
 * NOTE: only call with a single fd per program run (fine for stdin).
 */
static char	*ft_readline(int fd)
{
	static char	buf[4096];
	static int	buf_len = 0;
	static int	buf_pos = 0;
	char		*line;
	int			i;
	int			line_len;

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
	/*
	 * ft_helloitsmecalloc is your own calloc wrapper already in the project.
	 * If it doesn't exist yet, swap it for:  malloc((line_len + 1) * sizeof(char))
	 * followed by a ft_memset / manual zero-fill.
	 */
	line = ft_helloitsmecalloc(line_len + 1, sizeof(char), '\0');
	if (!line)
		return (NULL);
	{
		int	src;
		int	dst;

		src = buf_pos;
		dst = 0;
		while (src < i)
			line[dst++] = buf[src++];
		line[dst] = '\0';
	}
	buf_pos = i + 1;
	return (line);
}

/* ── ft_strcmp ──────────────────────────────────────────────────────────── */

/*
 * If you already have ft_strcmp / ft_strncmp in your libft / push_swap.h,
 * delete this block and just call yours.
 */
static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/* ── operation dispatcher ───────────────────────────────────────────────── */

/*
 * Calls the op functions already in ft_qops.c / ft_sorting_utilities.c.
 * Returns 1 for an unknown token so main can print "Error\n".
 */
static int	apply_op(t_stacks *s, char *op)
{
	if (!ft_strcmp(op, "sa"))
		sa(&s->a);
	else if (!ft_strcmp(op, "sb"))
		sb(&s->b);
	else if (!ft_strcmp(op, "ss"))
		ss(s);
	else if (!ft_strcmp(op, "pa"))
		pa(s);
	else if (!ft_strcmp(op, "pb"))
		pb(s);
	else if (!ft_strcmp(op, "ra"))
		ra(&s->a);
	else if (!ft_strcmp(op, "rb"))
		rb(&s->b);
	else if (!ft_strcmp(op, "rr"))
		rr(s);
	else if (!ft_strcmp(op, "rra"))
		rra(&s->a);
	else if (!ft_strcmp(op, "rrb"))
		rrb(&s->b);
	else if (!ft_strcmp(op, "rrr"))
		rrr(s);
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
	/*
	 * alltheknots() already handles:
	 *   - whitespace-separated numbers in a single arg
	 *   - multiple args  (e.g. checker 3 1 2)
	 *   - duplicate detection
	 *   - INT overflow
	 *   - sval ranking (ft_howMuchisPastrami)
	 */
	if (!alltheknots(s, ac, av))
		return (exit_error(s));
	if (s->a.size < 2)
	{
		decappler_two_point_o(s);
		return (0);
	}
	/* read operations from stdin and replay them on the stacks */
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
	/*
	 * check_if_sortdimamt()  → stack A ascending, no gaps
	 * qie()                  → stack B empty
	 */
	if (check_if_sortdimamt(s->a) && qie(s->b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	decappler_two_point_o(s);
	return (0);
}