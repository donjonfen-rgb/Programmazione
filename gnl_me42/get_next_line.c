/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:40:10 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/09 18:36:47 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *ss)
{
	char	*ssn;
	int		i;

	i = 0;
	while (ss[i] && ss[i] != '\n')
		i++;
	i += (ss[i] == '\n');
	ssn = ft_subs(ss, i, ft_strleng(ss) - i);
	if (!ssn)
		return (NULL);
	free(ss);
	return (ssn);
}

char	*ft_row(char *ss)
{
	char	*row;
	int		i;

	i = 0;
	if (!ss || !ss[i])
		return (NULL);
	while (ss[i] && ss[i] != '\n')
		i++;
	row = ft_subs(ss, 0, i + (ss[i] == '\n'));
	if (!row)
		return (NULL);
	return (row);
}

char	*ft_reed(char *ss, int fd)
{
	char	*rl;
	ssize_t	redby;
	char	*swp;

	redby = 1;
	while (ft_strchr(ss, '\n') == -1 && redby > 0)
	{
		rl = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!rl)
			return (free(ss), NULL);
		redby = read(fd, rl, BUFFER_SIZE);
		if (redby == -1)
			return (free(rl), free(ss), NULL);
		swp = ft_join(ss, rl);
		if (!swp)
			return (NULL);
		ss = swp;
	}
	return (swp);
}

// char	*get_next_line(int fd)
// {
// 	static char	*ss;
// 	char	*rp;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	ss = ft_reed(ss, fd);
// 	if (!ss)
// 		return (NULL);
// 	rp = ft_row(ss);
// 	if (!rp && ss)
// 		return (free(ss),NULL);
// 	ss = ft_clean(ss);
// 	return (rp);
// }
char	*get_next_line_bonus(int fd)
{
	static char	*ss[1024];
	char		*rp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	ss[fd] = ft_reed(ss[fd], fd);
	if (!ss[fd])
		return (NULL);
	rp = ft_row(ss[fd]);
	if (!rp && ss[fd])
		return (free(ss[fd]), NULL);
	ss[fd] = ft_clean(ss[fd]);
	return (rp);
}
// int main()
// {
//     char* fileName = "paperogante.txt";
//     int fd = open(fileName, O_RDWR);
//     if(fd == -1){
//         printf("\nError Opening File!!\n");
//         exit(1);
//     }else{
//         printf("\nFile: [%s] opened sucessfully!\n", fileName);
//     }
/*	char buffer[1024];
    int bytesRead = read(fd, buffer, sizeof(buffer));
    printf("%d bytes read!\n", bytesRead);
    printf("File Contents: %s\n", buffer);*/
	// char *riga;
	// size_t i = 1;
	// do
	// {
	// 	riga = get_next_line(fd);
	// 	printf("%s",riga);
	// } while (riga != NULL);
	// while ((riga = get_next_line(fd)) != NULL)
	// {
	// 	printf("%zu - %s",i,riga);
	// 	i++;
	// }
	// printf("\n");
	// while ((riga = get_next_line_bonus(fd)) != NULL)
	// {
	// 	printf("%zu - %s",i,riga);
	// 	i++;
	// }
	// printf("\n");
	// return 0;
// }