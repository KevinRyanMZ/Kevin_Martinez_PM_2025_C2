#include <stdio.h>
/* Rango de calificaciones.
El programa, al recibir como dato una serie de calificaciones, obtiene
el rango en el que se encuentran.*/

void Rango(int);
int RA1 = 0, RA2 = 0, RA3 = 0, RA4 = 0, RA5 = 0;


void main(void)
{
    float CAL;
    printf("Ingresa la primera calificación del alumno: ");
    scanf("%f", &CAL);
    while (CAL != -1)
    {
        Rango(CAL); /* Llamada a la función Rango. Se pasa un parámetro
por valor. */
        printf("Ingresa la siguiente calificación del alumno: ");
        scanf("%f", &CAL);
    }
    printf("\n0..3.99 = %d", RA1);
    printf("\n4..5.99 = %d", RA2);
    printf("\n6..7.99 = %d", RA3);
    printf("\n8..8.99 = %d", RA4);
    printf("\n9..10 = %d", RA5);
}
void Rango(int VAL)
/* La función incrementa una variable dependiendo del valor del
➥ parámetro VAL. */
{
    if (VAL < 4)
        RA1++;
    else if (VAL < 6)
        RA2++;
    else if (VAL < 8)
        RA3++;
    else if (VAL < 9)
        RA4++;
    else
        RA5++;
}
