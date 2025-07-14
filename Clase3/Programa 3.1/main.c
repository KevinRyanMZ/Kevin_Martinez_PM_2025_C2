#include <stdio.h>
#include <stdlib.h>
//define sirve para definir un valor a un nombre repetible en el codigo y asi conseguir poder cambiar ese valor sin tener
//que cambiarlo en cada zona en la que aparece

int main()
{
    int I = 0;
    float SAL = 0.0, NOM = 0.0, IMP = 0.0, IMPT = 0.0;


    for (I = 1; I <= 5; I++)
    {
        printf("ingrese el salario del profesor %d: \n", I);
        scanf("%f", &SAL);
        IMP = SAL*0.12;
        IMPT = IMPT + IMP;
        SAL = SAL - (SAL*0.12);

        printf("Nomina del profesor %.2f:\n", SAL);
        NOM = NOM + SAL;
    }


    printf("\n Total a pagar a profesores es: %.2f:", NOM);
    printf("\n Total a pagar de impuesto es: %.2f:", IMPT);
    return 0;
}
