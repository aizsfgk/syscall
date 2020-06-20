#include <stdio.h>
#include <stdlib.h>

#include <unistd.h> // unlink

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fd = open("./one_link2_ori.file.txt", O_CREAT|O_APPEND|O_RDWR, S_IRWXU);
	char *str = "hello-link\n";
	write(fd, str, strlen(str));

	int ret = link("./one_link2_ori.file.txt", "./new_link2.file.txt");
	if (ret == 0) {
		fprintf(stdout, "link success\n");

		system("ls -al | grep link2");

	} else {
		fprintf(stderr, "%s\n", "link err");
		exit(1);
	}

	int unret = unlink("./new_link2.file.txt");
	if (unret == 0) {

		// ************************* //

		fprintf(stdout, "unlink success\n");
		system("ls -al | grep link2");
	} else {
		fprintf(stderr, "%s\n", "unlink err");
	}		exit(1);
	
	//
	//
	// 
	//
	//
	return 0;
}