#include "base.h"


int main(int argc, char const *argv[])
{	gid_t gid = getgid();

	fprintf(stdout, "gid: %d\n", (int) gid);
	
	return 0;
}