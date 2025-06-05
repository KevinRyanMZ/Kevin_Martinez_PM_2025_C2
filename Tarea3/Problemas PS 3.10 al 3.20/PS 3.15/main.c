#include <stdio.h>

int main() {
    int N1, N2;
    printf("Ingresa dos números naturales: ");
    scanf("%d %d", &N1, &N2);

    int a = N1, b = N2;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("El MCD de %d y %d es %d\n", N1, N2, a);
    return 0;
}
