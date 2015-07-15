#include<stdio.h>
#include<stdlib.h>
int fact(int n) // A recursive function 
{
	if(n==0 || n==1) 
	{
		return 1;
	}
	else
	{
		return (n*fact(n-1)); 
	}
}
void main()
{
	int n,r;
	float ncr;
	printf("Enter values of N and R also N>=R\n");
	scanf("%d%d",&n,&r);
	printf("The factorial of N is %d\n",fact(n));
	ncr=(fact(n)/(fact(n-r)*fact(r)));
	printf("The ncr value is %f\n",ncr);
}
