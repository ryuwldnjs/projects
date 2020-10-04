#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){
	struct stat buf;

	stat("ex3.c", &buf);
	printf("Mode = %o\n", (unsigned int)buf.st_mode);
	
	printf("ex3.c : ");
	if((buf.st_mode & S_IRUSR) != 0) printf("user/");
	if((buf.st_mode & S_IRGRP) != 0) printf("group/");
	if((buf.st_mode & S_IROTH) != 0) printf("other ");
	
	printf("have a read permission\n");
	return 0;
}
