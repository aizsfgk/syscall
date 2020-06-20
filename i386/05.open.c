#include <stdio.h>
#include <stdlib.h> // itoa
#include <string.h>

#include <fcntl.h>  // O_CREAT|O_RDWR
#include <sys/stat.h> //S_IRWXU

#include <unistd.h> // write
/*
    每个进程都有一个自己的文件描述符表
*/
int main(int argc, char const *argv[])
{
	char num[10];

	int fd = open("./open.txt", O_CREAT|O_APPEND|O_RDWR, S_IRWXU);

	if (fd > 0) {
		sprintf(num, "%d\n", fd);
		int size = write(fd, num, strlen(num));
		if (size <= 0) {
			fprintf(stderr, "%s\n", "write err");
		}
	}


	close(fd);
	return 0;
}
