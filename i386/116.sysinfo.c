#include "base.h"
#include <sys/sysinfo.h>


// 使用 sysinfo 做一个内存监控器
int main(int argc, char const *argv[])
{
	struct sysinfo si;

	int rs = sysinfo(&si);
	if (rs == 0) {

		fprintf(stdout, "uptime: %ld\n", si.uptime);
		fprintf(stdout, "totalram: %ld\n", si.totalram);
		fprintf(stdout, "freeram: %ld\n", si.freeram);
		fprintf(stdout, "bufferram: %ld\n", si.bufferram);

	} else {
		fprintf(stderr, "%s\n", "sysinfo ");
		perror("sysinfo");
		exit(EXIT_FAILURE);
	}
	return 0;
}