/*
* preso in input un N da CLI, restituisce la somma 1+2+..+N;
* la somma è realizzata da un thread figlio, per poi esser stampata dal padre.
*/

#include <pthread.h> /*includiamo la Pthread API*/
#include <stdio.h>

#include <stdlib.h>

int sum; /*questo dato è condiviso tra i thread*/
void *runner(void *param); /*i thread invocano questa funzione*/

int main (int argc, char *argv[])
{
	pthread_t tid; /*l'identificatore del thread*/
	pthread_attr_t attr; /*insieme di attributi di un thread*/
	
	/*imposta gli attributi default del thread*/
	pthread_attr_init(&attr);
	/*crea il thread*/
	pthread_create(&tid, &attr, runner, argv[1]);
	/*aspetta la terminazione del thread*/
	pthread_join(tid, NULL);
	
	printf("sum = %d\n", sum);
}

/*Ogni thread eseguirà questa funzione*/
void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;
	
	for (i=1; i <= upper; i++)
		sum += i;
	
	pthread_exit(0);
}
