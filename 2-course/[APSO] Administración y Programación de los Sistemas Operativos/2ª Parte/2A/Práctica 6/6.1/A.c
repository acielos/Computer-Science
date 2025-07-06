#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>

// Creamos la estructura para la Cola
struct Mensaje
{
    long tipo;      // Nos servirá para identificar de que proceso viene el mensaje
    int dato;       // El dato que enviará el proceso
};

int main(){

    // Declaramos las variables que usaremos
    int pidB, pidC, idCola, colaVaciaB, colaVaciaC;

    // Generamos la variable para la clave de la cola
    key_t clave;

    // Creamos las variables donde guardaremos los mensajes enviados por la cola
    struct Mensaje mensajeB, mensajeC;

    // Generamos la clave para la cola; Necesitaremos un archivo existente y un "identificador" (el que queramos)
    clave = ftok("./makefile", 33);

    // Comprobamos que la generación de la clave se haya hecho de manera correcta
    if (clave == (key_t)-1)
    {
        perror("FAIL: Error al obtener la clave de la cola de mensajes...\n");
        exit(-1);
    }

    // Creamos o abrimos la cola de mensajes
    idCola = msgget(clave, 0600 | IPC_CREAT);

    // Comprobamos que la cola se haya creado / abierto correctamente
    if (idCola == -1)
    {
        perror("FAIL: Error al obtener el identificador de la cola de mensajes...\n");
        exit(-1);
    }

    // Lanzamos el proceso B
    pidB = fork();
    if (pidB == 0)
    {
        execl("B", "B", NULL);
        perror("FAIL: Error en el EXECL del proceso B...\n");
        exit(-1);
    }else if (pidB == -1)
    {
        perror("FAIL: Error en el FORK del proceso B...\n");
        exit(-1);
    }

    // Lanzamos el proceso C
    pidC = fork();
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

    // Leemos de la cola de mensajes
    int contador = 0;
    while (contador < 10)
    {
        // Damos forma...
        printf("Nº de Generación... %d\n", contador + 1);
        
        /*
        Leemos de la cola de mensajes (B)
            colaVaciaB: Donde guardaremos los datos leidos de la cola
            msgrcv(): Función que usamos para recibir de la cola (leemos)
            idCola: Identificador de la cola donde vamos a leer
            (struct msbuf *)&mensajeB: Puntero a la estructura donde guardaremos el dato
            sizeof(mensajeB) - sizeof(long): Quitamos el 'long tipo' de lo que queremos guardar
            1: Identificamos que viene del proceso B
            0: La llamada es bloqueante, esperamos hasta que haya algo que leer
        */
        colaVaciaB = msgrcv(idCola, (struct msbuf *)&mensajeB, sizeof(mensajeB) - sizeof(long), 1, 0);

        // Comprobamos que no haya errores en la lectura de la cola (B)
        if (colaVaciaB == -1)
        {
            perror("FAIL: No se puede recibir de la cola de mensajes (B)...\n");
        }

        // Mostramos por pantalla el dato que hemos leido
        printf("Número generado por B: %d\n", mensajeB.dato);

        // Al igual que antes... pero cambiamos el identificador de 1 a 2
        colaVaciaC = msgrcv(idCola, (struct msbuf *)&mensajeC, sizeof(mensajeC) - sizeof(long), 2, 0);

        // Comprobamos que no haya errores en la lectura de la cola (C)
        if (colaVaciaC == -1)
        {
            perror("FAIL: No se puede recibir de la cola de mensajes (C)...\n");
        }

        // Mostramos por pantalla el dato que hemos leido
        printf("Número generado por C: %d\n", mensajeC.dato);

        // Damos espacio...
        printf("\n");

        contador += 1;
    }

    // Cerramos la cola, si no podemos mostramos un mensaje de error
    if (msgctl(idCola, IPC_RMID, NULL) == -1)
    {
        perror("FAIL: No se puede cerrar la cola de mensajes...\n");
        exit(-1);
    }
    
    // Terminamos el proceso A
    return 0;
}
