#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

int main(){

    // Variable para PID del proceso B
    int pidB;

    /*
        En la PIPE hay dos "extremos", PIPE[0] y PIPE[1], de esta manera cada
        uno de ellos sirve para una cosa, por lo que daremos a un proceso acceso
        a uno y a otro proceso acceso a otro, dependiendo de lo que queramos conseguir:
            - PIPE[0] -> Lectura
            - PIPE[1] -> Escritura
    */

    // Creamos la pipe PIPE
    int PIPE[2];
    pipe(PIPE);

    // Creamos la fifo FIFOAC
    mkfifo("FIFOAC", 0666);

    // Lanzamos el proceso B
    pidB = fork();
    if (pidB == 0)
    {
        close(2);
        dup(PIPE[1]);
        execl("B", "B", NULL);
        perror("Error en el EXECL del proceso B\n");
        exit(-1);
    }else if (pidB == -1)
    {
        perror("Error en el FORK del proceso B\n");
        exit(-1);
    }

    // Creamos los arrays para leer los números
    int listaB[5], listaC[5];

    // Abrimos la FIFO para leer
    int fifoAC = open("FIFOAC", O_RDONLY);

    // Damos forma a lo mostrado por pantalla
    printf("\n");
    printf("Recibiendo números...\n");

    // Leemos los números dados por los procesos B y C
    for (int i = 0; i < 5; i++)
    {
        read(PIPE[0], &listaB[i], sizeof(int));
        printf("Número %d, mandado por el proceso B\n", listaB[i]);
        read(fifoAC, &listaC[i], sizeof(int));
        printf("Número %d, mandado por el proceso C\n", listaC[i]);
        printf("\n");
        sleep(1);
    }

    // Declaramos variables para guardar las medias
    int mediaB = 0, mediaC = 0;

    // Calculamos la suma de cada array
    for (int i = 0; i < 5; i++)
    {
        mediaB += listaB[i];
        mediaC += listaC[i];
    }

    // Calculamos la media de cada array
    mediaB /= 5;
    mediaC /= 5;

    // Mostramos la media por pantalla
    printf("Media de los números enviados por B: %d\n", mediaB);
    printf("Media de los números enviados por C: %d\n", mediaC);
    printf("\n");

    // Comparamos cuál es mayor y lo comunicamos a B
    if (mediaB > mediaC)
    {
        kill(pidB, 10);
    }else if (mediaB < mediaC)
    {
        kill(pidB, 12);
    }else if ( mediaB == mediaC)
    {
        printf("La media de ambos procesos es IGUAL\n");
        printf("\n");
        kill(pidB, 15);
    }

    // Esperamos a que finalice el proceso B
    wait(NULL);

    // Mensaje de finalización
    printf("Proceso A finalizado...\n");

    // Cerramos la FIFO
    unlink("FIFOAC");

    // Finalizamos el proceso A
    return 0;
}