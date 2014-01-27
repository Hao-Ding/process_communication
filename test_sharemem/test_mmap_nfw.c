/********************************************************
 * Author		: Hao Ding
 * Email		: mail2haoding@gmail.com
 * Created Time	: Mon 27 Jan 2014 07:25:26 PM CST
 * Filename		: test_mmap_nfw.c
 * Description	: mmap() with normal files (process to write) 
 * ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char **argv) {
	int fd, i;
	double *pdata;
	double temp = 100;

	if ((fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 00777)) < 0) {
		fprintf(stderr, "open error\n");
		exit(1);
	}
	lseek(fd, 0, SEEK_SET);
	write(fd, "", 1);
	if ((pdata = (double *)mmap(NULL, sizeof(double) * 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) < 0) {
		fprintf(stderr, "mmap error\n");
		exit(1);
	}

	close(fd);
	
	for (i = 0; i < 10; i++) {
		temp += 100;
		*(pdata + i) = temp;
	}

	printf("write finish\n");
	sleep(10);

	munmap(pdata, sizeof(double) * 10);
	printf("unmap ok\n");
	return 0;
}

