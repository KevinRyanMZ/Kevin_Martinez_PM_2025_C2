#include <stdio.h>
/* Archivos y caracteres.
El programa escribe caracteres en un archivo. */

int main(void)
{
    char p1;
    FILE *lol;

    lol = fopen("arc.txt", "w"); /* Se abre el archivo arc.txt para escritura. */

    if (lol != NULL)
    {
        printf("\nEscribe el contenido del archivo: ");
        while ((p1=getchar()) != '\n')
            /* Se escriben caracteres en el archivo mientras no se detecte el caracter que indica el fin de la línea. */

            fputc(p1, lol);
        fclose(lol); /* Se cierra el archivo. */
    }
    else
        printf("No se puede abrir el archivo");

        return 0;
}
