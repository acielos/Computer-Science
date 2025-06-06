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

    // Abrimos la FIFO
    int fifoAC = open("FIFOAC", O_WRONLY);

    // Preparamos la semilla para generar números aleatorios
    srand(getpid());

    // Declaramos variable para guardar los números aleatorios
    int ale;

    // Generamos los números aleatorios y los mandamos
    for (int i = 0; i < 5; i++)
    {
        ale = rand() % 5 + 1;
        write(fifoAC, &ale, sizeof(ale));
    }

    // Esperamos comunicación del resultado
    if (resultado == 0)
    {
        pause();
    }

    if (resultado == 10)
    {
        printf("        Proceso B Perdedor!\n");
        printf("        Proceso C Ganador!\n");
        printf("\n");
    }else if (resultado == 12)
    {
        printf("        Proceso B Ganador!\n");
        printf("        Proceso C Perdedor!\n");
        printf("\n");
    }else if (resultado == 15)
    {
        printf(" ");
    }
    

    // Mostramos mensaje de finalización
    printf("        Proceso C finalizado...\n");
    
    // Finalizamos el proceso C
    return 0;
}