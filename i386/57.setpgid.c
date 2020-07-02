#include "base.h"

// setpgid, getpgid, setpgrp, getpgrp - set/get process group


// 设置进程组id
int main(int argc, char const *argv[])
{
	int  rt = setpgid(getpid(), 0);
	if (rt == 0) {
		fprintf(stdout, "%s\n", "ok");
		pid_t pid = getpid();
		pid_t gpid = getpgrp();

		fprintf(stdout, "cur process gpid: %d, pid: %d\n", 
			(int)gpid, (int)pid);
	} else {
		perror("setpgid");
		// exit(EXIT_FAILURE);
	}


	pid_t gpid = getpgid(getpid());
	fprintf(stdout, "cur process gpid: %d\n", (int)gpid);
	return 0;
}