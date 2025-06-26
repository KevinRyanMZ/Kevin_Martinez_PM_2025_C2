#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Decodifica.
El programa decodifica una cadena de caracteres compuesta por números y letras. */

void interpreta(char *);

void main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);
    cad[strcspn(cad, "\n")] = '\0';
    interpreta(cad);
}

void interpreta(char *cadena)

{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))
        {
            k = cadena[i - 1] - '0';
            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
    printf("\n");
}
