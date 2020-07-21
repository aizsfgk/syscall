#include "base.h"
#include <sys/io.h>

// ioperm - set port input/output permissions
// 


int main(int argc, char const *argv[])
{
	int rs = ioperm(10000, 10, 1);
	if (rs == -1) {
		perror("ioperm");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "ok\n");
	return 0;
}