/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:40:10 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/05 20:35:18 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reed(char *ss, int fd)
{
	char	*rl;
	ssize_t	redby;

	rl = NULL;
	while ((int) ft_strchr(rl, '\n') == -1 || redby != 0)
	{
		rl = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!rl)
			return (NULL);
		redby = read(fd,rl,BUFFER_SIZE);
		if (redby == -1)
			return (free(rl), free(ss), NULL);
		ss = ft_join(ss,rl);
		if (!ss)
			return (NULL);
		free(rl);
	}
	ft_row(ss);
	return(ss);
}

char	*ft_row(char *ss)
{
	char	*row;
	int		i;

	i = 0;
	if (!ss[i] || !ss)//superfluo? ridondante?
		return (NULL);
	while (ss[i] && ss[i] != '\n')
		i++;
	row = ft_calloc((i + 1 + (ss[i]=='\n')), sizeof(char));
	if (!row)
		return (NULL);
	row = ft_subs(ss, 0, i);
	ss = ft_subs(ss, ft_strleng(row), ft_strleng(ss) - ft_strleng(row));
	return (row);
}

char	*get_next_line(int fd)
{
	static char	*ss;
	char	*rp;

	if (!(fd > 0 && BUFFER_SIZE > 0))
		return (NULL);
	ss = ft_reed(ss, fd);
	if (!ss)
		return (NULL);
	rp = ft_row(ss);
	//residue
	return (rp);
}

int main(){
    char* fileName = "esercizi GNL/paperogante.txt";
    int fd = open(fileName, O_RDWR);
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }
    /*char buffer[1024];
    int bytesRead = read(fd, buffer, sizeof(buffer));
    printf("%d bytes read!\n", bytesRead);
    printf("File Contents: %s\n", buffer);*/
	char *riga;
	riga = get_next_line(fd);
	printf("%s",riga);
    return 0;
}