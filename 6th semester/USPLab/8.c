#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid1,pid2;
	if((pid1 = fork())<0)
	{
		perror("Fork error");
		_exit(0);
	}
	else if(pid1 == 0)
	{
		printf("\nParent process id : %d \nChild process id  : %d\n",getppid(),getpid());
		if((pid2=fork())<0)
		{
			perror("Fork error");
			_exit(0);
		}
		else if(pid2 == 0)
		{
			printf("\nChild process id : %d \nGrand child process id  : %d\n",getppid(),getpid());
			_exit(0);
		}
		else
		{
			sleep(2);
			_exit(0);
		}
	}
	else
	{
		waitpid(pid1,NULL,0);
		_exit(0);
	}
}
