#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>

// Preparamos la estructura para los mensajes
struct Mensaje
{
    long tipo;
    int dato;
};

int main(){

    // Declaramos la variable para la clave de la cola
    key_t clave;

    // Declaramos la variable (tipo Mensaje) para los mensajes de la cola
    struct Mensaje mensaje;

    // Preparamos para generar números aleatorios
    srand(getpid());

    // Generamos la clave para la cola de mensajes
    clave = ftok("./makefile", 33);

    // Comprobamos que la clave se haya geenrado correctamente
    if (clave == (key_t)-1)
    {
        perror("FAIL: Error al obtener la clave de la cola de mensajes...\n");
        exit(-1);
    }

    // Obtenemos el ID de la cola (abrimos o creamos)
    int idCola = msgget(clave, 0600 | IPC_CREAT);

    // Comprobamos que hayamos obtenido correctamente el ID de la cola
    if (idCola == -1)
    {
        perror("FAIL: Error al obtener el identificador de la cola de mensajes...\n");
        exit(-1);
    }

    // Bucle para escribir en la cola de mensajes
    for (int i = 0; i <= 5; i++)
    {
        // 'Descansamos' un tiempo aleatorio
        sleep(rand() % 3 + 1);

        // Guardamos el tipo de mensaje para la cola
        mensaje.tipo = i;

        // Guardamos el numero para enviar
        mensaje.dato = i;

        // Enviamos toda la información a la cola
        if (msgsnd(idCola, (struct msgbug *)&mensaje, sizeof(mensaje) - sizeof(long), 0) == -1)
        {
            perror("FAIL: Error al enviar a la cola de mensajes...\n");
        }
        
    }

    // Finalizamos el proceso C
    return 0;
}