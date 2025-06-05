#include <stdio.h>

int main() {
    int N;
    printf("Ingresa un valor entero positivo para N: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        for (int j = 1; j <= N - i; j++) {
            printf("%d ", j);
        }


        for (int k = 0; k < i * 2 + 1; k++) {
            printf("  ");
        }


        for (int j = N - i; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
    }

    return 0;
}
