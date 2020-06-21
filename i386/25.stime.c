#include <time.h>
// #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	fprintf(stdout, "%s\n", "prev: ");
	system("date");
	time ori_t = time(NULL);
	time_t t = 1592728043; // 

	int ret = stime(&t); // settime
	if (ret != 0) {
		perror("stime");
	}

	fprintf(stdout, "%s\n", "next: ");
	system("date");

	int ret2 = stime(&ori_t);
	if (ret != 0) {
		perror("stime2");
	}

	fprintf(stdout, "%s\n", "next: "); // 改回之前的时间
	system("date");

	return 0;
}
