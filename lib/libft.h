/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:48:09 by ggaritta          #+#    #+#             */
/*   Updated: 2025/11/25 13:08:28 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t		ft_strlen(char *str);
void		*ft_memset(void *str, int ch, size_t n);
void			ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *d, const char *s, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int	ft_toupper(int ch);
int	ft_tolower(int ch);
char	*strchr(const char *str, int ch_needle);
char	*strrchr(const char *str, int ch_needle);
int	strncmp(const char *s1, const char *s2, size_t count);

#endif
