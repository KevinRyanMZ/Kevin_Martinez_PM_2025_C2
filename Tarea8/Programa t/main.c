#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    float promedio;
} Alumno;

// PROTOTIPOS
void guardarAlumnos(const char *archivo);
Alumno* cargarAlumnos(const char *archivo, int *cantidad);
void ordenarPorNombre(Alumno *alumnos, int n);
void ordenarPorPromedio(Alumno *alumnos, int n);
void imprimirAlumnos(Alumno *alumnos, int n);

// FUNCIÓN PRINCIPAL
int main() {
    Alumno *alumnos = NULL;
    int opcion, cantidad;
    const char *archivo = "alumnos.dat";

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
                alumnos = cargarAlumnos(archivo, &cantidad);
                if (alumnos) {
                    ordenarPorNombre(alumnos, cantidad);
                    imprimirAlumnos(alumnos, cantidad);
                    free(alumnos);
                }
                break;
            case 3:
                alumnos = cargarAlumnos(archivo, &cantidad);
                if (alumnos) {
                    ordenarPorPromedio(alumnos, cantidad);
                    imprimirAlumnos(alumnos, cantidad);
                    free(alumnos);
                }
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

// GUARDAR alumnos con malloc temporal
void guardarAlumnos(const char *archivo) {
    FILE *f = fopen(archivo, "ab");
    if (!f) {
        perror("Error al abrir archivo");
        return;
    }

    int n;
    printf("¿Cuántos alumnos deseas ingresar? ");
    scanf("%d", &n);
    getchar();

    Alumno *alumnos = malloc(n * sizeof(Alumno));
    if (!alumnos) {
        perror("Memoria insuficiente");
        fclose(f);
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nAlumno #%d\n", i + 1);
        printf("Nombre: ");
        fgets(alumnos[i].nombre, 50, stdin);
        alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0';
        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
        getchar();
    }

    fwrite(alumnos, sizeof(Alumno), n, f);
    fclose(f);
    free(alumnos);
    printf("Datos guardados correctamente.\n");
}

// CARGAR alumnos desde archivo binario con malloc y sin fread
Alumno* cargarAlumnos(const char *archivo, int *cantidad) {
    FILE *f = fopen(archivo, "rb");
    if (!f) {
        perror("Error al abrir archivo");
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long tamano = ftell(f);
    rewind(f);

    *cantidad = tamano / sizeof(Alumno);
    if (*cantidad <= 0) {
        fclose(f);
        return NULL;
    }

    Alumno *alumnos = malloc(*cantidad * sizeof(Alumno));
    if (!alumnos) {
        perror("Sin memoria");
        fclose(f);
        return NULL;
    }

    char *ptr = (char *)alumnos;
    size_t total = 0;
    while (total < *cantidad * sizeof(Alumno)) {
        int byte = fgetc(f);
        if (byte == EOF) break;
        ptr[total++] = (char)byte;
    }

    fclose(f);
    return alumnos;
}


void ordenarPorNombre(Alumno *alumnos, int n) {
    Alumno temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp((alumnos + j)->nombre, (alumnos + j + 1)->nombre) > 0) {
                temp = *(alumnos + j);
                *(alumnos + j) = *(alumnos + j + 1);
                *(alumnos + j + 1) = temp;
            }
}


void ordenarPorPromedio(Alumno *alumnos, int n) {
    Alumno temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((alumnos + j)->promedio > (alumnos + j + 1)->promedio) {
                temp = *(alumnos + j);
                *(alumnos + j) = *(alumnos + j + 1);
                *(alumnos + j + 1) = temp;
            }
}

// IMPRIMIR alumnos usando punteros
void imprimirAlumnos(Alumno *alumnos, int n) {
    printf("\n%-30s | %s\n", "Nombre", "Promedio");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-30s | %.2f\n", (alumnos + i)->nombre, (alumnos + i)->promedio);
    }
}

