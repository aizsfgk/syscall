#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <linux/fs.h> // MS_RDONLY
/*
/dev/vda1 on / type ext4 (rw)
proc on /proc type proc (rw)
sysfs on /sys type sysfs (rw)
devpts on /dev/pts type devpts (rw,gid=5,mode=620)
tmpfs on /dev/shm type tmpfs (rw)
none on /proc/sys/fs/binfmt_misc type binfmt_misc (rw)
 */


int main(int argc, char const *argv[])
{
	int ret = mount("none", "/tmp/proc", "proc", MS_RDONLY, NULL);

	if (ret == 0) {
		fprintf(stdout, "mount ok\n");
	} else {
		perror("mount");
		exit(EXIT_FAILURE);
	}
	return 0;
}
