#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/wait.h> // WEXITSTATUS

/*
fork
 1. inherits copies of the parent’s set of open file descriptors
 2. copies of the parent’s set of open message queue descriptors
 3. inherits copies of the parent’s  set  of  open  directory  streams

*/

int main(int argc, char const *argv[])
{
	int fd = open("./file.txt", O_CREAT|O_APPEND, S_IRWXU);
	int status;

	pid_t pid = fork();
	pid_t status_pid;

	if (pid == 0) {
		fprintf(stdout, "i am child process,  pid:%d,  ppid: %d, fd: %d\n", getpid(), getppid(), fd);
		exit(55);
	} else if (pid > 0 ) {
		fprintf(stdout, "i am parent process, pid:%d, child pid: %d, fd: %d\n", getpid(), pid, fd);

		status_pid = wait(&status);
		if (status_pid > 0 ) {
			// WEXITSTATUS 收集返回的状态
			fprintf(stdout, "status_pid: %d, status: %d\n", status_pid, WEXITSTATUS(status));
		} else {
			fprintf(stderr, "%s\n", "status_pid ret err");
		}
		
	} else {
		fprintf(stderr, "%s\n", "fork err" );
	}

	close(fd);
	return 0;
}