#include<stdio.h>

int main()
{
	int x;
	scanf("%d",&x);
	if(x&0x1)
		printf("ODD\n");
	else
		printf("EVEN\n");
	
}
