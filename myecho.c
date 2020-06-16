#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int j;
	fprintf(stdout, "\n=============\n%s\n", "i am myecho");
	for (j=0; j<argc; j++)
		printf("argv[%d]: %s\n", j, argv[j]);


	exit(EXIT_SUCCESS);
}