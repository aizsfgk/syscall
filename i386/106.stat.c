#include "base.h"
#include <sys/stat.h>

// stat, fstat, lstat -- get file status


void statPrint(struct stat *st) {
	printf("=============\n");
	fprintf(stdout, "st_dev: %d\n", (int)st->st_dev);
	fprintf(stdout, "st_ino: %d\n", (int)st->st_ino);
	fprintf(stdout, "st_nlink: %d\n", (int)st->st_nlink);
	fprintf(stdout, "st_uid: %d\n", (int)st->st_uid);
	fprintf(stdout, "st_gid: %d\n", (int)st->st_gid);
	fprintf(stdout, "st_size: %d\n", (int)st->st_size);
	fprintf(stdout, "st_atime: %d\n", (int)st->st_atime);
	fprintf(stdout, "st_mtime: %d\n", (int)st->st_mtime);
	fprintf(stdout, "st_ctime: %d\n", (int)st->st_ctime);
	printf("=============\n");
}

int main(int argc, char const *argv[])
{
	const char * file = "./file/file.txt";

	struct stat st;
	int rt = stat(file, &st);
	if (rt == -1) {
		perror("stat");
	}

	statPrint(&st);
	return 0;
}