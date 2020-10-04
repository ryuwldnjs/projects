#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int newfd, newfd2;
	int fd;

	fd = open("unix.txt", O_RDWR);

	newfd = dup(fd);
	newfd2 = dup2(fd, 10);

	printf("FD : (%d)\n", fd);
	printf("Duplicate FD: (%d), (%d)\n", newfd, newfd2);
	close(fd);
	close(newfd);
	close(newfd2);

	return 0;
}
