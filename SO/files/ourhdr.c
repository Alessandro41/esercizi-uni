#include "ourhdr.h"
#include <stdarg.h> /* Per gestire argomenti multipli (...) in err_sys */
#include <string.h> /* Per strerror() */
#include <errno.h>  /* Per leggere il codice di errore del sistema (errno) */

/* * Variabili globali statiche (nascoste a chi usa la libreria).
 * Servono per salvare lo stato delle risorse tra "start" e "stop".
 */
static struct rusage usage_start;
static struct rusage usage_end;

/*
 * Implementazione di err_sys:
 * Prende una stringa formattata (come fa printf), la stampa sullo standard error,
 * aggiunge la vera motivazione dell'errore di sistema (es. "No such file or directory")
 * e infine "killa" il programma con exit(1).
 */
void err_sys(const char *fmt, ...) {
    va_list ap;
    
    // Inizializza la lista degli argomenti variabili
    va_start(ap, fmt);
    // Stampa il messaggio personalizzato del prof (es. "Open failed...")
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    
    // Stampa la motivazione tecnica del sistema operativo legata all'ultimo errore
    fprintf(stderr, ": %s\n", strerror(errno));
    
    // Termina brutalmente il programma (1 indica errore)
    exit(1);
}

/*
 * Implementazione di startCounting:
 * "Fotografa" le statistiche del processo in questo esatto istante.
 */
void startCounting(void) {
    getrusage(RUSAGE_SELF, &usage_start);
}

/*
 * Implementazione di stopCounting:
 * "Fotografa" le statistiche del processo dopo che ha lavorato.
 */
void stopCounting(void) {
    getrusage(RUSAGE_SELF, &usage_end);
}

/*
 * Implementazione di printResourceUsage:
 * Calcola la differenza matematica tra le due "fotografie" per capire 
 * quanto tempo è stato speso ESATTAMENTE in quel blocco di codice.
 */
void printResourceUsage(int who) {
    long user_sec, user_usec;
    long sys_sec, sys_usec;

    // Calcolo della differenza per il Tempo in User Mode (Il nostro codice)
    user_sec = usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec;
    user_usec = usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec;
    // Se i microsecondi sono negativi, "prendiamo in prestito" un secondo
    if (user_usec < 0) {
        user_sec--;
        user_usec += 1000000;
    }

    // Calcolo della differenza per il Tempo in Kernel Mode (Le System Call)
    sys_sec = usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec;
    sys_usec = usage_end.ru_stime.tv_usec - usage_start.ru_stime.tv_usec;
    // Stesso trucco dei microsecondi negativi
    if (sys_usec < 0) {
        sys_sec--;
        sys_usec += 1000000;
    }

    // Stampa a video
    printf("--> Risorse consumate in questo blocco:\n");
    printf("    Tempo User Mode   : %ld.%06ld secondi\n", user_sec, user_usec);
    printf("    Tempo Kernel Mode : %ld.%06ld secondi\n", sys_sec, sys_usec);
    printf("----------------------------------------\n\n");
}
