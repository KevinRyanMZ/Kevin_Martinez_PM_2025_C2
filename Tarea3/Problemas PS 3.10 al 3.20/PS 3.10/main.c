#include <stdio.h>
#include <stdlib.h>


int main() {
    float precios[7];      // precios de L1 a L6 (índice 1 a 6)
    int boletos[7] = {0};  // contador de boletos vendidos por localidad
    int CLA = 0, CAN = 0;
    float monto = 0.0;
    float recaudacion_total = 0.0;

    // Leer precios
    printf("Introduce los precios de las 6 localidades:\n");
    for (int i = 1; i <= 6; i++) {
        printf("Precio L%d: ", i);
        scanf("%f", &precios[i]);
    }

    // Procesar ventas
    printf("\nIntroduce las ventas (CLA CAN), usa 0 0 para terminar:\n");
    while (1) {
        printf("Venta (CLA CAN): ");
        scanf("%d %d", &CLA, &CAN);

        if (CLA == 0 && CAN == 0)
            break;

        if (CLA < 1 || CLA > 6) {
            printf("Error: localidad inválida (CLA debe ser entre 1 y 6).\n");
            continue;
        }

        monto = precios[CLA] * CAN;
        boletos[CLA] += CAN;  // Acumular
        recaudacion_total += monto;

        printf("Monto de la venta: $%.2f\n", monto);
    }

    // Mostrar resumen
    printf("\nResumen de ventas:\n");
    for (int i = 1; i <= 6; i++) {
        printf("Boletos vendidos L%d: %d\n", i, boletos[i]);
    }
    printf("Recaudación total: $%.2f\n", recaudacion_total);

    return 0;
}
