/*
* Scrivere un programma C in cui un processo genera un processo figlio
* - il figlio scrive sullo standard output il proprio pid
* - solo successivamente, il padre scrive il proprio pid
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;
	int statloc;
	
	//crea processo figlio
	pid = fork();
	
	//se processo figlio
	if (pid==0) {
		fprintf(stdout, "PID figlio: %d\n", getpid());
		exit(0);
		//figlio finisce qui
	}
	
	//codice padre
	pid = wait(&statloc);
	fprintf(stdout, "Mio figlio %d ha appena terminato\n", pid);
	
	sleep(2);
	fprintf(stdout, "PID padre: %d\n", getpid());
	
	exit(0);
}
