#include <stdio.h>
#include <math.h>

int main() {
    int T, P, R;
    double valor;
    int LIMITE = 20;

    for (T = 1; T <= LIMITE; T++) {
        for (P = 1; P <= LIMITE; P++) {
            for (R = 1; R <= LIMITE; R++) {
                valor = 7 * pow(T, 4) - 6 * pow(P, 3) + 12 * pow(R, 5);
                if (valor < 5850 && valor > 0) {
                    printf("T = %d, P = %d, R = %d -> %.2f\n", T, P, R, valor);

                }
            }
        }
    }

    return 0;
}
