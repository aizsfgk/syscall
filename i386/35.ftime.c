#include "base.h"
#include <sys/timeb.h> // ftime


// ftime - return date and time


int main(int argc, char const *argv[])
{
	printf("include base\n");

	/*
		struct timeb {
           time_t         time;
           unsigned short millitm;
           short          timezone;
           short          dstflag;
        };
	*/
	struct timeb tmb;
	int ret = ftime(&tmb);
	if (ret == 0) {
		printf("time: %ld, millitm: %d\n", (long)tmb.time, (int)tmb.millitm);
	} else {
		perror("ftime");
		exit(EXIT_FAILURE);
	}


	return 0;
}