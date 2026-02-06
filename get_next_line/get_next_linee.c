/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linee.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:42:18 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/05 18:33:53 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*ft_functionami(char *buf, ssize_t redby)
{
	char	*rigapronta;
	size_t	segnalibro;

	while (!ft_strchrcami(buf) || redby == 0)
	{
		if (redby < 0)
		{
			segnalibro = ft_strchrcami(buf);
			rigapronta = ft_substringami(buf,0,segnalibro);
		}
	}
	return (rigapronta);
}

char	*get_next_line(int fd)
{
	static char *bufferone;
	char		*rigapronta;
	ssize_t		redby;

	bufferone = (char *) ft_callocami(BUFFER_SIZE + 1, sizeof(char));
	if (!bufferone)
		return (NULL);
	if (!(fd > 0 && BUFFER_SIZE > 0))
		return (NULL);
	redby = read(fd,bufferone,BUFFER_SIZE);
	while (!ft_strchrcami(bufferone) || redby == 0)
	{
		if (redby < 0)
		{
			if (!bufferone || (bufferone[0] == '\0'))
				return (ft_functionamilast(bufferone));
			rigapronta = ft_functionami(bufferone);
			return (free(bufferone), bufferone);
		}
		rigapronta = ft_functionami(bufferone,redby);
		redby = read(fd,bufferone,BUFFER_SIZE);
	}
	return (rigapronta);
}
/*01000011 01101111 01101110 01100111 01110010 01100001 01110100 01110101 01101100 01100001 01111010 01101001 01101111 01101110 01101001 00100001 00100000 01000011 01101100 01100001 01110000*/
int main(){
    char *content;
    char* fileName = "esercizi GNL/paperogante.txt";
    int fd = open(fileName, O_RDWR);
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }else{
        printf("\nFile %s opened sucessfully!\n", fileName);
		while(get_next_line(fd))
    		content = get_next_line(fd);
	    //int bytesRead = read(fd, buffer, sizeof(buffer));
    //printf("%d bytes read!\n", bytesRead);
    	printf("File Contents: \n---------------\n%s\n---------------\n", content);
		free(content);
	}
    return 0;
}
/*
char	*ft_read_memory(int fd, char *memory)
{
	char	*buffer;
	int		byte_read;
	char	*temp;

	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (ft_strchr(memory, '\n') == NULL && byte_read != 0)
	{
		byte_read = read (fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (buffer);
			free (memory);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		temp = ft_strjoin(memory, buffer);
		free (memory);
		memory = temp;
	}
	free (buffer);
	return (memory);
}

char	*ft_get_line(char *memory)
{
	size_t	x;
	char	*line;

	if (!memory || memory[0] == '\0')
		return (NULL);
	x = 0;
	while (memory[x] != '\n' && memory[x])
		x++;i = 0;
	line = malloc (sizeof(char) * (x + 1 + (memory[x] == '\n')));
	if (!line)
		return (NULL);
	x = 0;
	while (memory[x])
	{
		line[x] = memory[x];
		if (line[x] == '\n')
		{
			x++;
			break ;
		}
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_new_memory(char *memory)
{
	size_t	x;
	size_t	y;
	char	*temp;

	x = 0;
	while (memory[x] != '\n' && memory[x])
		x++;
	if (memory[x] == '\0')
	{
		free (memory);
		return (NULL);
	}
	temp = malloc ((ft_strlen(memory) - x) * sizeof(char));
	if (!temp)
	{
		free (memory);
		return (NULL);
	}
	y = 0;
	x++;
	while (memory[x])
		temp[y++] = memory[x++];
	temp[y] = '\0';
	free (memory);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = ft_read_memory(fd, memory);
	if (!memory)
		return (NULL);
	line = ft_get_line(memory);
	memory = ft_new_memory(memory);
	return (line);
}

---------------------------------------------------------
#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *ss)
{
	char	*row;
	int		i;

	i = 0;
	if (!ss[i])
		return (NULL);
	while (ss[i] && s[i] != '\n')
		i++;
	row = ft_calloc((i + 2) * sizeof(char));
	if (!row)
		return (NULL);

	if (ss[i] == '\n')
	{
		row[i] = '\n'; diventata inutile dopo la correzzioni
		row[i + 1] = '\0';
	}
	return (row);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("TCC.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

*/