#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>     // O_CREAT|O_APPEND
#include <sys/stat.h>  // S_IRWXU
#include <errno.h>

#include <string.h>    // strerror 必须要包含这个

int main(int argc, char const *argv[]) {
	int fd = open("./file.txt", O_CREAT|O_APPEND, S_IRWXU);
	if (fd < 0) {
		fprintf(stdout, "%s\n", "fd open err");
		exit(1);
	}

	char buf[100];
	int size = read(fd, buf, 100);
	if (size < 0) {
		fprintf(stderr, "%s\n", "read err");
		exit(1);
	} else if (size == 0) {
		fprintf(stderr, "%s\n", "file empty");
		exit(1);
	}

	printf("buf: %s\n", buf);


	// 如果没有O_RDWR，就会写入错误
	// int w_fd = open("./file_write.txt", O_CREAT|O_APPEND, S_IRWXU); // err
	int w_fd = open("./file_write.txt", O_CREAT|O_RDWR|O_APPEND, S_IRWXU);    // ok
	if (w_fd < 0) {
		fprintf(stderr, "%s\n", "w_fd open err");
		exit(1);
	}
	int w_size = write(w_fd, buf, size); // 注意这里使用size
	printf("w_size: %d\n", w_size);
	if (w_size > 0 ) {
		fprintf(stdout, "%s\n", "write ok");
	} else {
		fprintf(stderr, 
			"%s, errno: %d， error: %s\n", 
			"write err",
			 errno, 
			 strerror(errno)
		);
	}

	return 0;
}