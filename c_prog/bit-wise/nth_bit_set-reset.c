#include<stdio.h>

int main()
{

	int n,p;
	printf("enter number and position:");
	scanf("%d %d",&n,&p);
	if(n&(1<<p))
		printf("bit is set");
	else
		printf("bit is reset");

}
