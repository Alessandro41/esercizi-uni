/*
* Programma che genera n interi casuali, poi:
* - li scrive in un file;
* - li rilegge;
* - li stampa a video, 6 per linea,
*
*/

#include <stdio.h>        /* Per usare printf() */
#include <stdlib.h>       /* Per usare atoi(), malloc(), e random() */
#include <unistd.h>       /* Per le system call POSIX: read(), write(), close() */
#include <fcntl.h>        /* Per la system call open() e le costanti O_WRONLY, O_CREAT, O_TRUNC, O_RDONLY */
#include <sys/resource.h> /* Per la costante RUSAGE_SELF passata a printResourceUsage() */
#include "ourhdr.h"

//Viene dichiarato un array globale k di 10 milioni di interi.
int k[10000000];


int main(int argc,char*argv[]) {

	//Viene dichiarato n con un valore di default 10. Se viene fornito un argomento da riga di comando,
	//n assume il valore convertito da stringa a intero (atoi(argv[1])).
	int n=10;
	if(argc>1){
		n = atoi(argv[1]);
	}
	//Un buffer di dimensione n viene allocato dinamicamente per memorizzare gli interi.
	int *buffer = malloc(n*sizeof(int));
	//Viene stampato l'indirizzo del buffer allocato e dell'array k
	printf("0x%x,0x%x\n",buffer,k);

	int fd;

	for(int i=0;i<n;i++){
		 buffer[i]=random();
	}

//Apertura del File per Scrittura
	char *filename="prova.bin";
//Il file prova.bin viene aperto per la scrittura (O_WRONLY) e se non esiste, viene creato (O_CREAT).
	//Se il file esiste già, viene troncato (O_TRUNC).
//I permessi di creazione sono impostati a 0666, che consente la lettura e la scrittura per tutti gli utenti.
//startCounting() inizia una misurazione.
	startCounting();
	if((fd=open(filename,O_WRONLY | O_CREAT | O_TRUNC , 0666)) < 0){
		err_sys("Open failed %s",filename);
	}

//Scrittura nel File (Iterativa)
	for(int i=0;i<n;i++){
		if(write(fd,&buffer[i],sizeof(int)) < 0){
			err_sys("Write failed %d",buffer);
		}
	}
	//stopCounting() ferma la misurazione e printResourceUsage() stampa l'uso delle risorse per questa operazione.
	stopCounting();
	printResourceUsage(RUSAGE_SELF);

	close(fd);

//Apertura del File per Lettura
	if((fd=open(filename,O_RDONLY)) < 0){
			err_sys("Open failed %s",filename);
	}
//	Lettura dal File (Iterativa)
//Vengono letti n interi dal file e memorizzati nel buffer. La lettura avviene un intero alla volta.
//	Dopo la lettura, stopCounting() e printResourceUsage() vengono chiamati per misurare e stampare l'uso delle risorse.
	startCounting();
	for(int i=0;i<n;i++){
		if(read(fd,&buffer[i],sizeof(int)) < 0){
			err_sys("Read failed %d",buffer);
		}
	}
	stopCounting();
	printResourceUsage(RUSAGE_SELF);


	printf("Inizio test con una sola chiamata a write/read\n");


	startCounting();
	if((fd=open(filename,O_WRONLY | O_CREAT | O_TRUNC , 0666)) < 0){
		err_sys("Open failed %s",filename);
	}


	if(write(fd, buffer, sizeof( buffer)) < 0){
		err_sys("Write failed %d", buffer);
	}
	stopCounting();
	printResourceUsage(RUSAGE_SELF);

	close(fd);


	if((fd=open(filename,O_RDONLY)) < 0){
			err_sys("Open failed %s",filename);
	}


	startCounting();

	if(read(fd, buffer,sizeof(int)) < 0){
		err_sys("Read failed %d", buffer);
	}
	stopCounting();
	printResourceUsage(RUSAGE_SELF);

	close(fd);
//Stampa dei Numeri (6 per Linea)
	for(int i=0;i<n;i++){
		printf("%10d  ", buffer[i]);
		if (i % 6 == 0)
			printf("\n");
	}

	printf("\n");
}

