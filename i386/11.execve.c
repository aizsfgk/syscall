#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
// #include <stdlib.h>
#include <sys/types.h>

/*
	int execve(const char *filename, char * const argv[], char *const envp[])
 */


int main(int argc, char const *argv[])
{
	char *newargv[] = { NULL, "hello", "world", NULL };
	char *newenvp[] = { NULL };

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	
	pid_t pid = getpid();
	fprintf(stdout, "pid: %d\n", pid);


	newargv[0] = (char *) argv[1];
	execve(argv[1], newargv, newenvp);
	perror("execve"); // return only on error
	exit(EXIT_FAILURE);

	return 0;
}