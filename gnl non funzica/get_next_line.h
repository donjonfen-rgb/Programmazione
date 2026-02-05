/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:36:40 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/05 15:39:50 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/stat.h>

char	*get_next_line(int fd);
char	*ft_join (char *buffo, char *residuo);
size_t	ft_strchr(char *str, int c);
size_t	ft_strleng(char *lookintome);
char	*ft_subs(char *s, unsigned int start, size_t lungth);
void	*ft_calloc(size_t emmn, size_t ueit);
#endif