#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i;
	float k=0,n;
	printf("Enter the number\n"); // taking the number from the user
	scanf("%f",&n);
	if(n==1) //special case of (1*1=1)
	{
		printf("The square root is 1\n");
		exit(0);
	}
	if(n==0) // special case of (0*0=0)
	{
		printf("The square root is 0\n");
		exit(0);
	}
	for(i=0;i<n;i++
	{
		if(i*i > n)
		{
			break;
		}
	}
	i--;
	k=i;  
	while(k<=i+1) {
		if(k*k <= n && (k+0.001)*(k+0.001)>=n) 
		{
			printf("The root is %f\n",k);
			exit(0);
		}
		else
		{
			k=k+0.001;
		}
	}
}
