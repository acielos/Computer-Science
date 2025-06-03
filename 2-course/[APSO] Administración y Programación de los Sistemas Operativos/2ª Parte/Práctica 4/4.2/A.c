#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Creamos la variable y función para avisos de B
int permitB = 0;
void setPermitB(){ permitB = 1; }

int main(){

    // Escuchamos señal de B
    signal(10, setPermitB);

    // Variable para guardar el PID del proceso B
    int pidB;

    // Mostramos mensaje de bienvenida
    printf("Bienvenido al proceso A!\n");

    // Lanzamos el proceso B
    pidB = fork();
    if (pidB == 0)
    {
        execl("B", "B", NULL);
        perror("Error en EXECL del proceso B...\n");
        exit(-1);
    }else if (pidB == -1)
    {
        perror("Error en el fork de B...\n");
    }
    
    // Esperamos la señal de B
    if (permitB == 0)
    {
        pause();
    }

    // Creamos un número aleatorio entre 2 y 5
    srand(getpid());
    int aleA = rand() % 5 + 2;

    // Mostramos por pantalla el número aleatorio
    printf("Número aleatorio del proceso A: %d\n", aleA);

    // Pausamos el programa el tiempo de valor de aleA
    sleep(aleA);

    // Enviamos una señal al proceso B
    kill(pidB, 10);

    // Creamos una variable para el resultado que nos manadará B
    int Permision;
    
    // Esperamos a que llegue el resultado
    wait(&Permision);

    // Comprobamos el resultado
    if (WIFEXITED(Permision))
    {
        if (WEXITSTATUS(Permision) == 1)
        {
            printf("Juego Abortado...\n");
        }
        if (WEXITSTATUS(Permision) == 2)
        {
            printf("Gano Yo\n");
        }
        if (WEXITSTATUS(Permision) == 3)
        {
            printf("Gana C\n");
        }
    }

    // Finalizamos el proceso A
    return 0;
}