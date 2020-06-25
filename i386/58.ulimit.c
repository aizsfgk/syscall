#include "base.h"
#include <ulimit.h>

// ulimit - get and set user limits
// 
// Warning:  This routine is obsolete. 
// Use getrlimit(2), setrlimit(2), and sysconf(3) instead.
// 

#include <sys/time.h>
#include <sys/resource.h>


int main(int argc, char const *argv[])
{
	long rt = ulimit(UL_GETFSIZE,111); // 被废弃了
	printf("rt：%d\n", rt);

	struct rlimit rl;

	int rt2 = getrlimit(RLIMIT_NOFILE, &rl);
	if (rt2 == 0) {
		fprintf(stdout, "cur: %d, max: %d\n", rl.rlim_cur, rl.rlim_max);
	} else {
		perror("getrlimit");
	}
	return 0;
}