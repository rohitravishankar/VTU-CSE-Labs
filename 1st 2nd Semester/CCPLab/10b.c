#include<stdio.h>
int prime(int n)
{
	int i;
	for(i=2;i<=n/2;i++) 
	{
		if(n%i==0) 
		{
			return 0;
		}
	} 
	return 1;
}
void main()
{
	int num,flag;
	printf("enter the number\n");
	scanf("%d",&num);
	flag=prime(num);
	if(flag==1)
	{	
		printf("The given number is prime\n");
	}
	else
	{
		printf("The given number is not prime\n");
	}
}
