#include <stdio.h>
#include <stdlib.h>
#define Menu_Ninguno 0
#define Menu_Salir 1
#define Menu_Sumar 2
#define Menu_Dividir 3

int main()
{
    int menu = Menu_Ninguno;
    float n1 = 0.0, n2 = 0.0, result = 0.0;
    do
    {
     printf("\n1-Salir\n2-Suman\n3-Dividir\n");
     scanf("%i", &menu);

     if (menu == Menu_Sumar)
     {
         printf("\nPrimer Sumando: ");
         scanf("%f", &n1);
         printf("\nSegundo Sumando: ");
         scanf("%f", &n2);

         result = n1+n2;
         printf("\nEl Resultado de la operacion %f + %f es: %f", n1, n2, result);
     }
     if (menu == Menu_Dividir)
     {
         printf("\nDividendo: ");
         scanf("%f", &n1);
         printf("\nDivisor: ");
         scanf("%f", &n2);

         result = n1/n2;
         printf("\nEl Resultado de la operacion %f / %f es: %f", n1, n2, result);
     }
      if (menu >= 3){ printf("Operacion no valida"); }






    }while(menu != Menu_Salir);

    return 0;
}
