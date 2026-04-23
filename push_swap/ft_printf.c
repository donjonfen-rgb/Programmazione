/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:26:57 by ggaritta          #+#    #+#             */
/*   Updated: 2026/01/31 13:22:37 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ima_switch(const char *str, va_list ap, int *cptr)
{
	if (*str == 'c')
		ft_putmychar(va_arg(ap, int), cptr);
	else if (*str == 's')
		ft_putmystr(va_arg(ap, char *), cptr);
	else if (*str == 'p')
		ft_putmypointer(va_arg(ap, void *), cptr);
	else if (*str == 'd' || *str == 'i')
		ft_putmynmbrs((long) va_arg(ap, int), cptr);
	else if (*str == 'u')
		ft_putmynmbrs((long) va_arg(ap, unsigned int), cptr);
	else if (*str == 'x' || *str == 'X' )
	{
		if (*str == 'X')
			ft_print_hex((unsigned long) va_arg(ap, unsigned int), UBASE, cptr);
		else
			ft_print_hex((unsigned long) va_arg(ap, unsigned int), LBASE, cptr);
	}
	else if (*str == '%')
		ft_putmychar('%', cptr);
}

int	ft_printf(const char *str, ...)
{
	int		cptr;
	va_list	ap;

	if (!str)
		return (-1);
	va_start(ap, str);
	cptr = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ima_switch(str, ap, &cptr);
		}
		else
		{
			write(1, str, 1);
			cptr++;
		}
		str++;
	}
	va_end(ap);
	return (cptr);
}

// int main(void){
//     int a = 42;
//     char *s = "hello";
//     void *p = &a;
//     printf("REAL printf:\n");
//     int r1 = printf("c=%c s=%s d=%d u=%u x=%x X=%X p=%p %%\n",
//                     'A', s, -2147483647, -42u, 42, 42, p);   
// int r3 = printf(0);
//     printf("\nFT_printf:\n");
//     int r2 = ft_printf("c=%c s=%s d=%d u=%u x=%x X=%X p=%p %%\n",
//                        'A', s, -2147483647, -42u, 42, 42, p);
//     printf("\nReturn values:\n");
//     printf("printf  = %d\n", r1);
//     printf("ft_printf = %d\n", r2);

//     return 0;
// }

// int	main(void)
// {
// 	int	r1, r2;
// 	printf("--- TEST 1: Numeri Limite (INT_MIN / INT_MAX) ---\n");
// 	r1 = printf("Vero: %d %i\n", INT_MIN, INT_MAX);
// 	r2 = ft_printf("Mio:  %d %i\n", INT_MIN, INT_MAX);
// 	printf("Return: vero [%d] mio [%d]\n\n", r1, r2);
// 	printf("--- TEST 2: Unsigned e Zero ---\n");
// 	r1 = printf("Vero: %u %x %X\n", 0, 0, 0);
// 	r2 = ft_printf("Mio:  %u %x %X\n", 0, 0, 0);
// 	printf("Return: vero [%d] mio [%d]\n\n", r1, r2);
// 	printf("--- TEST 3: Puntatore NULL ---\n");
// 	r1 = printf("Vero: %p\n", NULL);
// 	r2 = ft_printf("Mio:  %p\n", NULL);
// 	printf("Return: vero [%d] mio [%d]\n\n", r1, r2);
// 	printf("--- TEST 4: Stringa NULL ---\n");
// 	r1 = printf("Vero: %s\n", (char *)NULL);
// 	r2 = ft_printf("Mio:  %s\n", (char *)NULL);
// 	printf("Return: vero [%d] mio [%d]\n\n", r1, r2);
// 	printf("--- TEST 5: Percentuali multiple ---\n");
// 	r1 = printf("Vero: %% %% %%%%\n");
// 	r2 = ft_printf("Mio:  %% %% %%%%\n");
// 	printf("Return: vero [%d] mio [%d]\n\n", r1, r2);
// 	printf("--- TEST 6: Mix e Unsigned Max ---\n");
// 	r1 = printf("Vero: %u %p %x\n", UINT_MAX, &r1, 424242);
// 	r2 = ft_printf("Mio:  %u %p %x\n", UINT_MAX, &r1, 424242);
// 	printf("Return: vero [%d] mio [%d]\n\n", r1, r2);
// 	return (0);
// }