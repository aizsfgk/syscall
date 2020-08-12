#include "base.h"

/*
	st_dev: 64513
	st_size: 34
	st_nlink: 1
	st_uid: 46705
	st_gid: 46705
	st_ino: 15227984
	st_atime: 1597198170
	st_mtime: 1597198170
	st_ctime: 1597198171
 */
void statPrint(struct stat buf) {
	fprintf(stdout, "st_dev: %ld\n",   (long) buf.st_dev);
	fprintf(stdout, "st_size: %ld\n",  (long) buf.st_size);
	fprintf(stdout, "st_nlink: %ld\n", (long) buf.st_nlink);
	fprintf(stdout, "st_uid: %ld\n",   (long) buf.st_uid);
	fprintf(stdout, "st_gid: %ld\n",   (long) buf.st_gid);
	fprintf(stdout, "st_ino: %ld\n",   (long) buf.st_ino);
	fprintf(stdout, "st_atime: %ld\n", (long) buf.st_atime);
	fprintf(stdout, "st_mtime: %ld\n", (long) buf.st_mtime);
	fprintf(stdout, "st_ctime: %ld\n", (long) buf.st_ctime);
}

int main(int argc, char const *argv[])
{
	const char *filename = "./file/stat.file.txt";
	struct stat buf;

	// stat
	int rs = stat(filename, &buf);

	// fstat
	
	// lstat

	if (rs == -1) {
		perror("stat");
		exit(EXIT_FAILURE);
	}


	statPrint(buf);

	return 0;
}