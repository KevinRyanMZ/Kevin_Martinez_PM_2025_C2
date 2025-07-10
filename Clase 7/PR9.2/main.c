#include <stdio.h>
/* Archivos y caracteres.
El programa lee caracteres de un archivo. */

void main(void)
{
    char p1, p2;
    int i, a;
    char Contenido[40];
    FILE *ar;
    FILE *ar2;
    if ((ar = fopen("C:\\Users\\Public\\arc.txt", "r")) != NULL)
    {
        i = 0;
        while (!feof(ar))

        {

            p1 = fgetc(ar);
            putchar(p1);
            Contenido[i++] = p1;

        }
        fclose(ar);

    }

    else
    {
        printf("No se puede abrir el archivo de lectura");
    }
    a = i;
    i = 0;

    if ((ar2 = fopen("C:\\Users\\Public\\arc2.txt", "w")) != NULL)
    {
        while (i != a)
        {

            fputc(Contenido[i++], ar2);


        }
    }
    else
    {
        printf("No se puede abrir el archivo de escritura");
    }
}

