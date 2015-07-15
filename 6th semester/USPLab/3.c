#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char **argv)
{
	int fd;
	char buffer[200];
	if(argc != 2)
	{
		perror("\nInsufficient arguments");
		exit(1);
	}
	fd = open(argv[1],O_RDWR);
	struct flock f;
	f.l_type = F_WRLCK;
	f.l_start = SEEK_END-100;
	f.l_whence = SEEK_END;
	f.l_len = 100;
	printf("\nPress enter to lock : ");
	getchar();
	if(fcntl(fd,F_SETLK,&f)==-1)
	{
		fcntl(fd,F_GETLK,&f);
		printf("\nThe region has been locked by process with pid = %d\n",f.l_pid);
		
		return -1;
	}
	printf("\nLocked");
	if(lseek(fd,SEEK_END-50,SEEK_END)==-1)
	{
		perror("\nlseek");
		exit(1);
	}
	if(read(fd,buffer,50)==-1)
	{
		perror("\nread");
		exit(1);
	}
	printf("\nData read from file.Contets of buffer :\n");
	puts(buffer);
	printf("\n\n");
	printf("\nPress enter to unlock : ");
	getchar();
	f.l_type = F_UNLCK;
	f.l_start = 0;
	f.l_whence = SEEK_SET;
	f.l_len = 0;
	if(fcntl(fd,F_UNLCK,&f)==-1)
	{
		perror("fcntl");
		exit(0);
	}
	printf("\nUnlocked\n");
	close(fd);

	return 0;
}
	
