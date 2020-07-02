#include "base.h"

int main(int argc, char const *argv[])
{
	const char *hostname = "zsf-test-yes";
	char ori_hostname[100];
	int rt0 = gethostname(ori_hostname, 100);
	if (rt0 == 0) {
		fprintf(stdout, "ori_hostname: %s\n", ori_hostname);
	}

	int rt1 = sethostname(hostname, strlen(hostname));
	if (rt1 == 0) {
		fprintf(stdout, "%s\n", "ok");
		char buf[100];
		int rt2 = gethostname(buf, 100);
		if (rt2 == 0) {
			fprintf(stdout, "HostName: %s\n", buf);
		}

		sethostname(ori_hostname, strlen(ori_hostname));
	} else {
		perror("sethostname");
	}
	return 0;
}