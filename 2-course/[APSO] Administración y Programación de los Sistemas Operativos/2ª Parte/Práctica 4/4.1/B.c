#include <stdio.h>

// Creamos la variable y la función para la señal del proceso A (señal 10)
int permitA = 0;

void setPermitA(){ permitA = 1; }

int main(){

    // Escuchamos la señal del proceso A
    signal(10, setPermitA);

    // Esperamos a la señal del proceso A
    if (permitA == 0)
    {
        pause();
    }
    permitA = 0;
    
    // Mostramos el segundo mensaje
    printf("    Segundo mensaje\n");

    // Envíamos la señal al proceso A
    kill(getppid(), 10);

    // Esperamos a la señal del proceso A
    if (permitA == 0)
    {
        pause();
    }
    permitA = 0;

    // Mostramos el quinto mensaje
    printf("    Quinto mensaje\n");

    // Envíamos la señal al proceso A
    kill(getppid(), 10);

    // Finalizamos el proceso B
    return 0;
}