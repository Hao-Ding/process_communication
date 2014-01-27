/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Sun 26 Jan 2014 10:01:24 PM CST
 * Filename		: test_fork.c
 * Description	: An example of how to fork a child process. 
 * ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
	pid_t pid;

	char buffer[] = "Output to stdout\n";
	if (write(STDOUT_FILENO, buffer, sizeof(buffer) - 1) != sizeof(buffer) - 1) {
		fprintf(stderr, "write error\n");
	}
	printf("before fork\n");

	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error\n");
	}
	else if (pid == 0) {
		printf("child\n");
		printf("getpid = %d\n", getpid());
		printf("getppid = %d\n", getppid());
	}
	else {
		sleep(2);
		printf("parent\n");
		printf("getpid = %d\n", getpid());
		printf("getppid = %d\n", getppid());
	}

	printf("finish\n");
	return 0;
}

