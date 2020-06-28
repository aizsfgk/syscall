#include "base.h"

#include <ustat.h>

// ustat - get file system statistics
// 

int main(int argc, char const *argv[])
{
    
	struct ustat ust;

	int rt = ustat(1, &ust);
	if (rt == 0) {
		printf("f_tfree: %ld\n", (long)ust.f_tfree);
		printf("f_tinode: %ld\n", (long)ust.f_tinode);
		printf("f_fname: %s\n", ust.f_fname);
		printf("f_fpack: %s\n", ust.f_fpack);
	} else {
		perror("ustat");
		exit(EXIT_FAILURE);
	}
	return 0;
}
