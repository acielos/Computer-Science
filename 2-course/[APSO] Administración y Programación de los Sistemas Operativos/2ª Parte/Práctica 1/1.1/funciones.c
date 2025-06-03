#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Leer(int *a, int *b, int *c)
{
    // Primero mostraremos la forma de la ecuación
    printf("Sea una función cuadrática de la forma: a^(2)X + bX + c...\n");

    // A continuación procedemos a solicitar los coeficientes
    printf("Introduzca el coeficiente 'a': \n");
    scanf("%d", a);
    printf("Introduzca el coeficiente 'b': \n");
    scanf("%d", b);
    printf("Introduzca el coeficiente 'c': \n");
    scanf("%d", c);
}

void Visualizar_Ecuacion(int a, int b, int c)
{
    // Mostramos la ecuación
    printf("La ecuación introducida es: \n");
    printf("%dX^2", a);
    printf(" %dX", b);
    printf(" %d", c);
    printf("\n\n");
}

void Calcular_Raices(int a, int b, int c)
{
    // Primero comprobaremos que a y b sean positivos
    if (a == 0)
    {
        if (b != 0)
        {
            printf("La raíz es: %f\n", -c/(float)b);
        }else
        {
            printf("No es una ecuación...\n");
        }
        
    }else
    {
        // Calculamos la parte interior de la raíz
        float inRaiz = b * b -4 * a * c;

        // Comprobamos que sea posible hallar la raíz
        if (inRaiz < 0)
        {
            printf("No es posible realizar el cálculo\n");
        }else
        {
            float r1 = (-b + sqrt(inRaiz) / 2 * a);
            float r2 = (-b - sqrt(inRaiz) / 2 * a);
            printf("Las raíces son: %f, %f\n", r1, r2);
        }
    } 
}