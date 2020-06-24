#include "base.h"


// acct - switch process accounting on or off

int main(int argc, char const *argv[])
{
	const char * file_name = "/var/log/pacct_zsf";
	int rt = acct(file_name);
	if (rt == 0) {
		fprintf(stdout, "%s\n", "ok");
	} else {
		perror("acct");
		exit(EXIT_FAILURE);
	}
	return 0;
}