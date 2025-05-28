#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    // Variable para guardar el PID de la copia
    int pidBcop;

    // Mostramos mensaje de bienvenida y PID's de los procesos A y B
    printf("    Bienvenido al proceso B! Mi PID es %d, y el de mi padre es %d\n", getpid(), getppid());

    // Lanzamos la copia del proceso B
    pidBcop = fork();
    if (pidBcop == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            // Lanzamos el mensaje del proceso B copia
            printf("        Soy el proceso B-Copia, mi PID es %d, y el de mi padre es %d\n", pidBcop, getpid());
            sleep(1);
        } 
    }

    // Realizamos tres iteraciones para mostrar el mensaje solicitado
    for (int i = 0; i < 3; i++)
    {
        printf("    Soy el proceso B, mi PID es %d, y el de mi copia es %d\n", getpid(), pidBcop);
        sleep(1);
    }

    // Finalizamos el proceso B
    return 0;
}