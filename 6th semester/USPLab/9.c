#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void usersystem(char command[])
{
	pid_t pid;
	if((pid=fork())<0)
	{
		perror("Fork");
		_exit(0);
	}
	else if(pid == 0)
	{
		execl("/bin/sh","sh","-c",command,NULL);
		_exit(0);
	}
}
int main()
{
	char command[100];
	while(1)
	{
		printf(">>");
		gets(command);
		usersystem(command);
		printf("\n");
	}
	return 0;
}
