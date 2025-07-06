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

    // Lanzamos el proceso C
    int pidC = fork();
    if (pidC == 0)
    {
        execl("C", "C", NULL);
        perror("FAIL: Error en el EXECL del proceso C...\n");
        exit(-1);
    }else if (pidC == -1)
    {
        perror("FAIL: Error en el FORK del proceso C...\n");
        exit(-1);
    }

    // Bucle para leer los números de la cola de mensajes
    for (int i = 1; i <= 5; i++)
    {
        // Leemos cada dos segundos...
        sleep(2);

        // Tratamos de leer de la cola de mensajes de A, si no… Error
        if (msgrcv(idCola, (struct msgbuf *)&mensaje, sizeof(mensaje) - sizeof(long), (long)i, IPC_NOWAIT) != -1)
        {
            printf("    A pone a tiempo el %i\n", i);
        }else
        {
            printf("    A NO pone a tiempo el %i\n", i);
        }

        if (msgrcv(idCola, (struct msgbuf *)&mensaje, sizeof(mensaje) - sizeof(long), (long)i, IPC_NOWAIT) != -1)
        {
            printf("    C pone a tiempo el %i\n", i);
        }else
        {
            printf("    C NO pone a tiempo el %i\n", i);
        }
    }
    
    // Esperamos a que el proceso C finalice...
    wait(NULL);

    // Cerramos la cola o mostramos ERROR si no podemos
    if (msgctl(idCola, IPC_RMID, NULL) == -1)
    {
        perror("FAIL: Error al eliminar la cola de mensajes...\n");
        exit(-1);
    }

    // Finalizamos el proceso B
    return 0;
}