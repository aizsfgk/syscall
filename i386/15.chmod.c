#include <stdio.h>

#include <unistd.h>

#include <sys/stat.h>

#include <stdlib.h>
#include <errno.h>



int main(int argc, char const *argv[])
{
	int rt = chmod("./chown.file.txt", S_ISUID|S_ISGID|S_IRUSR|S_IWUSR|S_IXUSR);
	if (rt == 0) {
		fprintf(stdout, "%s\n", "chmod ok");
	} else {
		perror("chmod");
		exit(1);
	}
	return 0;
}