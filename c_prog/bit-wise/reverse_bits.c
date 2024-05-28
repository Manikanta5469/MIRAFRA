#include<stdio.h>
int main()
{
	int n;
	scanf("%x",&n);
	for(int i=0,j=31;i<j;i++,j--)
	{
		if(!((n&(1<<i)))!=(!(n&(1<<j))))
		{
		n=(n^(1<<i));
		n=(n^(1<<j));
		}
	
	}
	printf("%x\n",n);	
}
