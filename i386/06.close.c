#include <stdio.h> // fprintf
#include <unistd.h> // open, close
#include <stdlib.h> // exit

#include <sys/stat.h> // O_CREAT|O_RDWR|O_APPEND
#include <fcntl.h> // S_IRWXU


#define FLAG O_CREAT|O_RDWR|O_APPEND
#define MODE S_IRWXU

int main(int argc, char *argv[])
{
   int fd = open("./close.txt", FLAG, MODE);
   if (fd < 0)
     fprintf(stderr, "open file err");

   write(fd, "close\n", 6);


   close(fd);
   return 0;
}
