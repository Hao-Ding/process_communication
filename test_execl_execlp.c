/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Mon 27 Jan 2014 03:40:06 AM CST
 * Filename		: test_execl_execlp.c
 * Description	: An example of execl and execlp 
 * ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	pid_t pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	if (pid == 0) {
		if (execl("/home/dhlinux/smallprograms/test_process/hello", "hello", (char *) 0) < 0) { // exec hello
			fprintf(stderr, "execl error \n");
			exit(1);
		}
	}
	else {
		if (waitpid(pid, NULL, 0) < 0) {
			fprintf(stderr, "waitpid error 1\n");
			exit(1);
		}
		if ((pid = fork()) < 0) {
			fprintf(stderr, "fork error 2\n");
			exit(1);
		}
		if (pid == 0) {
			if (execlp("ls", "ls", "-al", ".", (char *) 0) < 0) { // exec ls -al .
				fprintf(stderr, "execlp error\n");
				exit(1);
			}
		}
		else {
			if (waitpid(pid, NULL, 0) < 0) {
				fprintf(stderr, "waitpid error 2\n");
				exit(1);
			}
		}
	}

	return 0;
}

