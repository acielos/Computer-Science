#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

// Variable y función para esperar permiso del proceso B
int permisionB = 0;
void setPermisionB(){ permisionB = 1; }

// Variable y función para esperar permiso de la alarma
int permisionAl = 0;
void setPermisionAl(){ permisionAl = 1; }

int main(){

    // Escuchamos las señales...
    signal(12, setPermisionB);
    signal(14, setPermisionAl);

    // Variables para guardar el PID del proceso B
    int pidB;

    // Esperamos a que el proceso B nos de permiso
    while (permisionB == 0)
    {
        pause();
    }
    permisionB = 0;     // "Reiniciamos" el permiso de B

    // Mostramos el tercer mensaje
    printf("        Tercer Mensaje\n");

    // Establecemos alarma de 3 segundos
    alarm(3);

    // Esperamos fin de la alarma
    while (!permisionAl)
    {
        printf("        Esperando Alarma...\n");
        sleep(1);
    }
    
    // Mostramos el cuarto mensaje
    printf("        Cuarto Mensaje\n");

    // Abrimos la FIFO para comunicar los procesos B y C
    int fifoBC = open("fifoBC", O_RDONLY);

    // Leemos el PID del proceso B
    read(fifoBC, &pidB, sizeof(pidB));

    // Avisamos al proceso B de que puede continuar
    kill(pidB, 12);

    // Finalizamos el proceso B
    return 0;
}