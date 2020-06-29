#include "base.h"

#include <signal.h>


// int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
// 
// how: 
//     SIG_BLOCK : 将set指向的信号集内的信号添加到信号掩码中
//     SIG_UNBLOCK : 移除
//     SIG_SETMASK : 赋值
//     
//     
int main(int argc, char const *argv[])
{
	sigset_t blockSet, prevSet;

	sigemptyset(&blockSet);
	sigaddset(&blockSet, SIGINT);

	if (sigprocmask(SIG_BLOCK, &blockSet, &prevSet) == -1)
		exit(EXIT_FAILURE);

	kill(getpid(), SIGINT);

	printf("hello-world\n");


	if (sigprocmask(SIG_SETMASK, &prevSet, NULL) == -1)
		exit(EXIT_FAILURE);

	sleep(100);
	printf("%s\n", "end");
	return 0;
}