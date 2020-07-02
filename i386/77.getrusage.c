#include "base.h"

#include <sys/time.h>
#include <time.h>
 #include <sys/resource.h>

// getrusage - get resource usage
//
// #include <sys/time.h>   
// #include <sys/resource.h>
// 
// int getrusage(int who, struct rusage *usage);
//

// struct rusage {
//    struct timeval ru_utime; /* user time used */
//    struct timeval ru_stime; /* system time used */
//    long   ru_maxrss;        /* maximum resident set size */
//    long   ru_ixrss;         /* integral shared memory size */
//    long   ru_idrss;         /* integral unshared data size */
//    long   ru_isrss;         /* integral unshared stack size */
//    long   ru_minflt;        /* page reclaims */
//    long   ru_majflt;        /* page faults   */
//    long   ru_nswap;         /* swaps */
//    long   ru_inblock;       /* block input operations */
//    long   ru_oublock;       /* block output operations */
//    long   ru_msgsnd;        /* messages sent */
//    long   ru_msgrcv;        /* messages received */
//    long   ru_nsignals;      /* signals received */
//    long   ru_nvcsw;         /* voluntary context switches */
//    long   ru_nivcsw;        /* involuntary context switches */
// };


void rusagePrint(struct rusage *ru) {
	fprintf(stdout, "rusa->ru_maxrss: %ld\n", ru->ru_maxrss);
	fprintf(stdout, "rusa->ru_ixrss: %ld\n", ru->ru_ixrss);
	fprintf(stdout, "rusa->ru_idrss: %ld\n", ru->ru_idrss);
	fprintf(stdout, "rusa->ru_isrss: %ld\n", ru->ru_isrss);
	fprintf(stdout, "rusa->ru_minflt: %ld\n", ru->ru_minflt);
	fprintf(stdout, "rusa->ru_majflt: %ld\n", ru->ru_majflt);
	fprintf(stdout, "rusa->ru_nswap: %ld\n", ru->ru_nswap);
	fprintf(stdout, "rusa->ru_inblock: %ld\n", ru->ru_inblock);
	fprintf(stdout, "rusa->ru_oublock: %ld\n", ru->ru_oublock);
	fprintf(stdout, "rusa->ru_nsignals: %ld\n", ru->ru_nsignals);
	return;
}


int main(int argc, char const *argv[])
{

	struct rusage *rs;

	rs = malloc(sizeof(struct rusage));
	if (rs == NULL)
		exit(EXIT_FAILURE);
	int rt = getrusage(RUSAGE_SELF, rs);
	if (rt == 0) {
		rusagePrint(rs);
	} else {
		perror("getrusage");
		exit(EXIT_FAILURE);
	}
	free(rs);
	return 0;
}