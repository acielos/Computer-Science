#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Creamos la variable y la función para la señal del proceso A (señal 12)
int permitA = 0;

void setPermitA(){ permitA = 1; }

// Creamos la variable y la función para la señal de la alarma (señal 14)
int permitAla = 0;

void setPermitAla(){ permitAla = 1; }

int main(){

    // Escuchamos la señal del proceso A
    signal(12, setPermitA);

    // Escuchamos la señal de la alarma
    signal(14, setPermitAla);

    // Esperamos la señal del proceso A
    if (permitA == 0)
    {
        pause();
    }
    permitA = 0;

    // Mostramos el tercer mensaje
    printf("        Tercer mensaje\n");

    // Establecemos una alarma de 3 segundos
    alarm(3);       // Señal nº4

    // Esperamos la señal de la alarma...
    while (!permitAla)
    {
        printf("        Esperando Alarma...\n");
        sleep(1);
    }
    
    // Mostramos el cuarto mensaje
    printf("        Cuarto mensaje\n");

    // Envíamos señal al proceso A
    kill(getppid(), 12);        // Señal nº5

    // Finalizamos el proceso C
    return 0;
}