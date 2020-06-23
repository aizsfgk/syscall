#include "base.h"

int main(int argc, char const *argv[])
{
	uid_t euid = geteuid();
	printf("euid: %d\n",(int) euid );
	return 0;
}