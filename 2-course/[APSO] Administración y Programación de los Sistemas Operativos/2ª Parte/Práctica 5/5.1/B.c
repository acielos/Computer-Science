#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

// Variable y función para esperar permiso del proceso C
int permisionC = 0;
void setPermisionC(){ permisionC = 1; }

int main(){

    // Escuchamos las señales...
    signal(12, setPermisionC);

    // Variables para guardar los PIDs de los procesos B y C
    int pidB, pidC;

    // Abrimos la PIPE para leer el PID del proceso C
    int pipeAB = dup(2);

    // Leemos el PID del proceso C
    read(pipeAB, &pidC, sizeof(pidC));

    // Abrimos la FIFO para comunicar los procesos B y C
    int fifoBC = open("fifoBC", O_RDWR);

    // Mostramos el segundo mensaje
    printf("    Segundo Mensaje\n");

    // Avisamos al proceso C de que puede continuar
    kill(pidC, 12);

    // Esperamos a que el proceso C nos de permiso
    if (permisionC == 0)
    {
        pause();
    }
    permisionC = 0;     // "Reiniciamos" el permiso de C

    // Mostramos el quinto mensaje
    printf("    Quinto Mensaje\n");

    // Finalizamos el proceso B
    return 0;
}