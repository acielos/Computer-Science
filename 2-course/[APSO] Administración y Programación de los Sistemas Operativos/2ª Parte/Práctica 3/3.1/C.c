#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    // Mostramos mensaje de bienvenida con los PID's de los procesos A y C
    printf("        Bienvenido al proceso C! Mi PID es %d, y el de mi padre es %d\n", getpid(), getppid());
    return 0;
}