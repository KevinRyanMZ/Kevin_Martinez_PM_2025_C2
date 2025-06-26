#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cuentap(char *);

void main(void)
{
    int i;
    char fra[50];
    printf("\nIngrese la línea de texto: ");
    fgets(fra, sizeof(fra), stdin);
    fra[strcspn(fra, "\n")] = '\0';

    i = cuentap(fra);
    printf("\nLa línea de texto tiene %d palabras\n", i);
}

int cuentap(char *cad)
{
    int i = 0, palabras = 0;
    int en_palabra = 0;

    while (cad[i] != '\0')
    {
        if (!isspace(cad[i]) && !en_palabra)
        {
            en_palabra = 1;
            palabras++;
        }
        else if (isspace(cad[i]))
        {
            en_palabra = 0;
        }
        i++;
    }

    return palabras;
}
