#include <stdio.h>

// Creamos la variable y la función para la señal del proceso A (señal 12)
int permitA = 0;

void setPermitA(){ permitA = 1; }

// Creamos la variable y la función para la señal de la alarma (señal 14)
int permitAla = 0;

void setPermitAla(){ permitAla = 1; }

int main(){

    // Escuchamos la señal del proceso A
    signal(10, setPermitA);

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
    alarm(3);
    

    // Finalizamos el proceso B
    return 0;
}