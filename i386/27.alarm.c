#include <unistd.h>
#include <stdio.h>
#include <sys/signal.h>

void sig_handler(int num) {
	if (0 > num) {
		fprintf(stderr,"sig_handler param err. [%d]\n",num);
        return;
	}
	if (num == SIGALRM) {
		fprintf(stdout, "i am alarm signal.\n");
	}
	if (num == SIGHUP) {
		fprintf(stdout, "%s\n", "i am SIGHUP signal");
	}
}

int main(int argc, char const *argv[])
{
	signal(SIGALRM, sig_handler);
	signal(SIGHUP,sig_handler);

	int rt = alarm(2);
	fprintf(stdout, "rt1: %d\n", rt);
	rt = alarm(1);
	fprintf(stdout, "rt2: %d\n", rt);

	// 
	// 


	pause(); // 等待信号到达；才能被打断

	sleep(200);

	return 0;
}