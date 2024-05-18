#include<stdio.h>



int main()

{
	int s,n,j,i;
	printf("enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				s=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=s;
			}


		}
	}
	for(i=0;i<n;i++)
		printf(" %d \n",arr[i]);
}
