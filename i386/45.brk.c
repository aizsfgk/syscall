#include "base.h"

// brk, sbrk - change data segment size
// 
// #include <unistd.h>
// int brk(void *addr);
// void *sbrk(intptr_t increment);

int main(int argc, char const *argv[])
{
	int incre;
	printf("incre: %p\n", incre);
	char *ch = malloc(2);
	sbrk((intptr_t)&incre);
	printf("incre: %p\n", incre);

	free(ch);
	return 0;
}