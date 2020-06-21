#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

/*
	
 */

int main(int argc, char const *argv[])
{
	// 设置进程的pid
	int ret = setuid(0);
	if (ret == 0) {
		fprintf(stdout, "%s\n", "ok");
	} else {
		perror("setuid");
		exit(EXIT_FAILURE);
	}
	return 0;
}
