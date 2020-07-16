#include "base.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

// mmap, mmap64, munmap - map or unmap files or devices into memory
// 
// 
// 内存映射文件
// 
// 
// 
// 
// 

int main(int argc, char const *argv[])
{
	char *addr;
	int fd;
	struct stat sb;

	if (argc != 2 || strcmp(argv[1], "--help") == 0) {
		fprintf(stdout, "%s %s\n", argv[0], "file");
		return 0;
	}	

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	// use fstat
	if (fstat(fd, &sb) == -1) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}

	// use map
	addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (addr == MAP_FAILED)
		exit(EXIT_FAILURE);

	if (write(STDOUT_FILENO, addr, sb.st_size) != sb.st_size) {
		perror("write");
		exit(EXIT_FAILURE);
	}


	if (munmap(addr, sb.st_size) == -1) {
		perror("munmap");
		exit(EXIT_FAILURE);
	} else {
		fprintf(stdout, "\n%s\n", "munmap ok");
	}

	return 0;
}
