#include "base.h"

#include <time.h>
#include <sys/time.h>

#include <fcntl.h>

int main(int argc, char const *argv[])
{
	char old_file[100] = "file/old.file.txt";
	char new_file[100] = "file/new.file.txt";
	time_t t = time(NULL);
	struct tm *tmp;
	tmp = localtime(&t);
	char buf[100];
	strftime(buf, 100, "%Y-%m-%d_%H:%M:%S", tmp);
	strcat(old_file, buf);
	strcat(new_file, buf);

	fprintf(stdout, "old_file: %s\n", old_file);
	fprintf(stdout, "new_file: %s\n", new_file);


	int fd = creat(old_file, O_RDWR);
	if (fd < 0) {
		perror("creat");
		exit(EXIT_FAILURE);
	}
	int rt = rename(old_file, new_file);
	rt = chmod(new_file, S_ISUID|S_ISGID|S_IRUSR|S_IWUSR|S_IXUSR);

	system("ls -al file/|grep new.file.txt --col");
	return 0;
}