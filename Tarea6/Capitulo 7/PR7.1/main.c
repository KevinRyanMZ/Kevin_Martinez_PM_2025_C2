#include <stdio.h>
/* Funciones para el manejo de caracteres de la biblioteca stdio.h */
int main(void)
{
char p1, p2, p3 = '$';

printf("\nIngrese un caracter: ");
p1 = getchar();
putchar(p1);
printf("\n");
fflush(stdin);

printf("\nEl caracter p3 es: ");
putchar(p3);

printf("\n");
printf("\nIngrese otro caracter: ");
p2 = getchar();
scanf("%c", &p2);

printf("%c", p2);
fflush(stdin);

return 0;
}
