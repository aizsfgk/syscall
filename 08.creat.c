#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h> // creat | close

int main(int argc, char const *argv[])
{
	int fd = creat("./creat.file.txt", S_IRWXU);

	fprintf(stdout, "fd => %d\n", fd);


	close(fd);
	return 0;
}