#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Variable para guardar cualquier aviso
int Permision = -1;

// Creamos la función para avisos de Alarma
void setPermitAla(){ Permision = 0; }

// Creamos función para avisos de A
void setPermitA(){ Permision = 1; }

// Creamos la función para avisos de C
void setPermitC(){ Permision = 2; }

int main(){

    // Escuchamos señal de la alarma
    signal(14, setPermitAla);

    // Escuchamos señal del proceso A
    signal(10, setPermitA);

    // Escuchamos señal del proceso C
    signal(12, setPermitC);

    // Variable para guardar PID del proceso C
    int pidC;

    // Mostramos mensaje de bienvenida
    printf("    Bienvenido al proceso B!\n");

    // Lanzamos el proceso C
    pidC = fork();
    if (pidC == 0)
    {
        execl("C", "C", NULL);
        perror("    Error en EXECL del proceso C...\n");
        exit(-1);
    }else if (pidC == -1)
    {
        perror("    Error en el fork de C...\n");
    }
    
    // Esperamos un segundo...
    sleep(1);

    // Enviamos una señal a A para que continúe
    kill(getppid(), 10);

    // Enviamos una señal a C para que comience
    kill(pidC, 12);

    // Generamos un número aleatorio entre 3 y 6
    srand(getpid());
    int aleB = rand() % 6 + 3;

    // Mostramos por pantalla el valor de aleB
    printf("    Número aleatorio del proceso B: %d\n", aleB);

    // Programamos una alarma con el valor de aleB
    alarm(aleB);

    // Esperamos a que algún proceso nos mande señal...
    while (Permision == -1)
    {
        printf("    Esperando...\n");
        sleep(1);
    }

    // Devolvemos el permiso
    return Permision;
}