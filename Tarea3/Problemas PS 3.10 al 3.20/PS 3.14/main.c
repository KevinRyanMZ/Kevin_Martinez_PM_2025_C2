#include <stdio.h>
#include <math.h>

double factorial(int n) {
    double f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

int main() {
    double x, termino, senx = 0;
    int i = 1, signo = 1, terminos = 0;

    printf("Introduce el valor de x (en radianes): ");
    scanf("%lf", &x);

    do {
        termino = signo * pow(x, i) / factorial(i);
        senx += termino;
        signo *= -1;
        i += 2;
        terminos++;
    } while (fabs(termino) >= 0.001);

    printf("sen(%.2f) ≈ %.5f usando %d terminos\n", x, senx, terminos);
    return 0;
}
