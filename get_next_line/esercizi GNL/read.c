#include <stdio.h>

int main(void)
{
	FILE *fh;

	fh = fopen("t.txt","r");

	if (fh != NULL)
	{
		char c;
		while ((c = fgetc(fh)) != EOF)
			putchar(c);
		fclose(fh);
	} else printf("Error opening file.\n");
	return (0);
}