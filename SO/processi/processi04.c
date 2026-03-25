/*
* creare tre prcessi figli, ciascun figlio esegue un compito diverso:
* 1. il primo figlio termina normalmente con un codice di uscita specifico
* 2. il secondo figlio tenta di accedere a un'area di memoria non valida e genera un errore
* 3. il terzo figlio ora simula un'operazione che richiede del tempo (sleep()) e dopo che il tempo è scaduto, termina normalmente con codice di uscita specifico
* Il processo padre attende la terminazione di ciascun figlio, verifica come sono terminati e stampa le informazioni dettagliate sullo stato di ciascun processo figlio
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void wait_son (int numero_figlio, pid_t pid_figlio);

int main (void) {
	pid_t pid1, pid2, pid3;
	int *p = NULL; // serve a creare l'errore in F2
	char vect[10] = {0};
	
	// piccola prova personale per vedere come inizializza vect
	for (int i = 0; i < 10; i++)
		printf("%d ", vect[i]);
	printf("\n");
	
	// crea primo figlio
	pid1 = fork();
	
	// codice primo figlio
	if (pid1 == 0) {
		printf("F1: sono pacifico e termino con codice 1\n");
		exit(1);
	}
	
	// padre aspetta primo figlio
	wait_son(1, pid1);
	
	// crea secondo figlio
	pid2 = fork();
	
	// codice secondo figlio
	if (pid2 == 0) {
		printf("Figlio 2: ora faccio una pazzia\n");
		vect[999999999] = 1; // operazione illegale, int -> *int
		exit(0); // non verrà mai eseguita, in quanto il SO termina F2 per l'errore sopra
	}
	
	// padre aspetta primo figlio
	wait_son(2, pid2);
	
	// crea terzo figlio
	pid3 = fork();
	
	// codice terzo figlio
	if (pid3 == 0) {
		printf("Figlio 3; ci metterò un pò\n");
		sleep(5);
		printf("Figlio 3: ok ho finito, usciro con stato 0\n");
		exit(0);
	}
	
	// padre aspetta primo figlio
	wait_son(3, pid3);
	
	return 0;
	
}

void wait_son(int pn, pid_t pid) {

	int status;

	if (wait(&status) == pid) {
		printf("P: F%d ha finito .. ", pn);
		if (WIFEXITED(status)) {
			printf("in modo 'normale' con status: %d\n", WEXITSTATUS(status));
		} else {
			printf("con un errore generato dal segnale: %d\n", WTERMSIG(status));
			printf("\tvalore di WIFSIGNALED(): %d", WIFSIGNALED(status));
			printf("\tvalore di WEXITSTATUS(): %d\n", WEXITSTATUS(status));
		}
	} else {
		printf("P: Errore nell'attesa di P%d. Status: %d\n",pn, status);
	}

}


