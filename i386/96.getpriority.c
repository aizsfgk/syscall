#include "base.h"
#include <sys/time.h>
#include <sys/resource.h>

// 获取进程优先级

int main(int argc, char const *argv[])
{
	
	int rs = setpriority(PRIO_PROCESS, getpid(), 10);
	if (rs  == -1) {
		perror("setpriority");
		exit(EXIT_FAILURE);
	}


	rs = getpriority(PRIO_PROCESS, getpid());
	fprintf(stdout, "rs: %d\n", rs);

	return 0;
}