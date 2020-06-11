#include <stdio.h>
#include <unistd.h>

/*
	restart_syscall  - restart a system call after interruption by a stop signal
 */

int main(int argc, char const *argv[])
{
	long ret = restart_syscall();
	fprintf(stdout, "restart_syscall ret %ld\n", ret);
	return 0;
}
