#include "base.h"
#include <sys/time.h>
#include <signal.h>

/*
	一共支持以下3中计数器形式：  
  　　ITIMER_REAL      在real   time中计数器减1，然后等计数往比后发送SIGALRM信号。  
  　　ITIMER_VIRTUAL   当进程在执行的过程中计数，然后当计数完毕后发送SIGVTALRM信号给该进程。  
  　　ITIMER_PROF      在该进程被执行和系统在代表该进程执行的时间都进行计数 
 */

void PrintMsg(int Num) {
	printf("PrintMsg: %s => %d \n", "hello", Num);
}

int main(int argc, char const *argv[])
{
	signal(SIGALRM, PrintMsg);

	struct itimerval tick;
	tick.it_value.tv_sec = 10; // 10s后启动定时器
	tick.it_value.tv_usec = 0;
	tick.it_interval.tv_sec = 1; // 每隔1s执行一次相应的函数
	tick.it_interval.tv_usec = 0;


	int ret = setitimer(ITIMER_REAL, &tick, NULL);
	if (ret == -1) {
		perror("setitimer");
		exit(EXIT_FAILURE);
	}

	printf("Wait!\n");

	getchar(); // 阻塞在这里

	return 0;
}