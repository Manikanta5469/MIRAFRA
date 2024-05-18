#include<stdio.h>
#include<stdlib.h>

int binary_search(int arr[],int n,int s)
{
	int i=0,j=n-1,m;
	while(i<=j)
	{
	m=(i+j)/2;
	if(s>arr[m])
		i=m+1;
	else if(s<arr[m])
		j=m-1;
	else 
		return m;		

	}
	return -1;

}

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
	int t=0;
	/*
	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
		if(arr[i]>arr[j])	
		{
		t=arr[i];
		arr[i]=arr[j];
		arr[j]=t;
		}
	}
	}
	printf("after sorting\n");
	for(i=0;i<n;i++)
	{
	printf("%d ",arr[i]);
	}*/
	printf("enter the search element:");
	scanf("%d",&s);
	int r=binary_search(arr,n,s);
	printf("%d\n",r);
	
}

