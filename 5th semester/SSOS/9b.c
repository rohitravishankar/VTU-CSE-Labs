#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	char cmd[10];

	if((pid = fork()) < 0)
		printf("Error. Child process couldn't be created\n");

	if(pid == 0)
	{
		printf("I am the child process with ID - %d\n",getpid());
		printf("My parent process has the ID - %d\n",getppid());
	}
	else
	{
		printf("I am the parent process with ID - %d\n",getpid());
		printf("My child process has the ID - %d\n",pid);
	}
	wait();
	return 0;
}
