#include "base.h"
#include <syslog.h>

// man 3 syslog

int main(int argc, char const *argv[])
{
	// fprintf(stdout, "LOG_BUF_LEN: %d\n", LOG_BUF_LEN);


	// char buf[100];
	// int rt = syslog(SYSLOG_ACTION_READ_ALL, buf);

	// if (rt == -1) {
	// 	perror("syslog");
	// 	exit(EXIT_FAILURE);
	// }

	// fprintf(stdout, "buf: %s\n", buf);
	
	openlog("zsf-syscall", LOG_CONS, 0);


	syslog(LOG_EMERG, "LOG_EMERG, %s\n", "i am syslog");
	syslog(LOG_ALERT, "LOG_ALERT, %s\n", "i am syslog");
	syslog(LOG_CRIT, "LOG_CRIT, %s\n", "i am syslog");
	syslog(LOG_ERR, "LOG_ERR, %s\n", "i am syslog");
	syslog(LOG_WARNING, "LOG_WARNING, %s\n", "i am syslog");
	syslog(LOG_NOTICE, "LOG_NOTICE, %s\n", "i am syslog");
	syslog(LOG_INFO, "LOG_INFO, %s\n", "i am syslog");
	syslog(LOG_DEBUG, "LOG_DEBUG, %s\n", "i am syslog");





	closelog();

	return 0;
}