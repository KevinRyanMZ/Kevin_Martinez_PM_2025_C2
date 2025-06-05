
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad = 0;
    //Pregunta que determina el rango de edad de una persona
    // 1 - Recien nacido persona de edad menor a 1 ano
    // 2 - Infante persona de edad entre 1 a 3 anos
    // 3 - Nino persona de edad entre 3 a 12 anos
    // 4 - Adolecente persona de entre 12 a 18 anos
    // 5 - Mayor de edad persona de edad entre 18 a 38 anos
    // 6 - Envejeciente persona de edad entre 38 a 68 anos
    // 7 - Anciano persona mayor de 68 anos de edad
    // el cero es falso lo que sea que no sea cero es verdadero
    printf("Clase de seleccion!\n");

    printf("Ingrese su edad: ");
    scanf("%i", &edad);

    if(edad >= 0 && edad <= 120) //Verificar la validez de los datos
    {
        if(edad < 1) //verifica si es infante
        {
            printf("Usted es un recien nacido");
        }
         else if(edad >= 1, edad < 3) //verifica si es infante
        {
            printf("Usted es un Infante");
        }
         else if(edad >= 3, edad < 12) //verifica si es infante
        {
            printf("Usted es Nino");
        }
         else if(edad >= 12, edad < 18) //verifica si es infante
        {
            printf("Usted es Adolecente");
        }
         else if(edad >= 18, edad < 38) //verifica si es infante
        {
            printf("Usted es Mayor de edad");
        }
         else if(edad >= 38, edad < 68) //verifica si es infante
        {
            printf("Usted es una persona envejeciente");
        }
         else if(edad >= 68, edad <= 120) //verifica si es infante
        {
            printf("Usted es un anciano");
        }


    }
    else
    {
        if(edad < 0)
        {
            printf("\nError Edad negativa");
        }
        if(edad > 120)
        {
            printf("\nError Edad muy Alta no Real");
        }

    }

    getchar();
    return 0;
}
