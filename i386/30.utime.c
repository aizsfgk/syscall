#include <sys/types.h>
#include <utime.h>

#include <sys/stat.h> // stat函数

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>


// utime, utimes - change file last access and modification times
int main(int argc, char const *argv[])
{
	char buf[100];
	
	struct stat st;
	const char * file_name = "./file/utime.file.txt";
	int ret = stat(file_name, &st);
	if (ret == 0) {
		fprintf(stdout, "st_atim => tv_sec: %ld, tv_nsec: %ld\n", (long) st.st_atim.tv_sec, (long)  st.st_atim.tv_nsec);
		fprintf(stdout, "st_mtim => tv_sec: %ld, tv_nsec: %ld\n", (long) st.st_mtim.tv_sec, (long)  st.st_mtim.tv_nsec);

		struct tm *tm_local;
		tm_local = localtime(&st.st_atim.tv_sec);
		strftime(buf, 100, "[%Y-%m-%d %H:%M:%S]", tm_local);
		fprintf(stdout, "访问时间: %s\n", buf);


		tm_local = localtime(&st.st_mtim.tv_sec);
		strftime(buf, 100, "[%Y-%m-%d %H:%M:%S]", tm_local);
		fprintf(stdout, "修改时间: %s\n", buf);

		// 修改时间
		
		struct utimbuf u_time_buf;
		u_time_buf.actime =  time(NULL) + 10;
		u_time_buf.modtime = time(NULL) + 100;
		ret = utime(file_name, &u_time_buf);
		if (ret == 0) {
			fprintf(stdout, "%s\n", "utime_ok");

			tm_local = localtime(&st.st_atim.tv_sec);
			strftime(buf, 100, "[%Y-%m-%d %H:%M:%S]", tm_local);
			fprintf(stdout, "访问时间: %s\n", buf);


			tm_local = localtime(&st.st_mtim.tv_sec);
			strftime(buf, 100, "[%Y-%m-%d %H:%M:%S]", tm_local);
			fprintf(stdout, "修改时间: %s\n", buf);


		} else {
			perror("utime");
			exit(EXIT_FAILURE);
		}

	} else {
		perror("stat");
		exit(EXIT_FAILURE);
	}
	return 0;
}