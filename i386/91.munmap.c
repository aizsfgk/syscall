#include "base.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/wait.h>

// mmap, mmap64, munmap - map or unmap files or devices into memory


int main(int argc, char const *argv[])
{
	
	int *addr;

	int fd;

	fd = open("/dev/zero", O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	addr = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	*addr = 1;

	switch(fork()) {
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
			break;
		case 0:
			printf("child started. value => %d\n", *addr);
			(*addr) ++;
			if (munmap(addr, sizeof(int)) == -1) {
				perror("child munmap");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
			break;
		default:
			if (wait(NULL) == -1) {
				perror("wait");
				exit(EXIT_FAILURE);
			}
			fprintf(stdout, "in parent value => %d\n", *addr);
			if (munmap(addr, sizeof(int)) == -1) {
				perror("parent munmap");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
			break;

	}
	return 0;
}