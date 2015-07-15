#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	int a[10],*p,i,n; 
	float sum=0,avg,std=0;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	p=a;
	for(i=0;i<n;i++)
	{
		sum=sum+*p;
		p++; 
	}
	avg=sum/n;
	p=a;
	for(i=0;i<n;i++)
	{
		std=std+pow((avg-*p),2); 
		p++;
	}
	std=sqrt(std/n); 
	printf("The sum %f mean %f and Standard deviations %f \n",sum,avg,std);
}
