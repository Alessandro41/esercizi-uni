#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>


/**
*tests if the set-user-id flag in st_mode is set
*@param pathname 
*/
int main (int argc, char **argv) 
{
	if (argc != 2)
	{
		printf("Usage: %s <pathname>\n", *argv);
		exit(0);
	}
	
	struct stat buf;
	
	if(stat(argv[1], &buf) < 0) 
	{
		printf("Invalid pathname: %s\n", argv[1]);
		exit(0);
	} 
	
	if (buf.st_mode & S_ISUID)
		printf("flag is setted, effective = owner\n");
	else if (buf.st_mode & S_ISGID)
		printf("flag is setted, effective = owner's group\n");
	else
		printf("flag is not setted\n");
	
	return 0;
}
