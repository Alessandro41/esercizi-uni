/*
Creare un file FILE1 contenente un buco '\0'
far stampare il contenuto del file col buco con "od -c" e "cat" (da fare nella bash)
copiare il contenuto di FILE1 in un FILE2 eliminando il buco
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define HOLE_SIZE 20

void main (void)
{
	int fd1, fd2;
	char buf[] = "Inserting text!";

	//creazione di FILE1
	fd1 = open("FILE1", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0) 
	{
		fprintf(stderr, "could not open the file");
		exit(0);
	}
	
	//scrittura del testo con buco in FILE1
	write(fd1, &buf, sizeof(buf) - 1);
	lseek(fd1, HOLE_SIZE, SEEK_CUR);
	write(fd1, &buf, sizeof(buf) - 1);
	
	//creazione di FILE2
	fd2 = open("FILE2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0) 
	{
		fprintf(stderr, "could not open the file");
		exit(0);
	}
	
	//copia di FILE1 in FILE2, ma senza buco
	lseek(fd1, SEEK_SET, 0);
	while (read(fd1, &buf, 1) > 0)
	{
		if (*buf != '\0')
			write(fd2, &buf, 1);
	}
	
	//chiusura dei file
	close(fd1);
	close(fd2);
	
	return;
}
