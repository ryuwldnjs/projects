#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int fileCount;
int dirCount;

void SearchDir(char *dir){
	DIR *dp;
	struct dirent *temp;
	struct stat buf;
	
	dp = opendir(dir);
	if(!dp) return;

	chdir(dir);

	while((temp = readdir(dp)) != NULL){
		lstat(temp -> d_name, &buf);
		if(S_ISDIR(buf.st_mode)){ // this is dir
			if(strcmp(".",temp->d_name)==0||strcmp("..", temp->d_name)==0)
				continue;
			
			dirCount++;
			SearchDir(temp->d_name);
		}
		else fileCount++; // this is file
	}
	chdir("..");
	closedir(dp);
}

int main(int argc, char *argv[]){

	SearchDir(argv[1]);

	printf("n file: %d\n",fileCount);

	printf("n dir: %d\n", dirCount+1);

}



		
