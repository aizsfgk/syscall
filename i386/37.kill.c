#include "base.h"


#include <sys/types.h>
#include <signal.h>

/*
If pid is positive, then signal sig is sent to the process with the ID specified by pid.

If pid equals 0, then sig is sent to every process in the process group of the calling process.

If  pid equals -1, then sig is sent to every process for which the calling process has permission
to send signals, except for process 1 (init), but see below.

If pid is less than -1, then sig is sent to every process in the process group whose ID is  -pid.

If  sig  is 0, then no signal is sent, but error checking is still performed; this can be used to
check for the existence of a process ID or process group ID.
 */

void signal_handler(int signum) {
	if (signum < 0) {
		fprintf(stderr, "signum err\n");
		return;
	}

	if (signum == SIGHUP) {
		fprintf(stdout, "i am SIGHUP, %d\n", SIGHUP);
	}

	if (signum == SIGTERM) {
		fprintf(stdout, "i am SIGTERM, %d\n", SIGTERM);
	}
}
int main(int argc, char const *argv[])
{
	signal(SIGHUP, signal_handler);
	signal(SIGTERM, signal_handler);

	int rt = kill(getpid(), SIGHUP);
	if (rt == 0) {
		pause();
	} else {
		perror("kill");
		exit(EXIT_FAILURE);
	}
	return 0;
}