#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // stdout, stderr

void exit_print(void)
{
	printf("hello, exit_print1\n");   
}

void exit_print2(void)
{
	printf("hello, exit_print2\n");
}


int main(int argc, char *argv[])
{
    long a;
	int  i;
	a = sysconf(_SC_ATEXIT_MAX);
	printf("ATEXIT_MAX = %ld\n", a);

	if (argv[1] != NULL && atoi(argv[1]) == 1) {
       i = atexit(exit_print);
	} else if (argv[1] != NULL && atoi(argv[1]) == 2) {
       i = atexit(exit_print2);
	}
	if (i != 0) {
	    fprintf(stderr, "can not set exit function\n");
        exit(EXIT_FAILURE);
	}
	fprintf(stdout, "exit success\n");
    exit(EXIT_SUCCESS);
}
