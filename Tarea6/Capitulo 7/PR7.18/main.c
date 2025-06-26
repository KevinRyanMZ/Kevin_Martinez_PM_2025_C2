#include <stdio.h>
#include <string.h>

/* Cadena invertida recursivamente */

void inverso(char *);

void main(void)
{
    char fra[50];
    printf("\nIngrese la línea de texto: ");
    fgets(fra, sizeof(fra), stdin);
    fra[strcspn(fra, "\n")] = '\0';

    printf("\nEscribe la línea de texto en forma inversa: ");
    inverso(fra);
    printf("\n");
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
