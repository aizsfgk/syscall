#include "base.h"
#include <dirent.h>

// readdir - read directory entry
// 
// use man 3 readdir
// 
// 


int main(int argc, char const *argv[])
{
	// struct dirent dir;

	DIR *pdir = NULL;
	int cnt = 0;
	struct dirent *psdir;

	if (argc != 2) {
		fprintf(stderr, "useage: %s dirname\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pdir = opendir(argv[1]);
	if (pdir == NULL) {
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	while (1) {
		psdir = readdir(pdir);
		if (psdir != NULL) {
			if (psdir->d_type == DT_REG) {
				fprintf(stdout, "%s => ", "普通文件");
			} else {
				fprintf(stdout, "%s => ", "非普通文件");
			}
			fprintf(stdout, "名字: %s\n", psdir->d_name);

			cnt ++;
		} else {
			break;
		}
	}

	fprintf(stdout, "总文件数:%d\n", cnt);

	return 0;
}