/*
*Scrive un programma C che crei un nuovo processo con fork():
* - il figlio crea un file e scrive del testo usando le systemcall di sistema (open, write, close)
* - il pdre legge il contenuto del file e lo stampa nell standard out
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void) {
	pid_t pid;
		int fd;
	
	pid = fork();
	
	// codice figlio
	if (pid==0) {
		
	}
}
