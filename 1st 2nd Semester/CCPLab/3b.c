#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n;
	printf("Enter the year!\n");
	scanf("%d",&n);
	if(n%4==0) 
	{
		printf("It's is a leap year!\n");
	}
	else
	{
		printf("It's is not a leap year!\n");
	}
}
