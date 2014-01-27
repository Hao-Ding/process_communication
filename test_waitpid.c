/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Sun 26 Jan 2014 11:29:58 PM CST
 * Filename		: test_waitpid.c
 * Description	: An example of waitpid() 
 * ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	pid_t pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error");
	}
	else if ( pid == 0) { // first child
		if ((pid = fork()) < 0) {
			fprintf(stderr, "for error");
		}
		else {
			if (pid > 0) { // first child finishes
				exit(0);
			}
		}
		// first child's first child
		sleep(2);
		printf(" first child's first child id = %d, parent id = %d\n", getpid(), getppid());
		exit(0);
	}
	// parent process
	if (waitpid(pid, NULL, 0) != pid) {
		fprintf(stderr, "fork error");
	}

	printf("parent finishes\n");
	return 0;
}

