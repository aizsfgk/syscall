#include "base.h"

int main(int argc, char const *argv[])
{
	int new_fd = dup2(1, 123);
	if (new_fd > 0) {
		write(123, "hello-dup2\n", sizeof("hello-dup2"));
	} else {
		perror("dup2");
		exit(EXIT_FAILURE);
	}



	return 0;
}