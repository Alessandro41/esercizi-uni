/*
Prendere l'input da tastiera e inseriscilo in FILE1
copiare FILE1 in FILE2 in ordine inverso
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void main (void)
{
	int fd1, fd2;
	char buf;
	off_t offset;
	
	//creazione di FILE1
	fd1 = open("FILE1", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0) 
	{
		fprintf(stderr, "could not open the file");
		exit(0);
	}
	
	//lettura da tastiera e scrittura in FILE1
	do
	{
		read(0, &buf, 1);
		write(fd1, &buf, 1);
	} while (buf != '\n');
	
	//creazione di FILE2
	fd2 = open("FILE2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0) 
	{
		fprintf(stderr, "could not open the file");
		exit(0);
	}
	
	//copia inversa di FILE1 in FILE2
	lseek(fd1, 0, SEEK_END);
	while(1) 
	{
		offset = lseek(fd1, -2, SEEK_CUR);
		if (offset < 0)
			break;
		read(fd1, &buf, 1);
		write(fd2, &buf, 1);
	}
	
	//chiusura dei file
	close(fd1);
	close(fd2);
	
	return;
}
