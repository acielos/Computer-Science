#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función Leer
void Leer(int *lista, int *tamanno)
{
    int numero = 0, i = 0;

    printf("¡Se prodrán introducir un máximo de 10 número\n!");
    printf("En caso de querer salir, pulse -1\n");

    while (i < 10 && numero != -1)
    {
        printf("Introduzca un número: ");
        scanf("%d", &numero);
        if (numero != -1)
        {
            lista[i] = numero;
            i++;
        }
    }

    *tamanno = i;
    
}

// Función Calcular_Máximo
int Calcular_Maximo(int *lista, int *tamanno)
{
    int maximo;

    maximo = lista[0];

    for (int i = 0; i < tamanno; i++)
    {
        if (lista[i] > maximo)
        {
            maximo = lista[i];
        }
    }

    return maximo;
    
}

// Función Calcular_Seno
int Calcular_Seno(int numero)
{
    printf("El seno de %d es %f\n", numero, sin(numero));
    return 0;
}