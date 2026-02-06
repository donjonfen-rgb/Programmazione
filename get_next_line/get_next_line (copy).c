/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line (copy).c                             :+:      :+:    :+:   */
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
char	*get_next_line(int fd)
{
	char	*bufferone;
	char	*rigapronta;
	ssize_t redby;
	int	segnalibro;
	
	rigapronta = NULL;
	if (!(fd > 0 && BUFFER_SIZE > 0))
		return (NULL);
	redby = read(fd, bufferone, BUFFER_SIZE);
	printf("%s", bufferone);
	printf("buffami %d, bytesred %zd\n",BUFFER_SIZE, redby);
	if (redby < 0)
	{
		bufferone = NULL;
		free(bufferone);
		return (bufferone);
	}
	else if (redby == 0)
	{
// 1. Process whatever is left in your static 'buf'
// 2. If 'buf' is empty, return NULL to end the loop
		if (!bufferone && (bufferone[0] == '\0'))
		{
//chiamate in ordine per ultimo giro, 
//potrei mandare sbufferone e bona forse
			return (rigapronta);
		}
	}
// [if (read(fd, statico_bufferone, BUFFER_SIZE) == _EOFEFCSP_)
// 	free(statico_bufferone);]
//if everything is fine then: find,extract->copy into x2, reset,
// add back as if it was already from the second time
//teoricamente qui ci andrebbe -> segnalibro = 0;
	segnalibro = ft_strchrcami(bufferone);
	if(segnalibro)
	{
		rigapronta = ft_callocami(
			segnalibro + 1, sizeof(char));
		if (!rigapronta)
			{
				rigapronta = NULL;
				free(rigapronta);
				return (rigapronta);
			}
		
		rigapronta = ft_substringami(bufferone,
			ft_strlengmi(bufferone),segnalibro);
		printf("%s", rigapronta);
	}
	else
//stessa tiritera di sopra senno' sbufferone rimane allocato? valgrind cose...
	
		return (bufferone);
	return (rigapronta);
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

int main(){
    char* fileName = "esercizi GNL/paperogante.txt";
    int fd = open(fileName, O_RDWR);
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }
    char buffer[1024];
    int bytesRead = read(fd, buffer, sizeof(buffer));
    printf("%d bytes read!\n", bytesRead);
    printf("File Contents: %s\n", buffer);
    return 0;
}