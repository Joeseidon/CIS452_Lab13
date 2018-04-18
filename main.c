#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int mode;	
	struct stat statData;
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
		mode = 0;
	}else{
		
		//for 4 arguments, create symbolic link
		mode = 1;
		if(!(strcmp(argv[1],"-s") == 0)){
			perror("For Four Arguments, Flag Must be -s");
			exit(0);
		}
	}	

	//attempt to read file information
	if(stat(argv[mode+1], &statData) < 0){
		perror("Unable to get Stat information");
		exit(1);
	}

	if(link(argv[mode+1],argv[mode+2])<0){
		perror("Enabled to create hard lin");
		exit(0);
	}
	
	return 0;
}
