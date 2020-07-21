#include "base.h"

int main(int argc, char const *argv[])
{
	int r = iopl(2);

	if (r == -1) {
		perror("iopl");
		exit(EXIT_FAILURE);
	}
	return 0;
}