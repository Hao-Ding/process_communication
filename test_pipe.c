/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Mon 27 Jan 2014 05:15:50 AM CST
 * Filename		: test_pipe.c
 * Description	: An example of communication through pipe 
 * ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int n, fd[2];
	pid_t pid;
	char line[1024];

	if (pipe(fd) < 0) {
		fprintf(stderr, "pipe error\n");
		exit(1);
	}
	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	if (pid > 0) {
		close(fd[0]);
		write(fd[1], "hello world\n", 13);
	}
	else {
		close(fd[1]);
		n = read(fd[0], line, 1024);
		write(STDOUT_FILENO, line, n);
	}
	return 0;
}

