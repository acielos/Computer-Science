#include <stdio.h>

int main(){
    // Variables para guardar el PID de los procesos B y C
    int pidB, pidC;

    // Creamos el proceso B
    pidB = fork();
    if(pidB == 0){
        execl("B", "B", NULL);
        perror("Error en el EXECL del proceso B\n");
        exit(-1);
    }

    // Creamos el proceso C
    pidC = fork();
    if(pidC == 0){
        execl("C", "C", NULL);
        perror("Error en el EXECL del proceso C\n");
        exit(-1);
    }

    // Esperamos un segundo
    sleep(1);

    // Mostramos el primer mensaje
    printf("Primer mensaje\n");

    // Mostramos el último mensaje
    printf("Último mensaje\n");

    // Finalizamos el proceso A
    return 0;
}