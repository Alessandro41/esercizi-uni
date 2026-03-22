#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void printStatus(struct stat*);

/**
*check file status with stat() and lstat()
*@param pathname
*/
int main (int argc, char **argv) 
{
	if (argc != 2) {
		printf("Usage: %s <pathname>", *argv);
		exit(0);
	}
	
	struct stat buf;
	
	//print status obtained with stat()
	if(stat(argv[1], &buf)) {
		printf("Invalid pathname: %s\n", argv[1]);
		exit(0);
	}
	printStatus(&buf);
	
	//print status obtained with lstat()
	if(stat(argv[1], &buf)) {
		printf("Invalid pathname: %s\n", argv[1]);
		exit(0);
	}
	printStatus(&buf);
	
	return 0;
}


/**
*prints file status 
*@param struct status
*/
void printStatus (struct status *buf) 
{
	
}




