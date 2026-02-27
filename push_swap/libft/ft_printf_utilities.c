/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:29:41 by ggaritta          #+#    #+#             */
/*   Updated: 2026/01/31 13:14:17 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putmychar(char c, int *cptr)
{
	write(1, &c, 1);
	(*cptr)++;
}

void	ft_putmystr(char *str, int *cptr)
{
	if (!str)
	{
		*cptr += write (1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		ft_putmychar(*str, cptr);
		str++;
	}
}

void	ft_putmynmbrs(long num, int *cptr)
{
	if (num < 0)
	{
		ft_putmychar('-', cptr);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putmynmbrs((long)num / 10, cptr);
		ft_putmychar((num % 10) + '0', cptr);
	}
	else
		ft_putmychar(num + '0', cptr);
}

void	ft_print_hex(unsigned long n, const char *base, int *cptr)
{
	if (n >= 16)
		ft_print_hex(n / 16, base, cptr);
	ft_putmychar(base[n % 16], cptr);
}

void	ft_putmypointer(void *ptr, int *cptr)
{
	if (!ptr)
	{
		*cptr += write(1, "(nil)", 5);
		return ;
	}
	*cptr += write(1, "0x", 2);
	ft_print_hex((unsigned long)ptr, LBASE, cptr);
}
