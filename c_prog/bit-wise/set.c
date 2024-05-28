#include<stdio.h>

int main()

{
	
	int n,a;
	printf("enter the number:");
	scanf("%d",&a);
	printf("enter the position of the bit to set:");
	scanf("%d",&n);
	a=a |(1<<n);
	printf("%d\n",a);

}
