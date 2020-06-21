#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>



int main(int argc, char *argv[])
{
   pid_t pid = getpid();
   uid_t uid = getuid();
   uid_t euid = geteuid();


   fprintf(stdout, "pid: %d\n", pid);
   fprintf(stdout, "uid: %d\n", uid);
   fprintf(stdout, "euid: %d\n", euid);
   return 0;
}
