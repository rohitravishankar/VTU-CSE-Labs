#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#define INTERVAL 5
void callme(int signo)
{
	alarm(INTERVAL);
	printf("\nHello\n");
}
int main()
{
	struct sigaction action;
	action.sa_handler = (void (*) (int))callme;
	sigaction(SIGALRM,&action,0);
	alarm(2);
	sleep(5);
	return 0;
}

