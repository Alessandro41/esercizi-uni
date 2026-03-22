/*
usa le funzioni dup oppure dup2 per reindirizzare 
input e output per le funzioni getchar e putchar,
al fine di copiare il contenuto di FILE1 in FILE2
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void main (void)
{
	int fd1, fd2, i;
	int ch;
	
	//apertura di FILE1, ATTENZIONE: deve gia esistere
	fd1 = open("FILE1", O_RDONLY, 0644);
	if (fd1 < 0) 
	{
		fprintf(stderr, "could not open the file");
		exit(0);
	}
	
	//redirezione di stdin a FILE1, e chiusura di stdin
	dup2(fd1, STDIN_FILENO); //STDIN_FILENO = 0
	
	//creazione di FILE2
	fd2 = open("FILE2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0) 
	{
		fprintf(stderr, "could not open the file");
		exit(0);
	}
	
	//redirezione di stdout a FILE2, e chiusura di stdout
	dup2(fd2, STDOUT_FILENO); //STDOUT_FILENO = 1
		
	//copia da FILE1 a FILE2 usando solo getchar e putchar 	
	while ((ch = getchar()) != EOF) //senza le parentesi attorno a "ch = getchar()" non funziona.... dovuto alla implemetazione?
		putchar(ch);	
	
	/*
	ch = getchar();          //si puo fare anche in questo modo
	while (ch != EOF)
	{
		putchar(ch);
		ch = getchar();
	}
	*/
	
	//chiusura dei file
	close(fd1);
	close(fd2);
		
	return;
}
