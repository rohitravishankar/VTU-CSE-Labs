#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
	#ifdef _POSIX_JOB_CONTROL
		printf("\nBSD Style Job Control supported : %d ",_POSIX_JOB_CONTROL);
	#else
		printf("\nBSD Style Job Control not supported");
	#endif

	#ifdef _POSIX_CHOWN_RESTRICTED
		printf("\nChanging ownership of files is restricted : %d ",_POSIX_CHOWN_RESTRICTED);
	#else
		printf("\nChanging ownership of files is not defined");
	#endif

	#ifdef _POSIX_SAVED_IDS
		printf("\nSaved IDs defined : %d ",_POSIX_SAVED_IDS);
	#else
		printf("\nSAved IDs not defined");
	#endif

	#ifdef _POSIX_PRIORITY_SCHEDLING
		printf("\nPriority scheduling enabled : %d ",_POSIX_PRIORITY_SCHEDULING);
	#else
		printf("\nPriority Scheduling not enabled");
	#endif
	return 0;
}
	