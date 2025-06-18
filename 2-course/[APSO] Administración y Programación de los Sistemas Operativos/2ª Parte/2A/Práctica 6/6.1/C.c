#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

// Primero crearemos la estructura que usaremos para la cola
struct Cola
{
    long tipo;
    int dato;
};

int main(){

    // Declaramos las variables para el tiempo aleatorio, numero aleatorio y 
    // para guardar el ID de la cola de mensajes
    int nAle, tAle, idCola;

    // Declaramos el identificador de la cola
    key_t clave;

    // Declaramos la cola para añadir mensajes
    struct Cola mensajeC;

    // Creamos la semilla para generar números aleatorios
    srand(getpid());

    // Obtenemos la clave de la cola de mensajes
    clave = ftok("makefile", 33);

    // Comprobamos que la clave sea correcta
    if (clave == (key_t)-1)
    {
        perror("    Error al obtener la clave de la cola de mensajes\n");
        exit(-1);
    }

    // Abrimos la cola de mensajes y obtenemos su identificador
    idCola = msgget(clave, 0600 | IPC_CREAT);
    if (idCola == -1)
    {
        perror("    Error al obtener el identificador de la cola de mensajes\n");
        exit(-1);
    }

    // Generamos los números aleatorios y los escribimos en la cola
    for(int i = 0; i < 10; i++)
    {
        nAle = rand() % 100 + 1;            // Generamos número aleatorio entre 1 y 100
        tAle = rand() % 3 + 1;              // Generamos número aleatorio entre 1 y 3 para la pausa
        mensajeC.tipo = 2;                  // Declaramos que este dato viene del proceso C
        mensajeC.dato = nAle;
        sleep(tAle);                        // Pausa de tiempo aleatorio

        // Escribimos los números en la cola
        msgsnd(idCola, (struct msgbug*)&mensajeC, sizeof(mensajeC) - sizeof(long), 2);
    }

    // Finalizamos el proceso B
    return 0;
}