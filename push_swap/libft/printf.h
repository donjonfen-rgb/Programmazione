/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:14:54 by ggaritta          #+#    #+#             */
/*   Updated: 2026/01/31 13:19:16 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define LBASE "0123456789abcdef"
# define UBASE "0123456789ABCDEF"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

void	ft_putmychar(char c, int *cptr);
void	ft_putmystr(char *str, int *cptr);
void	ft_putmynmbrs(long num, int *cptr);
void	ft_print_hex(unsigned long n, const char *base, int *cptr);
void	ft_putmypointer(void *ptr, int *cptr);
void	ima_switch(const char *str, va_list ap, int *cptr);
int		ft_printf(const char *str, ...);

#endif