#include <stdio.h>

/* Declaración de cadenas de caracteres y asignación de valores. */

void main(void)
{
    char *cad0;
    cad0 = "Argentina";
    puts(cad0);
    cad0 = "Brasil";
    puts(cad0);


    char cad1[50];
    printf("Ingrese una cadena para cad1: ");
    gets(cad1);
    puts(cad1);


    char cad2[20] = "Mexico";
    puts(cad2);
    printf("Ingrese una nueva cadena para cad2: ");
    gets(cad2);
    puts(cad2);


    cad2[10] = 'G';
    printf("Carácter en la posición 10 de cad2: %c\n", cad2[10]);
}
