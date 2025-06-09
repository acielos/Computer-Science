#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

int main(){

    // Creamos las variables para guardar los PIDs de los procesos B y C
    int pidB, pidC;

    // Abrimos la PIPE para comunicar A y B
    int PIPE[2];
    pipe(PIPE);

    /*
        En la PIPE hay dos "extremos", PIPE[0] y PIPE[1], de esta manera cada
        uno de ellos sirve para una cosa, por lo que daremos a un proceso acceso
        a uno y a otro proceso acceso a otro, dependiendo de lo que queramos conseguir:
            - PIPE[0] -> Lectura
            - PIPE[1] -> Escritura
    */

    // Creamos la FIFO para comunicar B y C
    mkfifo("fifoBC", 0666);

    // Creamos el proceso B
    pidB = fork();
    if (pidB == 0)
    {
        close(2);
        dup(PIPE[0]);       
        execl("B", "B", NULL);
        perror("Error en el EXECL del proceso B\n");
        exit(-1);
    }else if (pidB == -1)
    {
        perror("Error en el FORK del proceso B\n");
    }

    // Creamos el proceso C
    pidC = fork();
    if (pidC == 0)
    {
        execl("C", "C", NULL);
        perror("Error en el EXECL del proceso C\n");
        exit(-1);
    }else if (pidC == -1)
    {
        perror("Error en el FORK del proceso B\n");
    }

    // Esperamos un segundo
    sleep(1);

    // Escribimos en la PIPE el PID del proceso C
    write(PIPE[1], &pidC, sizeof(pidC));

    // Mostramos el primer mensaje
    printf("Primer mensaje\n");

    // Esperamos a que terminen los procesos B y C
    wait(NULL);
    wait(NULL);

    // Mostramos el último mensaje
    printf("Último mensaje\n");

    // Cerramos la fifo
    unlink("fifoBC");
    // Finalizamos el proceso A
    return 0;
}