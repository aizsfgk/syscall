#include "base.h"

#include <sys/times.h>
#include <time.h>

// struct tms {
//    clock_t tms_utime;  /* user time */
//    clock_t tms_stime;  /* system time */
//    clock_t tms_cutime; /* user time of children */
//    clock_t tms_cstime; /* system time of children */
// };

int main(int argc, char const *argv[])
{
	struct tms time_buf_start, time_buf_end;
	long tck = 0;
	clock_t time_start, time_end;

	tck = sysconf(_SC_CLK_TCK);
	printf("tck:%f\n", tck);
	time_start = times(&time_buf_start);
	printf("start_time is : %f\n", time_start);

	// system("sleep 2"); // 子进程睡眠2s
	sleep(2);

	time_end = times(&time_buf_end);
	printf("end_time is : %f\n", time_end);

	printf("dur: %lf\n", (double)(time_end - time_start) / CLOCKS_PER_SEC); // 程序执行间隔


	printf("tck:%f\n", tck);
	printf("user time is        : %f \n" ,  (time_buf_end.tms_utime  - time_buf_start.tms_utime) / tck); 
    printf("systime time is     : %f \n" ,  (time_buf_end.tms_stime  - time_buf_start.tms_stime) / tck);
    printf("child user time is  : %f \n" ,  (time_buf_end.tms_cutime - time_buf_start.tms_cutime) / tck);
    printf("child sys time is   : %f \n" ,  (time_buf_end.tms_cstime - time_buf_start.tms_cstime) / tck);
    

	return 0;
}