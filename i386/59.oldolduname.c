#include "base.h"
#include <sys/utsname.h>

int main(int argc, char const *argv[])
{
	struct utsname un;

	int rt = uname(&un);
	if (rt == -1) {
		perror("uname");
		exit(EXIT_FAILURE);
	}

	unamePrintf((struct utsname *)&un);

	return 0;
}


void unamePrintf(struct utsname *utsnP) {
	fprintf(stdout, "%s\n", "=======================");
	fprintf(stdout, 
		"sysname: %s\nnodename: %s\nrelease: %s\nversion: %s\nmachine: %s\n",
		utsnP->sysname,
		utsnP->nodename,
		utsnP->release,
		utsnP->version,
		utsnP->machine);
	fprintf(stdout, "%s\n\n", "=======================");
	return;
}