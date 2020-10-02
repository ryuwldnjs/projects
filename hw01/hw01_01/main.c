#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	int fd;
	char string[100];

	if((fd = open("printf.txt" , O_CREAT | O_RDONLY | O_WRONLY, 0644)) <0){
		exit(1);
	}
	
	scanf("%s",string);
	dup2(fd,1);
	printf("%s",string);

	return 0;
}
