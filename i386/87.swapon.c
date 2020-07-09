#include "base.h"
//#include <asm/page.h>
#include <sys/swap.h>

int main(int argc, char const *argv[])
{
	const char *swap_file = "./file/swap.file.txt";

	int rt = swapon(swap_file, 0);
	if (rt == 0) {
		fprintf(stdout, "ok\n");
	} else {
		perror("swapon");
		exit(EXIT_FAILURE);
	}
	return 0;
}
