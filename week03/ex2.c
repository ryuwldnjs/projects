#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd, n;
	off_t start, cur;
	char buf[256];

	fd = open("unix.txt", O_RDONLY);

	start = lseek(fd, 0, SEEK_CUR);
	n = read(fd, buf, 255);
	buf[n] = '\0';
	printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n);
	cur = lseek(fd, 0, SEEK_CUR);
	printf("Offset cur=%d\n", (int)cur);

	start = lseek(fd, 5, SEEK_SET);
	n = read(fd, buf, 255);
	buf[n] = '\0';
	printf("Offset start=%d, Read Str=%s", (int)start, buf);

	close(fd);
	return 0;
}
