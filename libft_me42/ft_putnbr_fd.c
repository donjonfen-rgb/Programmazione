/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:18:20 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/06 15:59:38 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = (long) n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = ln * (-1);
	}
	if (ln > 9)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd((ln % 10) + '0', fd);
}
/* 
int main()
{
	int number = 5;
	int fd = open( "example.txt", O_WRONLY | O_CREAT | O_APPEND ,0644);
	if (fd == -1)
		printf("you made a mistake");
	else
	ft_putnbr_fd(number,fd);
} */
//ft_putstr_fd(ft_itoa(n), fd);???