/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:57:38 by ggaritta          #+#    #+#             */
/*   Updated: 2025/12/09 10:39:49 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	rex;
	int	sign;

	sign = 1;
	rex = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == '-' && sign > 0)
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		rex = rex * 10 + (str[i] - '0');
		i++;
	}
	return (rex * sign);
}
/* 
int main ()
{
	char *num = "++1";
	int ptr;

	ptr = ft_atoi(num);
	printf("%d\n",ptr);
} */
