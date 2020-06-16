#include <time.h>
#include <stdio.h>

#include <sys/time.h>

int main(int argc, char const *argv[])
{
	time_t tt = time(NULL);
	fprintf(stdout, "time: %ld \n", (long) tt);

	/*
	struct timeval tv;
	int rt = gettimeofday(&tv, NULL);
	*/
	#define LOG_BUFFER_SIZE 100
	char buffer[LOG_BUFFER_SIZE], *ptr = buffer;
	int size, cap = LOG_BUFFER_SIZE;
	struct tm *tmp;


	tmp = localtime(&tt);
	size = strftime(ptr, cap, "[%Y-%m-%d %H:%M:%S]", tmp);
	if (size > 0 ) {
		fprintf(stdout, "date: %s\n",ptr );
	}

	return 0;
}