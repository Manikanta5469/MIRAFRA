#include<stdio.h>

int main()
{
	int x;
	scanf("%d",&x);
	x=( (x & 0x0F)<<4 | (x & 0xF0)>>4 );
	printf("%d",x);

}
