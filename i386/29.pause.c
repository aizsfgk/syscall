#include <unistd.h>
#include <sys/signal.h>
#include <stdio.h>

#include <errno.h>
#include <string.h>


void sig_handler(int sigNum) {
	if (sigNum <= 0) {
		fprintf(stderr, "signal num err: %d\n", sigNum);
		return;
	}

	if (sigNum == SIGQUIT) {
		fprintf(stdout, "i am SIGQUIT: %d\n", sigNum);
	}
}

int main(int argc, char const *argv[])
{
	signal(SIGQUIT, sig_handler);

	int ret = pause();
	printf("ret: %d, errno: %d, error: %s\n", ret, errno, strerror(errno));

	// sleep(100);

	return 0;
}