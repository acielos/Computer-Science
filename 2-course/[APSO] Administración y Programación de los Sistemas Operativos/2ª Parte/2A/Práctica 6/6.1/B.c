#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/types.h>

// Creamos la estructura para la cola
struct Mensaje
{
    long tipo;
    int dato;
};

int main(){

    // Declaramos las variables que usaremos
    int nAle, tAle, idCola;

    // Preparamos la generación de números aleatorios
    srand(getpid());

    // Creamos la variable para la clave de la cola
    key_t clave;

    // Variables donde guardaremos los datos para la cola
    struct Mensaje mensaje;

    // Generamos la clave de la cola
    clave = ftok("./makefile", 33);

    // Comprobamos que se haya generado la clave correctamente
    if (clave == (key_t)-1)
    {
        perror("    FAIL: Error al obtener la clave de la cola de mensajes (B)...\n");
        exit(-1);
    }

    // Obtenemos el ID de la cola (comprobamos si existe o la creamos)
    idCola = msgget(clave, 0600 | IPC_CREAT);

    // Comprobamos que la cola esté abierta
    if (idCola == -1)
    {
        perror("    FAIL: Error al obtener el identificador de la cola...\n");
        exit(-1);
    }

    // Escribimos los datos en la cola (numeros aleatorios)
    for (int i = 0; i < 10; i++)
    {
        // Generamos el numero aleatorio que enviaremos
        nAle = rand() % 100 + 1;

        // Generamos el tiempo aleatorio para la pausa
        tAle = rand() % 3 + 1;

        // Guardamos en 'mensaje' el dato generado y el tipo (proceso) que lo manda
        mensaje.tipo = 1;
        mensaje.dato = nAle;

        // Hacemos pausa
        sleep(tAle);

        // Mandamos el mensaje por la cola, si falla... ERROR
        if (msgsnd(idCola, (struct msgbuf *)&mensaje, sizeof(mensaje) - sizeof(long), IPC_NOWAIT) == -1)
        {
            perror("    FAIL: No se puede enviar a la cola de mensajes (B)...\n");
            exit(-1);
        }
    }
    
    // Terminamos el proceso B
    return 0;
}