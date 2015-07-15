#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[10],b[10],i=0,j,k,n;
	printf("Enter a number\n");
	scanf("%d",&n);
	k=n; //keeping a copy of the actual number just in case
	while(k!=0)
	{
		a[i]=k%10;
		k=k/10;
		i++;
	}
	for(j=0;j<i;j++)
	{
		b[j]=a[i-j-1]; 
	}
	for(j=0;j<i;j++)
	{
		if(a[j]!=b[j])
		{
			printf("Not a palindrome\n");
			exit(0);
		}
	}
	printf("It is a palindrome\n");
}
