#include<stdio.h>

int main()
{
	int n,p;
	printf("enter number and position:");
	scanf("%d %d",&n,&p);
	n=n ^ (1<<p);
	printf("%d\n",n);
	return 0;

}
