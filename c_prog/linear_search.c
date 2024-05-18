#include<stdio.h>
#include<stdlib.h>


int linear_search(int arr[],int n,int s)
{
int i=0;
while(i<n )
{
	if(arr[i]==s)
		return i;
	i++;
}
return -1;
}

int main()

{
	int s,n,i;
	printf("enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
	printf("enter the search element:");
	scanf("%d",&s);
	int r=linear_search(arr,n,s);
	printf("%d\n",r);
	
}

