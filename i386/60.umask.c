#include "base.h"
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char const *argv[])
{
	mode_t um_bits = umask(S_IWGRP | S_IWOTH);
	printf("umask: %d\n", um_bits);

	um_bits = umask(0);
	printf("umask_now: %d\n", um_bits);
	return 0;
}