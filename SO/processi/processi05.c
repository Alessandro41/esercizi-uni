/*
* Programma C che crea 3 figli usando fork(); ogni processo figlio eseguirà un compito diverso:
* 1. Figlio 1: dato un path indicato da linea di comando, esegue l'istruzione ls + opzioni
* 2. Figlio 2: mostra il percorso assoluto della directory corrente usando pwd
* 3. Figlio 3: visualizza data ed ora usando date
* I figli cercheranno i rispettivi programmi nella variabile PATH di sistema, cosa possibile grazie alla 'p' della execlp();
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	pid_t pid;
	char *options_ls[2] = {"ls", NULL};
	options_ls[1] = argv[1];
	
	pid = fork();
	
	// codice figlio 1
	if (pid==0) {
		printf("Output F1:\n\t");
		fflush(stdout); // rende visibile \t dopo il \n, che altrimenti rimarrebbe nel buffer
		if(execlp("ls", "ls", argv[1], NULL) == -1)
			fprintf(stderr, "Exec fallita\n");
		exit(0); // se va tutto bene non viene eseguita
	}
	
	// aspetta prima di contunuare
	wait(NULL);
	
	pid = fork();
	
	// codice figlio 2
	if (pid==0) {
		printf("Output F2:\n\t");
		fflush(stdout); // rende visibile \t dopo il \n, che altrimenti rimarrebbe nel buffer
		if(execlp("pwd", "pwd", NULL) == -1)
			fprintf(stderr, "Exec fallita\n");
		exit(0); // se va tutto bene non viene eseguita
	}
	
	// aspetta prima di contunuare
	wait(NULL);
	
	pid = fork();
	
	// codice figlio 3
	if (pid==0) {
		printf("Output F3:\n\t");
		fflush(stdout); // rende visibile \t dopo il \n, che altrimenti rimarrebbe nel buffer
		if(execlp("date", "date", NULL) == -1)
			fprintf(stderr, "Exec fallita\n");
		exit(0); // se va tutto bene non viene eseguita
	}
	
	// aspetta prima di contunuare
	wait(NULL);
}
