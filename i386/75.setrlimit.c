#include "base.h"

#include <sys/time.h>
#include <sys/resource.h>

// getrlimit, setrlimit - get/set resource limits
// 
// #include <sys/time.h>
// #include <sys/resource.h>
// 
// int getrlimit(int resource, struct rlimit *rlim);
// int setrlimit(int resource, const struct rlimit *rlim);
// 
// resource: 
// RLIMIT_AS : 进程最大虚拟内存
// RLIMIT_CORE
// RLIMIT_CPU
// RLIMIT_DATA
// RLIMIT_FSIZE
// RLIMIT_LOCKS
// RLIMIT_MEMLOCK
// RLIMIT_MSGQUEUE
// RLIMIT_NICE
// RLIMIT_NOFILE
// RLIMIT_NPROC
// RLIMIT_RSS
// RLIMIT_RTPRIO
// 
// 

int main(int argc, char const *argv[])
{
	struct rlimit rli;
	int rt = getrlimit(RLIMIT_CORE, &rli);

	if (rt == 0) {
		fprintf(stdout, "rli.rlim_cur: %ld\n", (long)rli.rlim_cur);
		fprintf(stdout, "rli.rlim_max: %ld\n", (long)rli.rlim_max);
	}
	return 0;
}