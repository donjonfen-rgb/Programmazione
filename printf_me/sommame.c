#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int count, ...)
{
	va_list argoms;
	va_start(argoms,count);
	int i = 0;
	int s = 0;

	while(i<count)
	{
		int x = va_arg(argoms,int);
		s += x;
		i++;
	}
	va_end(argoms);
	return s;
}

int sum2(int a, ...) //discover not defining the number of elements or 
//discover creating a macro that calls sum2 for us
//this accept: instead of passing the number of parameters it gets the null at the end
{
	va_list args;
	va_start(args, a);
	int s = a;
	int i;
	int x = va_arg(args, int);// we're going to force getting an argument
	
	while(x != NULL) {//because we know we have one at the end
		s += x;
		x = va_arg(args, int); //then we read it again
	}
	va_end(args);
	return s;
}

int main()
{
	printf("la somma e': %d\n", sum(4,11,11,10,10));
	printf("la somma e': %d\n", sum2(4,11,11,10,10,NULL));
	return 0;
}