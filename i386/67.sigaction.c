#include "base.h"
#include <signal.h>


// sigaction - examine and change a signal action
// int sigaction(int signum, const struct sigaction *act,
//                 struct sigaction *oldact);
//           
//                       
//    struct sigaction {
//        void     (*sa_handler)(int);
//        void     (*sa_sigaction)(int, siginfo_t *, void *);
//        sigset_t   sa_mask;
//        int        sa_flags;
//        void     (*sa_restorer)(void); // 已经废弃
//     };         
//                 
//                 
//

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

	printSigset(&pendingSigs);
	return 0;
}




int main(int argc, char const *argv[])
{
/*
	struct sigaction newact, oldact;

	newact.sa_handler = SIG_IGN;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;

	int count = 0;
	pid_t pid = 0;

	psignal(SIGINT, "zsf_psignal => ");
	sigaction(SIGINT, &newact, &oldact);

	pid = fork();
	if (pid == 0) {
		while (1) {
			printf("i am child ...\n");
			sleep(1);
		}

		return 0;
	} else if (pid > 0) {
		while (1) {
			if (count++ > 3) {
				sigaction(SIGINT, &oldact, NULL);
				printf("pid == %d\n", pid);
			}

			printf("i am parent ....\n");
			sleep(1);
			kill(pid, SIGKILL);
		}
	}

*/
	
	return 0;
}