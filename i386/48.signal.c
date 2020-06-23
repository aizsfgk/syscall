#include "base.h"

#include <signal.h>


// signal - ANSI C signal handling


void sig_handler(int sNum) {
	if (sNum < 0) {
		fprintf(stderr, "%s, sNum: %d\n", "errnum", sNum);
		return;
	}
	if (sNum == SIGHUP) {
		fprintf(stdout, "i am SIGHUP, %d\n", SIGHUP);
	}
	if (sNum == SIGTERM) {
		fprintf(stdout, "i am SIGTERM, %d\n", SIGTERM);
	}
}

int main(int argc, char const *argv[])
{
	signal(SIGHUP, sig_handler);
	signal(SIGTERM, sig_handler);

	raise(SIGHUP);

	pause();
	return 0;
}