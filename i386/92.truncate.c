#include "base.h"

int main(int argc, char const *argv[])
{
	int rt = truncate("./file/truncate.txt", 3);

	if (rt == 0) {
		fprintf(stdout, "%s\n", "ok");
	} else {
		perror("truncate");
		exit(-1);
	}
	return 0;
}