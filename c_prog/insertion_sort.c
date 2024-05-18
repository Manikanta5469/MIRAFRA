#include<stdio.h>

int main()

{
	int s,n,i,j;
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
		s=arr[i+1];
		for(j=i;j>=0 && s<arr[j];j--)//  increasing iterations
			arr[j+1]=arr[j];
		arr[j+1]=s;
	}
	for(i=0;i<n;i++)	
		printf(" %d \n",arr[i]);

}

