#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARCHIVO_VEHICULOS "vehiculos.dat"
#define MAX 100

typedef struct
{
    char placa[20];
    char marca[30];
    char modelo[30];
    char tipoCombustible[10];
    float kmGalonCarretera;
    float kmGalonCiudad;
    float costoGomas;
    float kmGomas;
    float costoSeguroAnual;
    float costoMantenimiento;
    float kmMantenimiento;
    float costoVehiculo;
    int vidaUtil;
    float kmAnualPromedio;
    float depreciacion;

} Vehiculo;

// Variables
Vehiculo vehiculos[MAX];
int cantidadVehiculos = 0;
float costoGasolina = 100.0;
float costoGasoil = 60.0;

//funciones
void guardarVehiculos();
void cargarVehiculos();
void menu();
void crearVehiculo();
void borrarVehiculo(char placa[]);
void modificarVehiculo(char placa[]);
void setCostosGenerales();
void listadeVehiculos();
void calcularCostoViaje(char placa[]);

int main()
{
    cargarVehiculos(); // Cargar datos al iniciar, no funciona si no lo cargas antes >:,v
    menu();
    return 0;
}

// Guarda los vehículos en archivo binario (para eso el wb)
void guardarVehiculos()
{
    FILE *f = fopen(ARCHIVO_VEHICULOS, "wb");
    if (f == NULL)
    {
        printf("Error al guardar los vehículos.\n");
        return;
    }
    fwrite(&cantidadVehiculos, sizeof(int), 1, f);
    fwrite(vehiculos, sizeof(Vehiculo), cantidadVehiculos, f);
    fclose(f);
}


void cargarVehiculos()
{
    FILE *f = fopen(ARCHIVO_VEHICULOS, "rb");
    if (f == NULL)
    {
        printf("no hay vehiculos\n");
        return;
    }
    fread(&cantidadVehiculos, sizeof(int), 1, f);
    fread(vehiculos, sizeof(Vehiculo), cantidadVehiculos, f);
    fclose(f);
}


void menu()
{
    int opcion;
    char placa[20];

    do
    {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Crear vehículo\n");
        printf("2. Borrar vehículo\n");
        printf("3. Modificar vehículo\n");
        printf("4. Ingresar costos generales\n");
        printf("5. Calcular costo de viaje\n");
        printf("6. Ver lista de vehiculos\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            crearVehiculo();
            guardarVehiculos();
            break;
        case 2:
            printf("Placa a borrar: ");
            scanf(" %[^\n]", placa);
            borrarVehiculo(placa);
            guardarVehiculos();
            break;
        case 3:
            printf("Placa de coche a modificar: ");
            scanf(" %[^\n]", placa);
            modificarVehiculo(placa);
            guardarVehiculos();
            break;
        case 4:
            printf("Costo gasolina: ");
            scanf("%f", &costoGasolina);
            printf("Costo gasoil: ");
            scanf("%f", &costoGasoil);
            break;
        case 5:
            printf("\nColoque la placa del vehiculo a utilizar: ");
            scanf(" %[^\n]", placa);
            calcularCostoViaje(placa);
            break;
        case 6:
            listadeVehiculos();
            break;
        case 0:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción inválida.\n");
            return;
        }
    }
    while (opcion != 0);
}


void crearVehiculo()
{
    if (cantidadVehiculos >= MAX)
    {
        printf("No se pueden agregar más vehículos.\n");
        return;
    }
    Vehiculo a;

    printf("Placa: ");
    scanf(" %[^\n]", a.placa);
    printf("Marca: ");
    scanf(" %[^\n]", a.marca);
    printf("Modelo: ");
    scanf(" %[^\n]", a.modelo);
    printf("Tipo Combustible (Gasolina/Gasoil): ");
    scanf(" %[^\n]", a.tipoCombustible);
    printf("Km por galon en carretera: ");
    scanf("%f", &a.kmGalonCarretera);
    printf("Km por galon en ciudad: ");
    scanf("%f", &a.kmGalonCiudad);
    printf("Costo gomas: ");
    scanf("%f", &a.costoGomas);
    printf("Km de vida útil de gomas: ");
    scanf("%f", &a.kmGomas);
    printf("Costo seguro anual: ");
    scanf("%f", &a.costoSeguroAnual);
    printf("Costo mantenimiento: ");
    scanf("%f", &a.costoMantenimiento);
    printf("Km entre mantenimientos: ");
    scanf("%f", &a.kmMantenimiento);
    printf("Costo vehiculo: ");
    scanf("%f", &a.costoVehiculo);
    printf("Vida util (años): ");
    scanf("%d", &a.vidaUtil);
    printf("Km por agno promedio: ");
    scanf("%f", &a.kmAnualPromedio);
    printf("Depreciacion por agno: ");
    scanf("%f", &a.depreciacion);

    vehiculos[cantidadVehiculos++] = a;
}

void borrarVehiculo(char placa[])
{
    int i, encontrado = 0;
    for (i = 0; i < cantidadVehiculos; i++)
    {
        if (strcmp(vehiculos[i].placa, placa) == 0)
        {
            encontrado = 1;
            break;
        }
    }
    if (encontrado)
    {
        for (; i < cantidadVehiculos - 1; i++)
        {
            vehiculos[i] = vehiculos[i + 1];
        }
        cantidadVehiculos--;
        printf("Vehículo borrado.\n");
    }
    else
    {
        printf("Vehículo no encontrado.\n");
    }
}

void modificarVehiculo(char placa[])
{

    for (int i = 0; i < cantidadVehiculos; i++)
    {
        if (strcmp(vehiculos[i].placa, placa) == 0)
        {
            printf("\n--- Modificando vehículo %s ---\n", placa);

            printf("Marca: ");
            scanf(" %[^\n]", vehiculos[i].marca);
            printf("Modelo: ");
            scanf(" %[^\n]", vehiculos[i].modelo);
            printf("Tipo Combustible (Gasolina/Gasoil): ");
            scanf(" %[^\n]", vehiculos[i].tipoCombustible);
            printf("Km por galon en carretera: ");

            while(vehiculos[i].tipoCombustible == "Gasolina" && vehiculos[i].tipoCombustible == "Gasoil")
            {
                printf("Tipo de combustible invalido\n ");
                scanf(" %[^\n]", vehiculos[i].tipoCombustible);
            }


            scanf("%f", &vehiculos[i].kmGalonCarretera);
            printf("Km por galon en ciudad: ");
            scanf(" %f", &vehiculos[i].kmGalonCiudad);
            printf("Costo gomas: ");
            scanf(" %f", &vehiculos[i].costoGomas);
            printf("Km de vida útil de gomas: ");
            scanf(" %f", &vehiculos[i].kmGomas);
            printf("Costo seguro anual: ");
            scanf(" %f", &vehiculos[i].costoSeguroAnual);
            printf("Costo mantenimiento: ");
            scanf(" %f", &vehiculos[i].costoMantenimiento);
            printf("Km entre mantenimientos: ");
            scanf(" %f", &vehiculos[i].kmMantenimiento);
            printf("Costo vehiculo: ");
            scanf(" %f", &vehiculos[i].costoVehiculo);
            printf("Vida util (años): ");
            scanf(" %d", &vehiculos[i].vidaUtil);
            printf("Km por agno promedio: ");
            scanf(" %f", &vehiculos[i].kmAnualPromedio);
            printf("Depreciacion por agno: ");
            scanf(" %f", &vehiculos[i].depreciacion);

            printf("Vehiculo modificado correctamente.\n");
            return;
        }
    }
    printf("Vehiculo no encontrado.\n");
}

void listadeVehiculos()
{
    if (cantidadVehiculos == 0)
    {
        printf("\nNo hay vehiculos registrados.\n");
        return;
    }

    printf("\n--- LISTA DE VEHÍCULOS ---\n");
    for (int i = 0; i < cantidadVehiculos; i++)
    {
        printf("\nVehiculo #%d\n", i + 1);
        printf("Placa: %s\n", vehiculos[i].placa);
        printf("Marca: %s\n", vehiculos[i].marca);
        printf("Modelo: %s\n", vehiculos[i].modelo);
        printf("Tipo Combustible: %s\n", vehiculos[i].tipoCombustible);
        printf("Km/gal Carretera: %.2f\n", vehiculos[i].kmGalonCarretera);
        printf("Km/gal Ciudad: %.2f\n", vehiculos[i].kmGalonCiudad);
        printf("Costo Gomas: %.2f\n", vehiculos[i].costoGomas);
        printf("Km vida util gomas: %.2f\n", vehiculos[i].kmGomas);
        printf("Costo seguro anual: %.2f\n", vehiculos[i].costoSeguroAnual);
        printf("Costo mantenimiento: %.2f\n", vehiculos[i].costoMantenimiento);
        printf("Km entre mantenimientos: %.2f\n", vehiculos[i].kmMantenimiento);
        printf("Costo vehiculo: %.2f\n", vehiculos[i].costoVehiculo);
        printf("Vida útil (años): %d\n", vehiculos[i].vidaUtil);
        printf("Km/agno promedio: %.2f\n", vehiculos[i].kmAnualPromedio);
        printf("depreciacion /agno: %.2f\n", vehiculos[i].depreciacion);
    }
}

void calcularCostoViaje(char placa[])
{
    float GastoCiudad;
    float GastoCarretera;
    float GastoCiudad1km;
    float GastoCarretera1km;
    float Distancia;
    float PorcentajeCarretera;
    float PorcentajeCiudad;
    float Dias;
    float Seguro;
    float Seguro1km;
    float GastoGomas;
    float GastoGomas1km;
    float Mantenimiento;
    float Mantenimiento1km;
    float GastoTotal;
    float GastoKm;

    int encontrado = 0;




    for (int i = 0; i < cantidadVehiculos; i++)
    {
        if (strcmp(vehiculos[i].placa, placa) == 0)
        {
            encontrado = 1;

            // Escaneo de Datos
            printf("Coloque la distancia en Km: ");
            scanf("%f", &Distancia);

            printf("Porcentaje en Carretera aproximado: ");
            scanf("%f", &PorcentajeCarretera);
            PorcentajeCarretera /= 100;

            printf("Porcentaje en Ciudad aproximado: ");
            scanf("%f", &PorcentajeCiudad);
            PorcentajeCiudad /= 100;

            // Calculos
            Dias = Distancia / (vehiculos[i].kmAnualPromedio / 365.0f);

            Seguro = (vehiculos[i].costoSeguroAnual / 365.0f) * Dias;
            //Seguro1km = (vehiculos[i].costoSeguroAnual / 365.0f) * (1 / vehiculos[i].kmAnualPromedio / 365.0f);

            GastoGomas = (Distancia / vehiculos[i].kmGomas) * vehiculos[i].costoGomas;
            //GastoGomas1km = (1.0f / vehiculos[i].kmGomas) * vehiculos[i].costoGomas;

            Mantenimiento = (Distancia / vehiculos[i].kmMantenimiento) * vehiculos[i].costoMantenimiento;
            //Mantenimiento1km = (1.0f / vehiculos[i].kmMantenimiento) * vehiculos[i].costoMantenimiento;

            Seguro1km = vehiculos[i].costoSeguroAnual / vehiculos[i].kmAnualPromedio;
            GastoGomas1km = vehiculos[i].costoGomas / vehiculos[i].kmGomas;
            Mantenimiento1km = vehiculos[i].costoMantenimiento / vehiculos[i].kmMantenimiento;

            if (strcmp(vehiculos[i].tipoCombustible, "Gasolina") == 0)
            {
                GastoCarretera = ((PorcentajeCarretera * Distancia) / vehiculos[i].kmGalonCarretera) * costoGasolina;
                GastoCiudad = ((PorcentajeCiudad * Distancia) / vehiculos[i].kmGalonCiudad) * costoGasolina;

                GastoCarretera1km = ((PorcentajeCarretera * 1) / vehiculos[i].kmGalonCarretera) * costoGasolina;
                GastoCiudad1km = ((PorcentajeCiudad * 1) / vehiculos[i].kmGalonCiudad) * costoGasolina;
            }


            else if (strcmp(vehiculos[i].tipoCombustible, "Gasoil") == 0)
            {
                GastoCarretera = ((PorcentajeCarretera * Distancia) / vehiculos[i].kmGalonCarretera) * costoGasoil;
                GastoCiudad = ((PorcentajeCiudad * Distancia) / vehiculos[i].kmGalonCiudad) * costoGasoil;

                GastoCarretera1km = ((PorcentajeCarretera * 1) / vehiculos[i].kmGalonCarretera) * costoGasoil;
                GastoCiudad1km = ((PorcentajeCiudad * 1) / vehiculos[i].kmGalonCiudad) * costoGasoil;

            }
            else
            {
                printf("\nTipo de combustible no reconocido. Modifique el vehículo.\n");
                return;
            }


            GastoTotal = GastoCarretera + GastoCiudad + Seguro + GastoGomas + Mantenimiento;
            GastoKm = GastoCarretera1km + GastoCiudad1km + Seguro1km + GastoGomas1km + Mantenimiento1km ;


            printf("\n--- COSTOS ---");
            printf("\nSeguro: %.2f", Seguro);
            printf("\nGomas: %.2f", GastoGomas);
            printf("\nMantenimiento: %.2f", Mantenimiento);
            printf("\nGasto Carretera: %.2f", GastoCarretera);
            printf("\nGasto Ciudad: %.2f", GastoCiudad);
            printf("\nCosto total del viaje: %.2f\n", GastoTotal);
            printf("\nCosto aproximado en cada km: %.2f\n", GastoKm);
            return;
        }
    }

    if (!encontrado)
    {
        printf("\nVehículo no encontrado.\n");
    }
}
