#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// gcc -std=c99 -D_XOPEN_SOURCE 34.nice.c -o output/34.nice
int main(int argc, char const *argv[])
{

#ifdef _XOPEN_SOURCE
	printf("yes\n");
	printf("_XOPEN_SOURCE: %d\n", (int)_XOPEN_SOURCE);
#else
	printf("no\n");
#endif
	int inc = 5;
	int ret = nice(inc);
	if (ret > 0) {
		fprintf(stdout, "new nice : %d\n", ret);
	} else if (ret < 0) {
		perror("nice");
		exit(EXIT_FAILURE);
	}
	return 0;
}