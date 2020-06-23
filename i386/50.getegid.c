#include "base.h"

int main(int argc, char const *argv[])
{
	gid_t egid = getegid();
	printf("egid: %d\n", (int) egid);
	return 0;
}