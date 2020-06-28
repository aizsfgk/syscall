#include "base.h"

int main(int argc, char const *argv[])
{
	fprintf(stdout, "PPID: %ld\n", (long)getppid());
	return 0;
}