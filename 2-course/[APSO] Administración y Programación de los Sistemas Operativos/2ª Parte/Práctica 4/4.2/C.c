#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Creamos la variable y función para avisos de B
int permitB = 0;
void setPermitB(){ permitB = 1; }

int main(){

    // Escuchamos señal de B
    signal(12, setPermitB);

    // Generamos un número aleatorio entre 2 y 5
    srand(getpid());
    int aleC = rand() % 5 + 2;

    // Mostramos por pantalla el número aleatorio
    printf("        Número aleatorio del proceso C: %d\n", aleC);

    // Hacemos el sleep
    sleep(aleC);

    // Enviamos una señal al proceso B para informar
    kill(getppid(), 12);

    // Finalizamos el proceso C
    return 0;
}