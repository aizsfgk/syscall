#include "base.h"

#include <sys/time.h>

int main(int argc, char const *argv[])
{
	struct timeval tv;

	int rt = gettimeofday(&tv, NULL);
	if (rt == -1) {
		perror("gettimeofday");
		exit(EXIT_FAILURE);
	}


	fprintf(stdout, "sec: %ld\n", tv.tv_sec);
	fprintf(stdout, "usec: %ld\n", tv.tv_usec);

	
	return 0;
}