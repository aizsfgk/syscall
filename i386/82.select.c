#include "base.h"
#include <sys/select.h>

// select,  pselect, FD_CLR, FD_ISSET, FD_SET, FD_ZERO - synchronous I/O multiplexing
//      


int main(int argc, char const *argv[])
{
	fd_set rfds;
	struct timeval tv;
	int retval;

	fprintf(stdout, "FD_SETSIZE: %ld\n", (long)FD_SETSIZE); // 默认是1024

	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	// 等待5s
	tv.tv_sec = 5;
	tv.tv_usec = 0;

	retval = select(1, &rfds, NULL, NULL, &tv);

	if (retval == -1) {
		perror("select");
	} else if (retval) {
		printf("Data is  avilable now.\n");
	} else {
		printf("NO data within five seconds.\n");
	}
	
	return 0;
}