#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
El programa, al recibir como dato un arreglo unidimensional de tipo
cadena de caracteres, determina el número de minúsculas y mayúsculas que hay en cada cadena. */

void minymay(char *cad);  // Corregido: el parámetro debe ser puntero

void main(void)
{
    int i, n;
    char FRA[20][50];
    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    fflush(stdin);

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto: ", i + 1);
        gets(FRA[i]);
    }

    printf("\n\n");
    for (i = 0; i < n; i++)
        minymay(FRA[i]);
}

void minymay(char *cadena)
{
    int i = 0, mi = 0, ma = 0;
    while (cadena[i] != '\0')  // Comillas corregidas
    {
        if (islower(cadena[i]))
            mi++;
        else if (isupper(cadena[i]))
            ma++;
        i++;
    }
    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
}
