#include <stdarg.h>
#include <stdio.h>

int average(int n, ...)
{
	va_list ap; //argument pointer, it's pointing to the first argument, which is n
	int total;
	int i;
	va_start(ap,n);//we are skipping this argument in this case n, which is 
	total = 0;
	i = 0;					//used when working with the args or doing ops
	while (i<n){total+= va_arg(ap,int);i++;}
	return (total/n);
}
int main()
{
	int aver_age;
			//the first int that is being passed is a flag that will later use
			//based on the code we need to grab or do some ops on the args
	aver_age = average(5,24,36,115,54,80);
	printf("",aver_age);
}