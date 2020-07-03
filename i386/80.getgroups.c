#include "base.h"

int main(int argc, char const *argv[])
{
	gid_t list[10];
	int i;
	int rt = getgroups(10, list);
	if (rt == 0) {
		for (i=0; i<10; i++) {
			printf(" %d ==> %d\n", i, list[i]);
		}
	} else {
		perror("getgroups");
		exit(EXIT_FAILURE);
	}
	return 0;
}