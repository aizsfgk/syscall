#include "base.h"
#include <linux/net.h>

/*
x86-64 and ARM—there is no socketcall() system call;

socket system calls

#include <linux/net.h> 
int socketcall(int call, unsigned long *args);
	SYS_SOCKET        socket(2)
	SYS_BIND          bind(2)
	SYS_CONNECT       connect(2)
	SYS_LISTEN        listen(2)
	SYS_ACCEPT        accept(2)
	SYS_GETSOCKNAME   getsockname(2)
	SYS_GETPEERNAME   getpeername(2)
	SYS_SOCKETPAIR    socketpair(2)
	SYS_SEND          send(2)
	SYS_RECV          recv(2)
	SYS_SENDTO        sendto(2)
	SYS_RECVFROM      recvfrom(2)
	SYS_SHUTDOWN      shutdown(2)
	SYS_SETSOCKOPT    setsockopt(2)
	SYS_GETSOCKOPT    getsockopt(2)
	SYS_SENDMSG       sendmsg(2)
	SYS_RECVMSG       recvmsg(2)
	SYS_ACCEPT4       accept4(2)
	SYS_RECVMMSG      recvmmsg(2)
	SYS_SENDMMSG      sendmmsg(2)

*/


int main(int argc, char const *argv[])
{
	int rt;

	rt = socketcall(SYS_SOCKET, NULL);
	if (rt == -1) {
		perror("socketcall");
		exit(EXIT_FAILURE);
	}
	return 0;
}