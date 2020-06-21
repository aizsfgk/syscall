#include <sys/types.h>
#include <unistd.h>
#include <sys/mount.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	const char * dir = "/tmp/proc";
	// int ret = umount(dir);
	// 
	// 
	// fuser : Show which processes use the named files, sockets, or filesystems.
	// 

	int ret = umount2(dir, MNT_FORCE)
	if (ret == 0) {
		fprintf(stdout, "ok\n");
	} else {
		perror("umount");
		exit(EXIT_FAILURE);
	}
	return 0;
}