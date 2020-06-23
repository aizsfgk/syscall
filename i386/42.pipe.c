#include "base.h"

// pipe, pipe2 - create pipe
// 单向的通道；双向会出问题

int main(int argc, char const *argv[])
{

	// 0 读
	// 1 写
	int pipefd[2];

	int ret = pipe(pipefd);
	if (ret == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid_t pid = fork();

	if (pid == 0) { // child
		close(pipefd[1]);
		char childBuf[100];
		read(pipefd[0], childBuf, 100);
		fprintf(stdout, "childBuf: %s\n", childBuf);

		snprintf(childBuf, 100, "hello-master, i am child, pid: %d, ppid: %d\n", getpid(), getppid());


	} else if (pid > 0) { // master
		close(pipefd[0]);

		char buf[100];
		snprintf(buf,100, "hello-child, i am master, pid: %d, child_pid: %d", getpid(), pid);
		write(pipefd[1], buf, strlen(buf));

		int status;
		pid_t child_pid = wait(&status);
		
		if (WIFEXITED(status)) {
			fprintf(stdout, "pid: %d\n", child_pid);
		}
			
		
		
		int flag = 1;
		while (flag < 10) {
			sleep(1);
			printf("master_flag: %d\n", flag);
			flag++;
		}
	} else {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return 0;
}