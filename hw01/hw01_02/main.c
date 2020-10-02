#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	int fd;
	char buf[1024];
	off_t file_size;
	ssize_t nread;

	fd=open(argv[1], O_RDWR);
	file_size = lseek(fd, 0, SEEK_END);
	printf("%ld\n",file_size);
	
	lseek(fd, 0, SEEK_SET);
	nread = read(fd, buf, 1023);	
	buf[nread] = '\0';
	lseek(fd, 0, SEEK_SET);

	if(file_size % 2 == 0){
		for(int j =0; j<file_size; j+=2){
			buf[j]='e';
		}
	}
	else{
		for(int j=1;j<file_size;j+=2){
			buf[j]='o';
		}
	}
	write(fd, buf, file_size);
	return 0;	
}
		
	
			
			
