#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Necesaria para strcspn

/* Suma y promedio.
El programa, al recibir como datos varias cadenas de caracteres que
contienen reales, los suma y obtiene el promedio de los mismos. */

void main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();
    while (getchar() != '\n');

    while (c == 'S')
    {
        printf("\nIngrese la cadena de caracteres: ");
        fgets(cad, sizeof(cad), stdin);
        cad[strcspn(cad, "\n")] = '\0';

        i++;
        sum += atof(cad);

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
        while (getchar() != '\n');
    }
    printf("\nSuma: %.2f", sum);
    printf("\nPromedio: %.2f", sum / i);
}
