#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PIE 3.142 

void main()
{
	int i,d;
	float term,num,den,sum=0,x;
	printf("Enter the degree\n");
	scanf("%d",&d);
	x=d*(PIE/180); // converting degree to radian! 
	num=x; 
	den=1;
	i=2;
	do
	{
		term=num/den;
		num=-num*x*x;
		den=den*i*(i+1);
		sum=sum+term;
		i=i+2;
	}while(fabs(term)>=0.00001); //value correct to 4 decimal places
	printf("The sine series of %d is %f\n",d,sum); 
	printf("Sine function of %d is %f\n",d,sin(x)); 
}
// Don't forget "cc 5.c -lm" 