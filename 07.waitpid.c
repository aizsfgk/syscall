#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdlib.h> // exit

/*

    #include <sys/types.h>
    #include <sys/wait.h>

	pid_t waitpid(pid_t pid, int *wstatus, int options);


# 会阻塞调用进程，直到一个pid参数相关的特殊子进程状态发生改变

pid:
1. pid < -1  : 等待任意子进程，她的进程组ID等于 pid绝对值
2. pid == -1 : 等待任意的子进程
3. pid == 0  : 等待任意子进程，它的进程组id等于调用进程
4. pid > 0   : 等待进程id为pid的子进程

options:
	WNOHANG : 子进程没有退出，也立刻返回
	WUNTRACE ： 
	WCONTINUED

wstatus: 存储子进程的返回状态

	WIFEXITED(wstatus)
	WEXITSTATUS(wstatus)
	...
	
等待一个子进程状态改变：
1. 子进程退出
2. 子进程被一个信号结束
3. 子进程被一个信号恢复

如果wait没有被使用，则会产生一个僵尸进程


 */

int main(int argc, char *argv[])
{
    
    
    if (atoi(argv[1]) == 1) {
    	pid_t pid;
    	pid_t wpid;
    	int status;
    	// waitpid
    	pid = fork();
	    if (pid > 0) {
	    	fprintf(stdout, "i am master process, pid: %d, child_pid: %d\n", getpid(), pid);
	    	wpid = waitpid(-1, &status, 0);
	    	if (wpid > 0) {
	    		fprintf(stdout, "%s, wpid:%d, status:%d\n", "waitpid: ", wpid, WEXITSTATUS(status));
	    	} else {
	    		fprintf(stderr, "%s\n", "waitpid err");
	    	}
	    } else if (pid == 0) {
	    	fprintf(stdout, "i am child process, pid: %d\n", getpid());

	    	exit(3);
	    } else {
	    	fprintf(stderr, "%s\n", "fork err");
	    	exit(1);
	    }
    } else {

    	/*
    		$ ./a.out &                            
			Child PID is 32360                     
			[1] 32359                              
			$ kill -STOP 32360                     
			stopped by signal 19                   
			$ kill -CONT 32360                     
			continued                              
			$ kill -TERM 32360                     
			killed by signal 15                    
			[1]+  Done                    ./a.out  
			$                                      
    	 */

    	// waitid()
    	// int waitid(idtype_t idtype, id_t id, siginf_t *infop, int options);
    	pid_t cpid, w;
    	int wstatus;

    	cpid = fork();
    	if (cpid == -1) {
    		perror("fork");
    		exit(EXIT_FAILURE);
    	}

    	// 子进程返回0
    	if (cpid == 0) {
    		printf("child pid is %ld\n", (long) getpid());
    		if (atoi(argv[1]) == 2)
    			pause(); // 让进程暂停直到信号出现, Wait for signals                 
    		_exit(atoi(argv[1]));
    	} else {
    		do {
    			w = waitpid(cpid, &wstatus, WUNTRACED|WCONTINUED);
    			if (w == -1) {
    				perror("waitpid");
    				exit(EXIT_FAILURE);
    			}

    			if (WIFEXITED(wstatus)) {
    				printf("exited, status=%d,\n",  WEXITSTATUS(wstatus)); // 直接退出


    			//// 其他状态	
    			} else if (WIFSIGNALED(wstatus)) {
    				printf("killed by signal %d\n", WTERMSIG(wstatus));
    			} else if (WIFSTOPPED(wstatus)) {
    				printf("stopped by signal %d\n", WSTOPSIG(wstatus));
    			} else if (WIFCONTINUED(wstatus)) {
    				printf("continued\n");
    			}

    		} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
    		exit(EXIT_SUCCESS);
    	}
    }
    return 0;
}
