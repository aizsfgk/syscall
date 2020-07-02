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
// RLIMIT_AS : 进程最大虚拟内存
// 

int main(int argc, char const *argv[])
{
	struct rlimit rli;
	// source
	// 
	// 
	// 
	int rt = getrlimit(RLIMIT_CORE, &rli);

	if (rt == 0) {
		fprintf(stdout, "rli.rlim_cur: %ld\n", (long)rli.rlim_cur);
		fprintf(stdout, "rli.rlim_max: %ld\n", (long)rli.rlim_max);
	}
	return 0;
}