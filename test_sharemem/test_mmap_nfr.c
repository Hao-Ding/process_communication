/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Mon 27 Jan 2014 07:34:22 PM CST
 * Filename		: test_mmap_nfr.c
 * Description	: mmap() with normal files (process to read) 
 * ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char **argv) {
	int fd, i;
	double *pdata;

	if ((fd = open(argv[1], O_CREAT | O_RDWR)) < 0) {
		fprintf(stderr, "open error\n");
		exit(1);
	}
	pdata = (double *)mmap(NULL, sizeof(double) * 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	for (i = 0; i < 10; i++) {
		printf("data %d = %lf\n", i, *(pdata + i));
	}
	munmap(pdata, sizeof(double) * 10);
	return 0;
}

