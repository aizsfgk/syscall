#include "base.h"


// setsid - creates a session and sets the process group ID

int main(int argc, char const *argv[])
{
	pid_t sid = setsid();
	if (sid == -1) {
		perror("setsid");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%s\n", "creates a session and sets the process group ID --OK");
	return 0;
}