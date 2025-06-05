#include <stdio.h>
//Obtiene el numero colocado por el operador y busca sus numeros primos
// a travez de bucles

int main()
{
    int NUM;
    int esPrimo = 0;
    printf("Introduce un número entero positivo: ");
    scanf("%d", &NUM);

    if (NUM <= 2)
    {
        printf("No hay números primos menores que %d.\n", NUM);
        return 0;
    }

    printf("Números primos menores que %d:\n", NUM);
    printf("2 ");
    for (int i = 2; i < NUM; i++)     //Empieza a probar valores por debajo de NUM
    {
                // asume que i es primo
        for (int j = 2; j * j <= i; j++)   //calcula los numeros que su cuadrado sea menor a (i)
        {
            //(los numeros factoriales menores a la raiz un numero son los mismos que los factores siguientes esta raiz solo que invertidos)

            if (i % j == 0) //busca a ver si dividir (i) entre ese factor deja algun residuo
            {
                esPrimo = 0; // no es primo
                break;
            }

            if (i % j != 0) //busca a ver si dividir (i) entre ese factor deja algun residuo
            {
                esPrimo = 1; // no es primo
                break;
            }

        }
        if (esPrimo)
        {
            printf("%d ", i);
        }
    }

    printf("\nfin\n");
    return 0;
}
