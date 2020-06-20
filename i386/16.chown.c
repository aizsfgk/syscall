#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/stat.h>
#include <fcntl.h>

/*
	int chown(const char *path, uid_t owner, gid_t group);

 */


int main(int argc, char const *argv[])
{
	
#ifdef _BSD_SOURCE

	int fd = open("./chown.file.txt", O_CREAT|O_APPEND, S_IRWXU);
	if (fd <= 0) {
		perror("open");
		exit(1);
	}

	int rt = chown("./chown.file.txt", 0, 0);
	if (rt < 0) {
		perror("chown");
		exit(1);
	} else {
		fprintf(stdout, "%s\n", "chown ok");
	}
#endif
	return 0;
}