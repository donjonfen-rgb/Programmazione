/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:40:10 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/04 17:25:25 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reed(char *ss, int fd)
{
	char	*rl;
	ssize_t	redby;

	while (ft_strchr(rl, '\n') != -1 || redby == 0)
	{
		rl = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!rl)
			return (NULL);
		redby = read(fd,rl,BUFFER_SIZE);
		if (redby == -1)
			return (free(rl), free(ss), NULL);
		rl[redby] = '\0';
		ss = ft_join(ss,rl);
		if (!ss)
			return (NULL);
		free(rl);
	}
	return(ss);
}
char	*ft_row(char *ss)
{
	char	*row;
	int		i;
	size_t	len;
	
	i = 0;
	if (!ss[i])
		return (NULL);
	while (ss[i] && ss[i] != '\n')
		i++;
	row = ft_calloc((i + 2), sizeof(char));
	if (!row)
		return (NULL);
	
	len = ft_strlen(ss);
	ft_subs(ss, i, len);
	if (ss[i] == '\n')
	{
		row[i] = '\n'; //diventata inutile dopo la correzzioni
		row[i + 1] = '\0';
	}
	return (row);
}

char	*get_next_line(int fd)
{
	static char	*ss;
	char	*rp;

	if (!(fd > 0 && BUFFER_SIZE > 0))
		return (NULL);
	ss = ft_reed(fd,ss);
	if (!ss)
		return (NULL);
	
	rp = ft_row(ss);
	
	return (rp);
}
	// rp deve acquisire la riga da consegnare (riga fino al nl)
	//acquisire FD
	//controlli fd e buffsize
	//allocare stratica dimensione BUFFER_SIZE 
		if buffsize is 1 and staticstr is BS+1 how do i reach nl?
	//controlla stratica
	//se buffsize is 1 what happens then
	leggere
	controllare byte letti
	se byteletti 
		< 0 errore
		= 0 controllare cosa rimasto nella statica
			mandare solo a substring e consegnare
		-> 0 eseguire standard
			deve andare bene da buffsize 1, quindi cicla lettura fino new line
			cercare nl > ottenere segnalibro
			substring fino a segnalibro
			segnalibro va bene anche a 1
			join di 0 e di row letta fino a nl
			+1 per statica prende residuo
			join di ns < ss + sl, sux swap
			caso di 1 verificato da condizione di ciclo
			
			
}
/*
*/