#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){

    // Declaramos las variables que vamos a utilizar
    int opc, lista[10], tamanno = 0;

    // Creamos el bucle que contendrá el menú
    do
    {
        printf("\n");
        printf("1. Leer datos\n");
        printf("2. Visualizar máximo\n");
        printf("3. Calcular seno del máximo\n");
        printf("4. Salir\n");
        printf("Seleccione: ");
        scanf("%i", &opc);

        // Una vez seleccionada, realizamos la acción indicada
        switch (opc)
        {
        case 1:
            printf("\n");
            printf("Opción seleccionada: Leer datos\n");
            Leer(lista, &tamanno);

            // Mostramos por pantalla los datos introducidos
            printf("Has introducido %d números: \n", tamanno);
            for (int i = 0; i < tamanno; i++)
            {
                printf("%d\t", lista[i]);
            }
            printf("\n");
            break;
        case 2:
            printf("\n");
            printf("Opción seleccionada: Visualizar máximo\n");
            printf("El valor máximo introducido es: %i\n", Calcular_Maximo(lista, &tamanno));
            break;
        case 3:
            printf("\n");
            printf("Opción seleccionada: Calcular seno del máximo\n");
            int maximo = Calcular_Maximo(lista, &tamanno);
            printf("El seno del máximo es: %i\n", Calcular_Seno(maximo));
            break;
        
        default:
            break;
        }
    } while (opc != 4);
    
    // Terminamos le programa
    return 0;
}