#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    // Variable para guardar el PID del proceso B
    int pidB;

    // Mostramos mensaje de bienvenida
    printf("Bienvenid@ al proceso A!\n");

    // Lanzamos el proceso B
    pidB = fork();
    if (pidB == 0)
    {
        execl("B", "B", NULL);
        perror("Error en el EXECL del proceso B\n");
        exit(-1);
    }

    // Mostramos PID's de los procesos A y B
    printf("PID del proceso A: %d\n", getpid());
    printf("PID del proceso B: %d\n", pidB);

    // Esperamos un segundo
    sleep(1);

    // Finalizamos el proceso
    return 0;
}