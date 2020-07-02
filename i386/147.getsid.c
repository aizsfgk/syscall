#include "base.h"


int main(int argc, char const *argv[])
{

#define XOPEN_SORCE 500
	pid_t sid = getsid(getpid());
	if (sid == -1) {
		perror("getsid");
		exit(EXIT_FAILURE);
	} else {
		fprintf(stdout, "sid: %d, pid: %d\n", (int)sid, (int)getpid());
	}
	return 0;
}