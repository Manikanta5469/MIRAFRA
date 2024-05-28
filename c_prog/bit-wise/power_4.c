#include<stdio.h>

int main()

{
	int n,c=0,k;
	printf("enter the number:");
	scanf("%d",&n);
	if(n&(~(0x1)))
	{
	
	for(int i=0;i<sizeof(n)*8;i++)
	{
		if(n&(1<<i))
		{
			k=i;
			c++;

		}
	}

	if(c==1 & (~(k&0x1)))
		printf("power of 4\n");
	else
		printf("NOT\n");
	}
	else
		printf("NOT\n");
}

