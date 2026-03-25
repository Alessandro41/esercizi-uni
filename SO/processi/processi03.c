/*
* Scivi un programma C che:
* 1. crea due processi figli a partire dal processo padre usando fork();
* 2. il primo processo figlio esegue un calcolo matematico (ad esempio, somma due numeri) e aggiorna una variabile locale
* 3. il processo padre attende che il primo figlio termini, poi crea il secondo figlio.
* 4. il secondo processo figlio legge il valore della variabile globale e lo utilizza per eseguire un'ulteriore operazione
* 5. ogni processo deve stampare il proprio PID e il risultato calcolato
* 6. il processo padre attende che entrambi i figli terminimo, poi stampa un messaggio di conferma
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int glob = 5;

int main (void) {
	pid_t pid1, pid2;
	int status;
	
	// creazione primo figlio
	pid1 = fork();
	
	//codice primo figlio
	if (pid1 == 0) {
		glob += 5;
		printf("Figlio 1: aggiungo 5 alla a glob: %d\n", glob);
		exit(0);
	}

	// padre aspetta primo figlio e da conferma
	if (wait(&status) == pid1)	
		printf("Figlio 1 bene, con stato %d\n", pid1);
		
	// creazione secondo figlio
	pid2 = fork();	
	
	//codice secondo figlio
	if (pid2 == 0) {
		glob = glob * 3;
		printf("Figlio 1: moltiplica glob per 3: %d\n", glob);
		exit(0);
	}
	
	// padre aspetta secondo figlio e da conferma
	if (wait(&status) == pid2)	
		printf("Figlio 2 bene, con stato %d\n", pid2);
		
	return 0;
}
