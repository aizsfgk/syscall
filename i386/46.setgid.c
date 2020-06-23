#include "base.h"


int main(int argc, char const *argv[])
{	gid_t gid = getgid();

	fprintf(stdout, "gid: %d\n", (int) gid);
	int ret = setgid(958);
	if (ret == 0) {
		fprintf(stdout, "%s\n", "ok");
	} else {
		perror("setgid");
		exit(EXIT_FAILURE);
	}
	return 0;
}