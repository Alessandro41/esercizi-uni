#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MY_R_OK = 0400
#define MY_W_OK = 0200
#define MY_X_OK = 0100
#define MY_F_OK = 0000

int my_access(const char *, int), choice;
const int myTests[4] = {MY_R_OK, MY_w_OK, MY_X_OK, MY_F_OK};
const mode_t tests[4] = {R_OK, W_OK, X_OK, F_OK};

/**
*program that simulates syscall access()
*@param pathname
*/
int main (int argc, char **argv) 
{
	if (argc != 2) {
		printf("Usage: %s <pathname>\n", *argv);
		exit(0);
	}
	
	if(access(argv[1], F_OK)) {
		printf("%s does not exist\n", argv[1]);
		exit(0);
	}
	
	while (1) {
		printf("chose test... type:\n1 -> test for read permission\n2 -> test for wtite permission\n3 -> test for execute permission\n 4 -> test for existence of file\n\t0 -> quit\n");
		scanf("%c", &choice);
		fflush(stdin);
		
		if (!(choice > 0 || choice < 5))
			return 0;
			
		printf("access() result: ");
		if(access(argv[1], tests[choice - 1]))
			printf("OK\n\n");
		else 
			printf("ERROR\n\n");
		
		printf("my_access() result: ");
		if(access(argv[1], myTests[choice - 1]))
			printf("OK\n\n");
		else 
			printf("ERROR\n\n");
	}
}	
	
/**
*actual function simulating syscall access()
*@param pathname
*@param my version of mode_t
*@return 0 if OK, -1 if there is an error
*/
int my access (const char *path, int mode) {
	struct stat buf;
	
	if (!lstat(path, &buf)) {
		if (!mode)
			return 0;
		if (mode & )
	 }
	 
	 return -1;
}

























	
	
	
	
