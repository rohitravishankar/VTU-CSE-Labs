#include<stdio.h>
int rightrot(unsigned int x,unsigned int n)
{
	if (n == 0)
	{
		return x;
	}
	else
	{
		return ((x >> n) | (x << ( 32- n))); // will rotate "bit x" 'n times'
	}
}
void main ( )
{
	unsigned int ans,x,n;
	printf("Enter the data to be rotated\n"); 
	scanf("%d",&x);
	printf("Enter the number of times the data has to be roatated\n");
	scanf("%d",&n); 
	n=n%4; 
	ans=rightrot(x,n); 
	printf("The value after rotating the bit %d times is ",n);
	printf("%d\n",ans);
}
