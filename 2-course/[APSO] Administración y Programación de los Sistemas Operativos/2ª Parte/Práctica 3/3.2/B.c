#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    // Variable para guardar el PID del proceso C
    int pidC;

    // Mostramos mensaje de bienvenida
    printf("    Bienvenido al proceso B!\n");

    // Generamos un número aleatorio entre 1 y 10
    srand(getpid());            // Inicializamos srand() y le damos como semilla el PID del proceso B
    int nAle = rand() % 10 + 1;  // Generamos el número aleatorio en la variable nAle

    char cadena[3];
    snprintf(cadena, 3, "%d", nAle);

    // Lanzamos el proceso C, pasándole el número aleatorio como parámetro
    pidC = fork();
    if (pidC == 0)
    {
        execl("C", "C", cadena, NULL);
        perror("    Error en EXECL del proceso C\n");
        exit(-1);
    }

    // Mostramos los PID's de los procesos A, B y C
    printf("    PID del proceso A: %d\n", getppid());
    printf("    PID del proceso B: %d\n", getpid());
    printf("    PID del proceso C: %d\n", pidC);

    // Esperamos un segundo y finalizamos
    sleep(1);

    // Finalizamos el proceso
    return 0;
}