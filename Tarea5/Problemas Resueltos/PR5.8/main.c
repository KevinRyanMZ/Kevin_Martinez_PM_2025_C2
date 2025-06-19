#include <stdio.h>

/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100 números
primos. */

const int TAM = 100;
void Imprime(int[], int);
void Primo(int, int *);

int main(void)
{
    int P[TAM];
    int FLA, J = 0, PRI = 2;

    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);
        if (FLA)
        {
            P[J] = PRI;
            J++;
        }
        PRI++;
    }
    Imprime(P, TAM);
    return 0;
}

void Primo(int A, int *B)
{
    int DI = 2;
    while (*B && (DI <= (A / 2)))
    {
        if ((A % DI) == 0)
            *B = 0;
        DI++;
    }
}

void Imprime(int Primos[], int T)
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nPrimos[%d]: %d", I, Primos[I]);
}
