#include "base.h"

int main(int argc, char const *argv[])
{
	
	pid_t pgrp = getpgrp();
	printf("pgrp: %ld\n", (long)pgrp);
	printf("pid: %ld\n", (long)getpid());
	printf("ppid: %ld\n", (long)getppid());

	return 0;
}