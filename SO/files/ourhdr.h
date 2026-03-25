#ifndef OURHDR_H
#define OURHDR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>

/* Prototipi delle funzioni custom del professore */

/* Stampa l'errore di sistema e termina il programma */
void err_sys(const char *fmt, ...);

/* Fa partire il "cronometro" delle risorse */
void startCounting(void);

/* Ferma il "cronometro" delle risorse */
void stopCounting(void);

/* Calcola la differenza e stampa i risultati */
void printResourceUsage(int who);

#endif
