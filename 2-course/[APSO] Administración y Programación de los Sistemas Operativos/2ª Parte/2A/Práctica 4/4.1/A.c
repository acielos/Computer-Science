#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/*
    Para el desarrollo de esta práctica, incluiremos un concepto nuevo, las "signals"
    Estas señales las usaremos para la comunicación entre procesos, de manera que un proceso
    hijo pueda comunicar al proceso padre que ha realizado una acción, de manera que
    el padre pueda seguir realizando otro tipo de acciones.

    De la misma manera, podrán comunicarse procesos que no sean padre-hijo.

    Podemos definir un pequeño "esquema" de señales

    A -> B (Señal nº 1): Primer mensaje
    B -> A (Señal nº 2): Segundo mensaje
    A -> C (Señal nº 3): Tercer mensaje
    C -> C (Señal nº 4): Esperando alarma...
    C -> A (Señal nº 5): Cuarto mensaje
    A -> B (Señal nº 6): Quinto mensaje
    B -> A (Señal nº 7): Último mensaje
 */

// Creamos la variable y la función para la señal del proceso B (señal 10)
int permitB = 0;

void setPermitB(){ permitB = 1; }

// Creamos la variable y la función para la señal del proceso C (señal 12)
int permitC = 0;

void setPermitC(){ permitC = 1; }

int main(){

    // Escuchamos señales 10 y 12
    signal(10, setPermitB);
    signal(12, setPermitC);

    // Variables para guardar el PID de los procesos B y C
    int pidB, pidC;

    // Creamos el proceso B
    pidB = fork();
    if(pidB == 0){
        execl("B", "B", NULL);
        perror("Error en el EXECL del proceso B\n");
        exit(-1);
    }else if (pidB == -1)
    {
        perror("Error de fork para B...\n");
    }

    // Creamos el proceso C
    pidC = fork();
    if(pidC == 0){
        execl("C", "C", NULL);
        perror("Error en el EXECL del proceso C\n");
        exit(-1);
    }else if (pidC == -1)
    {
        perror("Error de fork para C...\n");
    }
    

    // Esperamos un segundo
    sleep(1);

    // Mostramos el primer mensaje
    printf("Primer mensaje\n");

    // Envíamos una señal al proceso B
    kill(pidB, 10);     // Señal nº1

    // Esperamos a que el proceso B nos mande una señal para seguir
    if (permitB == 0)
    {
        pause();
    }
    permitB = 0;

    // Envíamos una señal al proceso C
    kill(pidC, 12);     // Señal nº3

    // Esperamos a que el proceso C nos mande una señal para seguir
    if (permitC == 0)
    {
        pause();
    }
    permitC = 0;

    // Envíamos una señal al proceso B
    kill(pidB, 10);     // Señal nº6

    // Esperamos a que el proceso B nos mande una señal para seguir
    if (permitB == 0)
    {
        pause();
    }
    permitB = 0;

    // Esperamos a que los procesos B y C terminen por completo
    wait(NULL);
    wait(NULL);

    // Mostramos el último mensaje
    printf("Último mensaje\n");

    // Finalizamos el proceso A
    return 0;
}