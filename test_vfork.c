/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Sun 26 Jan 2014 10:29:57 PM CST
 * Filename		: test_vfork.c
 * Description	: An example of vfork 
 * ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	pid_t pid;

	printf("before vfork\n");

	if ((pid = vfork()) < 0) {
		fprintf(stderr, "vfork error\n");
		exit(1);
	}
	else if (pid == 0){
		printf("child\n");
		 _exit(0);
		// exit(0); In p146, APUE, exit(0) is said unsafe for the parent process, but actually it depends on the kernel. 
	}
	printf("%d\n", printf("parent\n"));
	return 0;
}

