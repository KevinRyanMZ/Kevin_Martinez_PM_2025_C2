#include <stdio.h>
#include <math.h>
//Busca 2 primos enteros que sean gemelos

int esPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int N1, N2;
    printf("Ingresa dos números enteros positivos: ");
    scanf("%d %d", &N1, &N2);

    if (N1 > N2) {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    printf("Primos gemelos entre %d y %d:\n", N1, N2);
    for (int i = N1; i <= N2 - 2; i++) {
        if (esPrimo(i) && esPrimo(i + 2))
            printf("(%d, %d)\n", i, i + 2);
    }

    return 0;
}
