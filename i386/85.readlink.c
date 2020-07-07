#include "base.h"

// 读取link文件

int main(int argc, char const *argv[])
{

	char buf[200];

	// buf 存储真实的文件名
	
	ssize_t rd_size = readlink("./file/link_path_file.txt", buf, 200);
	if (rd_size > 0) {
		fprintf(stdout, "%s\n", buf);
	} else {
		perror("readlink");
		exit(EXIT_FAILURE);
	}
	return 0;
}