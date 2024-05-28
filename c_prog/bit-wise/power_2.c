#include<stdio.h>

int main()

{
	int i,n,c=0;
	printf("enter the number:");
	scanf("%d",&n);
/*	for(i=0;i<sizeof(n)*8;i++)
	{
	if(n&(1<<i))
		c++;

	}
	if(c==1)
		printf("Power of 2\n");
	else
		printf("NOT\n");*/
	if(n&(n-1))
		printf("NOT\n");
	else
		printf("power of 2\n");

}



