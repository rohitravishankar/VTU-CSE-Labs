/*generation of fib series upto a given value*/
#include<stdio.h>
#include<omp.h>
int main()
{
	int v,a[100],i,j;
	omp_set_num_threads(2);
	
	printf("enter the value upto which the fibonacci series has to be generated\n");
	scanf("%d",&v);
	a[0]=0;
	a[1]=1;

	#pragma omp parallel
	{
			
		#pragma omp single
		for(i=2;;i++)
			{
				a[i]=a[i-2]+a[i-1];
				if(a[i]>v)
					break;
			printf("id of thread involved in  the computation of fib no.%d is =%d\n",i+1,omp_get_thread_num());
			}
		
		#pragma omp barrier
		#pragma omp single
		{
			printf("the elements of fib series are\n");
			for(j=0;j<i;j++)
				printf("%d, id of the thread dislpaying this no. is =%d\n",a[j],omp_get_thread_num());
			
		}
	
	}

}



	
