/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:26:57 by ggaritta          #+#    #+#             */
/*   Updated: 2026/01/09 11:55:26 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
//#include <>
//tantovale mandare tutto a switcherone
/* char look_for_me(char str,char *anticameradelloswitcherone)
{
	while (str != *anticameradelloswitcherone)
		anticameradelloswitcherone++;
	if (anticameradelloswitcherone)
		return (*anticameradelloswitcherone);
	return (str);//dovra' ritornare null se non trova
} */

int ft_putmystr(char *str)
{
	int cont;
	
	if (!str)
		return (write(1,"(null)",6));
	cont = 0;
	while(*str++)
	{
		write(1,str,1);
		cont++;
	}
	return (cont);
}

int	ft_putmychar(char c)
{
	write(1,&c,1);
	return (1);
}

int	ft_putmynmbrs(va_list num)
{
	long	lnum;
	int		cont;

	lnum = num;
	
	return (cont);
}
int	ft_print_hex(unsigned long n, char *base)
{
	char	*base;
	int		cont;

	cont = 0;
	if (n >= 16)
		cont += ft_print_hex(n / 16,base);
	write(1, &base[n % 16], 1);
	cont++;
	return (cont);
}
int	ft_putmypointer(void *ptr)
{
	
	return (cont);
}

void ima_switch(char *str, va_list ap, int cont)
{
	char	*base;
	
	base = "0123456789ABCDEF";
	if (*str == 'c')
		cont += ft_putmychar(va_arg(ap,char));
	else if (*str == 's')
		cont += ft_putmystr(va_arg(ap,char *));
	else if (*str == 'p')
		cont += ft_putmypointer(va_arg(ap,char));//what is this format?
	else if (*str == 'd' || *str == 'i')
		cont += ft_putmynmbrs(va_arg(ap,int));
	else if (*str == 'u')
		cont += ft_putmyus(va_arg(ap,unsigned int));
	else if (*str == 'x' || *str == 'X' )
		{
			if (*str == 'x')
				base = "0123456789abcdef";
			cont += ft_print_hex((long)va_arg(ap, unsigned int), base);
		}//check me. (long) <-? va fatto il cast, perche serve?
	else if (*str == '%')
		cont += ft_putmychar('%');
	return -1;
}

int ft_printf(const char *str, ...)
{
	int	cont;
	//ciclare tutta la stringa in entrata per cercare % -> !stampo
	//se c'e' diventa la flag e cercare uno dei caratteri
	// % "cspdiuxX %"
	va_list ap;
	
	va_start(ap,str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			//cont += imaswitch(str,ap);
			ima_switch(str,ap,cont);
		}
		else
			write(1,str,1);
	}
	// look_for_me(str,set);
	va_end(ap);
	return (cont);
}

int main()
{
	char *str = "Caron, non ti crucciare: \nvuolsi così colà dove si puote ciò che si vuole, \ne più non dimandare";
	int fd = open( "example.txt", O_WRONLY | O_CREAT | O_APPEND ,0644);
	
	ft_printf("mia [%string%sa]\n",str,str);
	printf("vero [%stronzo]\n",str);
}