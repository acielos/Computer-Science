#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/msg.h>

// Primero crearemos la estructura que usaremos para la cola
struct Cola
{
    long tipo;
    int dato;
};

int main(){

    // Declaramos las variables para guardar los PID's de los procesos B y C
    int pidB, pidC;

    // Declaramos las variables necesarias para:
    // Guardar el id de la Cola
    int idCola;

    // Guardar información de las dos colas
    int colaB, colaC;

    // Declaramos el identificador de la cola
    key_t clave;

    // Declaramos las colas de los procesos B y C
    struct Cola mensajeB, mensajeC;

    // Obtenemos la clave de la cola de mensajes
    clave = ftok("./makefile", 33);
    if (clave == (key_t)-1)
    {
        perror("Error al obtener la clave de la cola de mensajes\n");
        exit(-1);
    }

    // Abrimos la cola de mensajes
    idCola = msgget(clave, 0666 | IPC_CREAT);
    if (idCola == -1)
    {
        perror("Error al obtener el identificador de la cola de mensajes\n");
        exit(-1);
    }

    // Lanzamos el proceso B
    pidB = fork();
    if (pidB == 0)
    {
        execl("B", "B", NULL);
        perror("Error en el EXECL del proceso B\n");
        exit(-1);
    }else if (pidB == -1)
    {
        printf("Error en el FORK del proceso B\n");
    }

    // Lanzamos el proceso C
    pidC = fork();
    if (pidC == 0)
    {
        execl("C", "C", NULL);
        perror("Error en el EXECL del proceso C\n");
        exit(-1);
    }else if (pidC == -1)
    {
        printf("Error en el FORK del proceso C\n");
    }

    // Mostramos los números de las colas por pantalla
    int contador = 0;
    while (contador < 10)
    {
        // Comprobación del nº de mensajes mostrados por pantalla
        printf("Mensaje nº %d\n\n", contador);
        
        // Mensajes de la cola del proceso B
        colaB = msgrcv(idCola, (struct msgbug *)&mensajeB, sizeof(mensajeB) - sizeof(long), 1, 0);

        // Comprobamos que no haya errores en la lectura de mensajes 
        if (colaB == -1)
        {
            perror("No se pueden recibir mensajes de la cola de mensajes\n");
        }
        
        printf("Proceso B: %d\n", mensajeB.dato);

        // Mensajes de la cola del proceso C
        colaC = msgrcv(idCola, (struct msgbug *)&mensajeC, sizeof(mensajeC) - sizeof(long), 1, 0);

        // Comprobamos que no haya errores en la lectura de mensajes 
        if (colaC == -1)
        {
            perror("No se pueden recibir mensajes de la cola de mensajes\n");
        }
        
        printf("Proceso C: %d\n", mensajeC.dato);
    }

    // Eliminamos la cola de mensajes // mostramos mensaje de error
    if (msgctl(idCola, IPC_RMID, (struct msgid_ds *)NULL) == -1)
    {
        perror("No se puede eliminar la cola de mensajes\n");
        exit(-1);
    }
    
    // Finalizamos el proceso A
    return 0;
}