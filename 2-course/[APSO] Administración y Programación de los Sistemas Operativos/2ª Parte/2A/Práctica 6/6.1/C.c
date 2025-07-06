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

    // Preparamos para generar numeros aleatorios
    srand(getpid());

    // Declaramos la variable para la clave de la cola
    key_t clave;

    // Declaramos la variable (tipo Mensaje) para enviar por la cola
    struct Mensaje mensaje;

    // Generamos la clave de la cola
    clave = ftok("./makefile", 33);

    // Comprobamos que la clave se haya generado correctamente
    if (clave == (key_t)-1)
    {
        perror("    FAIL: Error al obtener la clave de la cola de mensajes (C)...\n");
        exit(-1);
    }

    // Obtenemos el ID de la cola (creamos o abrimos)
    idCola = msgget(clave, 0600 | IPC_CREAT);

    // Comprobamos que el ID sea válido
    if (idCola == -1)
    {
        perror("    FAIL: Error al obtener el identificador de la cola de mensajes...\n");
        exit(-1);
    }

    // Vamos a enviar mensajes por la cola...
    for (int i = 0; i < 10; i++)
    {
        nAle = (rand() % 100 + 1) * (-1);
        tAle = rand() % 3 + 1;
        mensaje.tipo = 2;
        mensaje.dato = nAle;
        sleep(tAle);

        if (msgsnd(idCola, (struct msgbuf *)&mensaje, sizeof(mensaje) - sizeof(long), IPC_NOWAIT) == -1)
        {
            perror("    FAIL: No se puede enviar a la cola de mensajes (C)...\n");
        }
    }
    
    // Finalizamos el proceso C
    return 0;
}