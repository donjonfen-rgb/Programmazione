/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 23:40:00 by ggaritta          #+#    #+#             */
/*   Updated: 2026/04/27 14:04:06 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	streka(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (a[i] == '\0' && b[i] == '\0');
}

static int	read_op(char op[5])
{
	char	c;
	int		r;
	int		i;

	i = 0;
	while ((r = read(0, &c, 1)) > 0)
	{
		if (c == '\n')
			return (op[i] = '\0', 1);
		if (i >= 4)
			return (-1);
		op[i++] = c;
	}
	if (r < 0)
		return (-1);
	if (i == 0)
		return (0);
	return (-1);
}

static int	apply_swap_push(t_stacks *s, const char *op)
{
	if (streka(op, "sa"))
		swp(&s->a);
	else if (streka(op, "sb"))
		swp(&s->b);
	else if (streka(op, "ss"))
	{
		swp(&s->a);
		swp(&s->b);
	}
	else if (streka(op, "pa"))
		push(&s->b, &s->a);
	else if (streka(op, "pb"))
		push(&s->a, &s->b);
	else
		return (0);
	return (1);
}

static int	apply_rot(t_stacks *s, const char *op)
{
	if (streka(op, "ra"))
		scroll_up(&s->a);
	else if (streka(op, "rb"))
		scroll_up(&s->b);
	else if (streka(op, "rr"))
	{
		scroll_up(&s->a);
		scroll_up(&s->b);
	}
	else
		return (0);
	return (1);
}

static int	apply_rrot(t_stacks *s, const char *op)
{
	if (streka(op, "rra"))
		scroll_down(&s->a);
	else if (streka(op, "rrb"))
		scroll_down(&s->b);
	else if (streka(op, "rrr"))
	{
		scroll_down(&s->a);
		scroll_down(&s->b);
	}
	else
		return (0);
	return (1);
}

static int	apply_op(t_stacks *s, const char *op)
{
	if (apply_swap_push(s, op))
		return (1);
	if (apply_rot(s, op))
		return (1);
	if (apply_rrot(s, op))
		return (1);
	return (0);
}

static int	has_invalid_raw_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0' || !ft_pastramiOrSalami(av[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	run_checker(t_stacks *s)
{
	char	op[5];
	int		status;

	while (1)
	{
		status = read_op(op);
		if (status == 0)
			break ;
		if (status < 0 || !apply_op(s, op))
		{
			ft_errors(0, 0);
			return (1);
		}
	}
	if (check_if_sortdimamt(s->a) && qie(s->b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	main(int ac, char **av)
{
	t_stacks	*s;
	int			ret;

	if (ac < 2)
		return (0);
	s = create_stacks();
	if (!s)
		return (1);
	if (has_invalid_raw_arg(ac, av) || !alltheknots(s, ac, av))
		return (exit_error(s));
	ft_howMuchisPastrami(&s->a);
	ret = run_checker(s);
	decappler_two_point_o(s);
	return (ret);
}
