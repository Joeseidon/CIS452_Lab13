#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc, char *argv[]){
	if(argc < 3){
		perror("Not Enough Arguments");
		exit(0);
	}

	if(argc > 4){
		perror("Too Many Arguments");
		exit(0);
	}
	
	if(argc == 3){
		//create hard link
		
	}else{
		//for 4 arguments, create symbolic link
		if(!(strcmp(argc[1],"-s") == 0)){
			perror("For Four Arguments, Flag Must be -s");
			exit(0);
		}
	}	
}
