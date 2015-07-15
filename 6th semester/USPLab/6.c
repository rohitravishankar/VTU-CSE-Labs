#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
static void charatatime(char * str)
{
	int c;
	char *ptr;
	setbuf(stdout,NULL);
	for(ptr = str;c = *ptr++;)
		putc(c,stdout);
}
int main()
{
	pid_t pid;
	if((pid=fork())<0)
	{
		perror("Fork failed");
		_exit(0);
	}
	else if(pid ==0)
		charatatime("\nOutput from Child\n");
	else
		charatatime("\nOutput from Parent\n");
	_exit(0);
}

