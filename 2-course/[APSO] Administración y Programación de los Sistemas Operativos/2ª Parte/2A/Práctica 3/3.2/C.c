#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "C.h"

int main(int argc, char *argv[]){

    // Mostramos mensaje de bienvenida
    printf("        Bienvenido al proceso C!\n");

    // Mostramos los PID's de los procesos B y C
    printf("        PID del proceso B: %d\n", getppid());
    printf("        PID del proceso C: %d\n", getpid());

    // Mostramos el número pasado como parámetro
    printf("        El número pasado como parámetro es: %s\n", argv[1]);

    // Finalizamos el proceso
    return 0;
}