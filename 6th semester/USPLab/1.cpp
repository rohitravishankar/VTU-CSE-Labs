#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
	cout<<"\nMaximum number of clock ticks : "<<sysconf(_SC_CLK_TCK)<<endl;
	cout<<"\nMaximum number of childern : "<<sysconf(_POSIX_CHILD_MAX)<<endl;
	cout<<"\nMaximum path length : "<<pathconf("/",_PC_PATH_MAX)<<endl;
	cout<<"\nMaximum number of number of characters in a filename : "<<pathconf("/",_PC_NAME_MAX)<<endl;
	cout<<"\nMaximum number of open files : "<<sysconf(_SC_OPEN_MAX)<<endl;
	
	return 0;
}
	
