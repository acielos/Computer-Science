#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

// Variable y funciones para esperar señal de resultado
int resultado = 0;
void setWinner(){ resultado = 10; }
void setLoser(){ resultado = 12; }
void setFinal(){ resultado = 15; }

int main(){

    // Escuchamos las señales...
    signal(10, setWinner);
    signal(12, setLoser);
    signal(15, setFinal);

    // Variable para guardar el PID del proceso C
    int pidC;

    // Abrimos la PIPE
    int pipeAB = dup(2);

    // Lanzamos el proceso C
    pidC = fork();
    if (pidC == 0)
    {
        execl("C", "C", NULL);
        perror("    Error en el EXECL del proceso C\n");
        exit(-1);
    }else if (pidC == -1)
    {
        perror("    Error en el FORK del proceso C\n");
        exit(-1);
    }

    // Preparamos la semilla para generar números aleatorios
    srand(getpid());

    // Variable para guardar los números aleatorios
    int ale;

    // Generamos y escribimos los 5 números aleatorios
    for (int i = 0; i < 5; i++)
    {
        ale = rand() % 5 + 1;
        write(pipeAB, &ale, sizeof(ale));
    }

    // Esperamos a que nos informen del resultado
    while (resultado == 0)
    {
        pause();
    }

    if (resultado == 10)
    {
        kill(pidC, 12);
    }else if (resultado == 12)
    {
        kill(pidC, 10);
    }else if (resultado == 15)
    {
        printf(" ");
        kill(pidC, 15);
    }

    // Esperamos a que C termine...
    wait(NULL);

    // Mensaje de finalización
    printf("    Proceso B finalizado...\n");
    
    // Finalizamos el proceso B
    return 0;
}