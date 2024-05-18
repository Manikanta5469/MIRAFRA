#include<stdio.h>
#include<stdlib.h>


int main()

{
	int s,n,i,k,j,t;
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
		k=i,s=arr[i];
		for(j=i+1;j<n;j++)
		{
			if(s>arr[j])
			{
				s=arr[j];//finding smallest element
				k=j;//storing it's index
			}

		}
		t=arr[i];
		arr[i]=s;
		arr[k]=t;
		

	}
	for(i=0;i<n;i++)
		printf("%d\n",arr[i]);

}
