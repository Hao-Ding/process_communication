/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Mon 27 Jan 2014 08:06:36 PM CST
 * Filename		: test_mmap_anonymous.c
 * Description	: mmap() with anonymous file 
 * ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(int argc, char **argv) {
	int i;
	pid_t pid;
	double *pdata = (double *)mmap(NULL, sizeof(double) * 10, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1 ,0);
	if ((pid = fork()) ==0 ) { // child process
		sleep(2);
		for (i = 0; i < 5; i++) {
			printf("The child reads %lf\n", *(pdata + i));
		}
	}
	else {
		for (i = 0; i < 5; i++) {
			*(pdata + i) = i * 100;
			printf("parent writes %lf\n", (double)i * 100);
		}
	}
	munmap(pdata, sizeof(double) * 10);
	printf("unmap ok\n");
	return 0;
}

