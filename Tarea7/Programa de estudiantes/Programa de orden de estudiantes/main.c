#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct {
    char nombre[50];
    float promedio;
} Alumno;

void guardarAlumnos(const char *archivo);
int cargarAlumnos(const char *archivo, Alumno alumnos[]);
void ordenarPorNombre(Alumno alumnos[], int n);
void ordenarPorPromedio(Alumno alumnos[], int n);
void imprimirAlumnos(Alumno alumnos[], int n);

int main() {
    Alumno alumnos[MAX];
    int opcion, cantidad;
    const char *archivo = "alumnos.dat";
    int j = 0, i = 0, n = 0;

    do {
        printf("\nMENÚ:\n");
        printf("1. Ingresar alumnos\n");
        printf("2. Mostrar alumnos ordenados por nombre\n");
        printf("3. Mostrar alumnos ordenados por promedio\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1:
                guardarAlumnos(archivo);
                break;
            case 2:
                cantidad = cargarAlumnos(archivo, alumnos);
                ordenarPorNombre(alumnos, cantidad);
                imprimirAlumnos(alumnos, cantidad);
                break;
            case 3:
                cantidad = cargarAlumnos(archivo, alumnos);
                ordenarPorPromedio(alumnos, cantidad);
                imprimirAlumnos(alumnos, cantidad);
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);

    return 0;
}


// Guarda los alumnos al archivo binario
void guardarAlumnos(const char *archivo) {
    FILE *f = fopen(archivo, "wb");
    if (!f) {printf("No se pudo abrir el archivo");
        return;
    }

    int n;
    Alumno a;
    printf("¿Cuántos alumnos deseas ingresar? ");
    scanf("%d", &n);
    getchar();  // Limpiar el buffer

    for (int i = 0; i < n; i++) {
        printf("\nAlumno #%d\n", i + 1);
        printf("Nombre: ");
        fgets(a.nombre, sizeof(a.nombre), stdin);
        a.nombre[strcspn(a.nombre, "\n")] = '\0';
        printf("Promedio: ");
        scanf("%f", &a.promedio);
        getchar();  // Limpiar el buffer
        fwrite(&a, sizeof(Alumno), 1, f);
    }

    fclose(f);
}

// Lee los alumnos del archivo sin usar fread
int cargarAlumnos(const char *archivo, Alumno alumnos[]) {
    FILE *f = fopen(archivo, "rb");
    if (!f) {printf("No se pudo abrir el archivo");
        return 0;
    }

    int i = 0;
    Alumno a;

    while (1) {
        // leer byte por byte en memoria simulando fread
        size_t leidos = 0;
        char *ptr = (char *)&a;
        while (leidos < sizeof(Alumno)) {
            int byte = fgetc(f);
            if (byte == EOF) {
                fclose(f);
                return i;  // Fin de archivo
            }
            ptr[leidos++] = (char)byte;
        }

        alumnos[i++] = a;
        if (i >= MAX) break;
    }

    fclose(f);
    return i;
}

// Ordenar por nombre (BubbleSort)
void ordenarPorNombre(Alumno alumnos[], int n) {
    Alumno temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0)
                {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
}

// Ordenar por promedio (BubbleSort)
void ordenarPorPromedio(Alumno alumnos[], int n) {
    Alumno temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (alumnos[j].promedio > alumnos[j + 1].promedio) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
}

// Imprimir alumnos
void imprimirAlumnos(Alumno alumnos[], int n) {
    printf("\n%-30s | %s\n", "Nombre", "Promedio");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-30s | %.2f\n", alumnos[i].nombre, alumnos[i].promedio);
}


