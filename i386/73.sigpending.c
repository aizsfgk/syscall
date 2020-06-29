#include "base.h"

#include <signal.h>

// int sigpending(sigset_t *set); // 返回处于等待状态的信号

void printSigset(FILE *of, const char * prefix, const sigset_t *sigset)
{
	int sig, cnt;
	cnt = 0;
	for (sig=1; sig < NSIG; sig++) {
		if (sigismember(sigset, sig)) {
			cnt++;
			fprintf(of, "%s: %d (%s)\n", prefix, sig, strsignal(sig));
		}
	}

	if (cnt == 0) {
		fprintf(of, "%s: (%s)\n", prefix, "<sigset is empty>");
	}
}

int printSigMask(FILE *of, const char *msg)
{
	sigset_t currMask;
	if (msg != NULL)
		fprintf(of, "%s", msg);


	// 获取当前阻塞信号的MAask
	if (sigprocmask(SIG_BLOCK, NULL, &currMask) == -1) {
		return -1;
	}

	printSigset(of, "\t\t", &currMask);

	return 0;
}

// 打印当前进程pending的信号
int printPendingSigs(FILE *of, const char *msg)
{
	sigset_t pendingSigs;
	if (msg != NULL) {
		fprintf(of, "%s\n", msg);
	}

	if (sigpending(&pendingSigs) == -1)
		return -1;

	printSigset(of, "\t\t", &pendingSigs);
	return 0;
}

int main(int argc, char const *argv[])
{
	sigset_t blockSet;

	sigemptyset(&blockSet);
	sigaddset(&blockSet, SIGUSR1);
	// sigaddset(&blockSet, SIGUSR2);
	sigaddset(&blockSet, SIGINT);
	sigaddset(&blockSet, SIGTERM);
	sigaddset(&blockSet, SIGHUP);

	if (sigprocmask(SIG_BLOCK, &blockSet, NULL) == -1)
		exit(EXIT_FAILURE);


	kill(getpid(), SIGINT);

	printSigMask(stdout, "mask: ");
	printPendingSigs(stdout, "pending: ");

	pause();
	printf("end\n");
	return 0;
}