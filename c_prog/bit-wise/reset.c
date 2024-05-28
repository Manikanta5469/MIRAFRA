#include<stdio.h>

int main()
{
	int n,p;
	printf("enter the number:");
	scanf("%d",&n);
	printf("enter the position of bit start's 0th to reset:");
	scanf("%d",&p);
	n=n & ~(1<<p);
	printf("%d\n",n);
}
