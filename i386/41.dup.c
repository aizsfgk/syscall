#include "base.h"


int main(int argc, char const *argv[])
{

	int new_stdout = dup2(1, 10);
	if (new_stdout > 0) {
		write(new_stdout, "yes\n", 4);
		fprintf(stdout, "new_stdout: %d\n", new_stdout);
	} else {
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	return 0;
}