#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>


#include <errno.h>

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		perror("argc num must 2");
		exit(1);
	}
	char buf[100];
	printf("%s\n", getcwd(buf, sizeof(buf)));
	int ret = chdir(argv[1]); // 改变当前工作目录
	if (ret == 0 ) {
		printf("%s\n", getcwd(buf, sizeof(buf)));
	} else {
		printf("%s\n", getcwd(buf, sizeof(buf)));
		printf("errno: %d, errer: %s\n", errno, strerror(errno));
		exit(1);
	}
	return 0;
}