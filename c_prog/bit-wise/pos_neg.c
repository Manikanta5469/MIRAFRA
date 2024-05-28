#include<stdio.h>

int main()
{
	int n;
	scanf("%x",&n);
	if(n&(1<<31))
		printf("negative");
	else
		printf("positive");


}
