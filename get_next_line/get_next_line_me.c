/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_me.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaritta <ggaritta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:14:18 by ggaritta          #+#    #+#             */
/*   Updated: 2026/02/02 14:23:49 by ggaritta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
GNL
leggere dati da un file e posizionarli nel buffer
MO del Buffer: attraverso un buff size acquisira' tot chars compreso
 il \n e altra roba dopo
il nostro obiettivo e' invece separare la chiamata e dunque
 il ritorno richiesto fino alla coincidenza del New Line.
I char residui, ovvero quelli che possono essere stati letti e
 dunque successivi alla richiesta del ritorno, dovranno essere conservati
 in una variabile od eseguire la funzione fino alla coincidenza 
*/
/*
start:
 creare una stringa lunga quanto la lettura(buffSIZE) +\n 
 (si ferma prima? puoi sempre aggiungerlo in una funzione dedicata che
 controlla in base al valore della lettura o della presenza di residui)
 leggere "int read(int fileDescriptor, void *buffer, size_t bytesToRead)"
 3rd param: instead of bytestoread we will feed IT the BUFFSIZE
 & acquisire 
 [Q: ma dove va salvata, devo stamparla?
 A: si, devi mandarla al main come ritorno #check]
 serve una statica che possa ricordarsi del residuo (serve veramente?)
 devo controllare il residuo dopo aver diviso...
 o a che mi serve il dup join ...aggiungere altre utils
 mi serve fare uno swap quando trovato \n tenere il punto e prendere il residuo
 cancellare il contenuto di buff e poi rimettere il res ma invece di scrivere la 
 volta successiva joinare(?). joinare sempre che fa?
 
end:
	ritornare una linea fino al punto e a capo
*/
/*ho bisogno di 
1)variabile che si carichi la lettura di buffsize, 
2)una pulita che venga consegnata al printf, 
3) uno swapper(?) che riaffidera il residuo a var1,
4)un numerico per i controlli o figlia dello strlen per il malloc/calloc?
*/
// 1. Process whatever is left in your static 'buf'
// 2. If 'buf' is empty, return NULL to end the loop
//chiamate in ordine per ultimo giro, 
//potrei mandare sbufferone e bona forse
// [if (read(fd, statico_bufferone, BUFFER_SIZE) == _EOFEFCSP_)
// 	free(statico_bufferone);]
//if everything is fine then: find,extract->copy into x2, reset,
// add back as if it was already from the second time
//teoricamente qui ci andrebbe -> segnalibro = 0;

char	*get_next_line(int fd)
{
	static char	*bufferone;
	char		*rigapronta;
	ssize_t		redby;
	size_t		segnalibro;

	printf("fd: [%d]\n",fd);
	rigapronta = NULL;
	bufferone = (char *) ft_callocami(BUFFER_SIZE + 1, sizeof(bufferone));
	if (!bufferone)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!(ft_strchrcami(bufferone)))
	{
		redby = read(fd, bufferone, BUFFER_SIZE);
		printf("buffsize %d, bytesred %zd\n",BUFFER_SIZE, redby);
		printf("bufferone: [%s]\n", bufferone);
	}
	if (redby < 0)
		return (free(bufferone),bufferone);
	else if (redby == 0 || redby < BUFFER_SIZE)
	{
		
		{printf("ultimo giro\n");
			return (rigapronta);
		}
	}
	segnalibro = ft_strchrcami(bufferone);
	printf("segnalibro:%zd",segnalibro);
	if(segnalibro)
	{
		rigapronta = ft_substringami(bufferone,0,segnalibro);
		//rigapronta = ft_callocami(segnalibro + 1, sizeof(char));
		// if (!rigapronta)
		// 	return (NULL);
		//printf("rigapronta[%s]\n",rigapronta);
		if (!rigapronta)
		{
			printf("rigapronta should be fore null [%s]\n",rigapronta);
			rigapronta = NULL;
			printf("rigapronta should be after null [%s]\n",rigapronta);
			free(rigapronta);
			return (rigapronta);
		}
		printf("rigapronta per davvero[%s]", rigapronta);
	}
	else
//stessa tiritera di sopra senno' sbufferone rimane allocato? valgrind cose...
		return (bufferone);
	return (rigapronta);
}

int main(){
    char *content;
    char* fileName = "esercizi GNL/paperogante.txt";
    int fd = open(fileName, O_RDWR);
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    	content = get_next_line(fd);
	    //int bytesRead = read(fd, buffer, sizeof(buffer));
    //printf("%d bytes read!\n", bytesRead);
    	printf("File Contents: \n---------------\n%s\n---------------\n", content);
	}
    return 0;
}
// int main (void)
// {
// 	char	*laion;
// 	int callingnumba = 0;
// 	//S_IROTH 3rd param mode_t mode others(anyone) can read this file
// 	int	filedescripteur = open("paperogante.txt",O_RDONLY);
// 	if (filedescripteur > -1)
// 	{
// 		//printf("printo prima %s",get_next_line(filedescripteur));
// 		while((laion = get_next_line(filedescripteur)) != NULL) //use read here? nope
// 		{
// 			callingnumba++;
// 			printf("WDIR: %s",laion);
// 			printf("Chiamata #%d terminata -------------------------------------------",
// 				callingnumba);
// 		}
// 	}
// 		else
// 			printf("file non accessibile\n");
// 	close(filedescripteur);
// }