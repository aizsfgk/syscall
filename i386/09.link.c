#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>


#include <unistd.h> // link

int main(int argc, char const *argv[])
{
	int fd = open("./one_link_ori.file.txt", O_CREAT|O_APPEND|O_RDWR, S_IRWXU);
	char *str = "hello-link\n";
	write(fd, str, strlen(str));


	int ret = link("./one_link_ori.file.txt", "./new_link.file.txt");
	if (ret == 0) {
		fprintf(stdout, "link success\n");
	} else {
		fprintf(stderr, "%s\n", "link err");
		exit(1);
	}
	return 0;
}