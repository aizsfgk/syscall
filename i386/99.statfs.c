#include "base.h"
#include <sys/vfs.h>


// statfs, fstatfs - get filesystem statistics
// 
// 获取文件系统统计信息
// 

int main(int argc, char const *argv[])
{
	const char * file = "./file/file.txt";
	struct statfs sfs;
	int rs = statfs(file, &sfs);
	if (rs == -1) {
		perror("statfs");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "f_type: %x\n", (int) sfs.f_type); // EXT4_SUPER_MAGIC      0xEF53
	return 0;
}