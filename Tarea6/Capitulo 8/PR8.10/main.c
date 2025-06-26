#include <stdio.h>
#include <string.h>

/* Vendedores. */

typedef struct
{
    char noba[10];  // Nombre del banco
    char nucu[10];  // Número de cuenta
} banco;

typedef union
{
    banco che;  // Cheque
    banco nomi; // Nómina
    char venta; // Ventanilla
} fpago;

typedef struct
{
    char cnu[20];   // Calle y número
    char col[20];   // Colonia
    char cp[6];     // Código Postal (+1 para '\0')
    char ciu[15];   // Ciudad
} domicilio;

typedef struct
{
    int num;
    char nom[20];
    float ven[12];
    domicilio domi;
    float sal;
    fpago pago;
    int cla;
} vendedor;

// Prototipos
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);

int main(void)
{
    vendedor VENDEDORES[100];
    int TAM;

    do
    {
        printf("Ingrese el número de vendedores: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA\n");
    return 0;
}

void Lectura(vendedor A[], int T)
{
    int I, J;
    for (I = 0; I < T; I++)
    {
        printf("\n\tIngrese datos del vendedor %d", I + 1);
        printf("\nNúmero de vendedor: ");
        scanf("%d", &A[I].num);

        getchar();
        printf("Nombre del vendedor: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0';

        printf("Ventas del año:\n");
        for (J = 0; J < 12; J++)
        {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }

        getchar();
        printf("Domicilio del vendedor:\n");
        printf("\tCalle y número: ");
        fgets(A[I].domi.cnu, sizeof(A[I].domi.cnu), stdin);
        A[I].domi.cnu[strcspn(A[I].domi.cnu, "\n")] = '\0';

        printf("\tColonia: ");
        fgets(A[I].domi.col, sizeof(A[I].domi.col), stdin);
        A[I].domi.col[strcspn(A[I].domi.col, "\n")] = '\0';

        printf("\tCódigo Postal: ");
        fgets(A[I].domi.cp, sizeof(A[I].domi.cp), stdin);
        A[I].domi.cp[strcspn(A[I].domi.cp, "\n")] = '\0';

        printf("\tCiudad: ");
        fgets(A[I].domi.ciu, sizeof(A[I].domi.ciu), stdin);
        A[I].domi.ciu[strcspn(A[I].domi.ciu, "\n")] = '\0';

        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);

        printf("Forma de Pago (Banco-1 Nómina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);
        getchar();
        switch (A[I].cla)
        {
        case 1:
            printf("\tNombre del banco: ");
            fgets(A[I].pago.che.noba, sizeof(A[I].pago.che.noba), stdin);
            A[I].pago.che.noba[strcspn(A[I].pago.che.noba, "\n")] = '\0';

            printf("\tNúmero de cuenta: ");
            fgets(A[I].pago.che.nucu, sizeof(A[I].pago.che.nucu), stdin);
            A[I].pago.che.nucu[strcspn(A[I].pago.che.nucu, "\n")] = '\0';
            break;
        case 2:
            printf("\tNombre del banco: ");
            fgets(A[I].pago.nomi.noba, sizeof(A[I].pago.nomi.noba), stdin);
            A[I].pago.nomi.noba[strcspn(A[I].pago.nomi.noba, "\n")] = '\0';

            printf("\tNúmero de cuenta: ");
            fgets(A[I].pago.nomi.nucu, sizeof(A[I].pago.nomi.nucu), stdin);
            A[I].pago.nomi.nucu[strcspn(A[I].pago.nomi.nucu, "\n")] = '\0';
            break;
        case 3:
            A[I].pago.venta = 'S';
            break;
        }
    }
}

void F1(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tVentas Totales de los Vendedores");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        printf("\nVendedor: %d", A[I].num);
        printf("\nVentas: %.2f\n", SUM);
    }
}

void F2(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tIncremento a los Vendedores con Ventas > 1,500,000$");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        if (SUM > 1500000.0)
        {
            A[I].sal *= 1.05;
            printf("\nNúmero de empleado: %d", A[I].num);
            printf("\nVentas: %.2f", SUM);
            printf("\nNuevo salario: %.2f\n", A[I].sal);
        }
    }
}

void F3(vendedor A[], int T)
{
    int I, J;
    float SUM;

    printf("\n\t\tVendedores con Ventas < 300,000");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];

        if (SUM < 300000.0)
        {
            printf("\nNúmero de empleado: %d", A[I].num);
            printf("\nNombre: %s", A[I].nom);
            printf("\nVentas: %.2f\n", SUM);
        }
    }
}

void F4(vendedor A[], int T)
{
    int I;

    printf("\n\t\tVendedores con Cuenta en el Banco");
    for (I = 0; I < T; I++)
    {
        if (A[I].cla == 1)
        {
            printf("\nNúmero de vendedor: %d", A[I].num);
            printf("\nBanco: %s", A[I].pago.che.noba);
            printf("\nCuenta: %s\n", A[I].pago.che.nucu);
        }
    }
}

