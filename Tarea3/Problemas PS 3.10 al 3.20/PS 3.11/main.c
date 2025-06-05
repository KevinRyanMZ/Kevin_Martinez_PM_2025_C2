#include <stdio.h>
#include <stdlib.h>

/*Recibe el dato acerca de la cantidad de a�os y pregunta al operador la cantidad de vino
por tipo que se produjo en cada a�o, para al final calcular que tanto se produjo en ese
periodo de tiempo por tipo y cuando en total se produjo */

int main() {

    int N = 0;
    int i = 0;
    int j = 0;
    int tipo[4];
    float VIN[4];
    float totalPorTipo[4] = {0};  // Total por tipo de vino
    float totalPorAnio[30];        // Total por a�o

    printf("Introduce el numero de anos: ");
    scanf("%d", &N);



    // Leer datos
    for (int i = 0; i < N; i++) {
        printf("Introduce la produccion del ano %d para los 4 tipos de vino en litros:\n", i + 1);


        for (int j = 0; j < 4; j++) {
            printf("  Tipo %d: ", j + 1);
            scanf("%f", &VIN[j]); //

            totalPorTipo[j] += VIN[j];
            totalPorAnio[i] += VIN[j];
        }
    }

    // Mostrar total producido por tipo
    printf("\nTotal producido por tipo de vino:\n");
    for (int j = 0; j < 4; j++) {
        printf("Tipo %d: %.2f litros\n", j + 1, totalPorTipo[j]);
    }

    // Mostrar total producido por a�o
    printf("\nTotal producido por ano:\n");
    for (int i = 0; i < N; i++) {
        printf("A�o %d: %.2f litros\n", i + 1, totalPorAnio[i]);
    }

    return 0;
}
