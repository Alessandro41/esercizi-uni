#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int glob = 10; // dati inizializzati globalmente
int main(void) {
int var = 100; // variabile locale
pid_t pippo;
printf("prima della fork"); // modificata la stringa senza \n
pippo = fork();
if (pippo == 0) {
glob++;
var++;
}
else sleep(2);
printf("pid=%d, glob=%d, var=%d\n", getpid(), glob, var);
exit(0);
}
