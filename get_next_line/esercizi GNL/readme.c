#include <stdio.h>

int main (void)
{
	//a buffer is a container an array of chars 
	//to hold one line of our doc one line at a time
	char buffer[255];
	unsigned int cont = 0;

	FILE *pF = fopen("leggimeinvece","r");
	
	if (pF == NULL)
	{
		printf("Unable to open il file-ino.\n");
	}
	else
	{
	//to read a single line we use gets, 
	//params(what it takes, max input size(we can match the two), and the pointer 
	//to the file the file descriptor or pointer to the file
	//(it's the same))
	fgets(buffer, 255,pF);
	printf("prima chiamata[%s]\n",buffer);
		while (fgets(buffer,255,pF) != NULL)
		{
			printf("[%s]",buffer);
			//cont++;
			printf("chiamata numero:%u",++cont);
		}
	}
	fclose(pF);//do not reference it
	return (0);
}