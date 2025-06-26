#include <stdio.h>
#include <string.h>

int cuenta(char *);

void main(void)
{
    int i;
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);
    cad[strcspn(cad, "\n")] = '\0';

    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d", i);
}

int cuenta(char *cadena)

{
    int c = 0;
    while (cadena[c] != '\0')
        c++;
    return c;
}
