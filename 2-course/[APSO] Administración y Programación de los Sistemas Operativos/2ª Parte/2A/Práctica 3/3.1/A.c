#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    // Variables para guardar los PID's de los procesos B y C
    int pidB, pidC;

    // Mostramos mensaje de bienvenida
    printf("Bienvenido al proceso A! Mi pid es %d\n", getpid());

    // Lanzamos el proceso B
    pidB = fork();
    if (pidB == 0)
    {
        execl("B", "B", NULL);
        perror("Error en el execl del proceso B\n");
        exit(-1);
    }

    // Lanzamos el proceso C
    pidC = fork();
    if (pidC == 0)
    {
        execl("C", "C", NULL);
        perror("Error en el execl del proceso C\n");
        exit(-1);
    }

    // Damos una pausa a la ejecución
    sleep(1);

    // Mostramos los PID's de los procesos B y C
    printf("El PID del proceso B es: %d\n", pidB);
    printf("El PID del proceso C es: %d\n", pidC);

    // Damos una pausa de 4 segundos
    sleep(4);

    // Finalizamos el programa
    return 0;
}