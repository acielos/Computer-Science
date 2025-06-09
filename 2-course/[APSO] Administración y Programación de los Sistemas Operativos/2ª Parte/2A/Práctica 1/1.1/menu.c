#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){

    // Declaramos las variables para guardar los coeficientes
    int a, b, c;

    // Declaramos la variable para guardar la selección del menu
    int opc = 0;

    // Menú
    do
    {
        // Opciones del menú
        printf("\n");
        printf("1. Leer coeficientes\n");
        printf("2. Visualizar ecuación\n");
        printf("3. Calcular raíces\n");
        printf("4. Salir\n");
        printf("Selecciona: \n");

        // Guardamos la selección
        scanf("%i", &opc);

        // En base a la opción seleccionada...
        switch (opc)
        {
        case 1:
            printf("Opción seleccionada: Leer coeficientes\n");
            Leer(&a, &b, &c);
            break;

        case 2:
            printf("Opción seleccionada: Visualizar ecuación\n");
            Visualizar_Ecuacion(a, b, c);
            break;

        case 3:
            printf("Opción seleccionada: Calcular raíces\n");
            Calcular_Raices(a, b, c);
            break;

        default:
            break;
        }
    } while (opc != 4);
    
    // Finalizamos el programa
    return 0;
}