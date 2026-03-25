#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <strl.h>

char buffer[100000];

int main (void) {
	int fd;
	char *f_name = "alfabeto.txt", str[] = "ABCDEFGHILMNOPQRSTUVZ";
	
	fd = open(f_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	printf("%d\n", sizeof(str));
	
	write(fd, str, sizeof(str));
	
	close(fd);
	
	fd = open(f_name, O_RDONLY);
	
	read(fd, &buffer, sizeof(str));
	
	for (int i = 0; buffer[i] != '\0'; i++) {
		printf("%c ", buffer[i]);
	}
	printf("\n");
	
	close(fd);
	
	exit(0);
}
