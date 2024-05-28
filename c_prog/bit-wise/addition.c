//adding 1 t0 given number with '+'

#include<stdio.h>

int main()

{
	int n;
	scanf("%d",&n);
	printf("%d  %d\n",(~n),!n);
	n=-(~n);
	printf("%d\n",n);

}
