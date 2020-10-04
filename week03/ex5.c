#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int val;
	int fd;

	fd = open("unix.txt", O_RDWR);
	
	val = fcntl(fd, F_GETFL, 0);
	switch(val & O_ACCMODE){
		case O_RDONLY:
			printf("read only\n");
			break;
		case O_WRONLY:
			printf("write only\n");
			break;
		case O_RDWR:
			printf("read write\n");
			break;
	}
	close(fd);
	return 0;
}
