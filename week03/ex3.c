#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int rfd, wfd, n;
	char buf[10];

	rfd = open("unix.txt", O_RDONLY);

	wfd = open("unix.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	while((n = read(rfd, buf, 6)) > 0){
		write(wfd, buf, n);
	}

	close(rfd);
	close(wfd);
	return 0;
}
