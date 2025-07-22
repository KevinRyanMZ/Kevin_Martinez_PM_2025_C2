// Activamos la implementación de las librerías stb_image y stb_image_write
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

// Librerías necesarias para trabajar con archivos e imágenes
#include <stdio.h>
#include <stdlib.h>

// Incluimos las cabeceras de stb
#include "stb_image.h"
#include "stb_image_write.h"

// Función que convierte un píxel RGB en un valor de gris, usando la fórmula
unsigned char a_gris(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
}

int main(int argc, char *argv[]) {
    // Verifica que el usuario haya pasado el nombre del archivo por la línea de comandos
    if (argc != 2) {
        printf("Uso: %s archivo.jpg\n", argv[0]);
        return 1; // Termina el programa con error si no hay argumento
    }

    int ancho, alto, canales;

    // Carga la imagen JPG desde el archivo indicado, forzando a que tenga 3 canales (RGB)
    // stbi_load devuelve un puntero al buffer de datos de imagen
    unsigned char *imagen = stbi_load(argv[1], &ancho, &alto, &canales, 3);
    if (!imagen) {
        printf("No se pudo cargar la imagen: %s\n", argv[1]);
        return 1;
    }

    // Muestra información básica de la imagen
    printf("Imagen cargada: %dx%d píxeles, %d canales.\n", ancho, alto, canales);

    // Reserva memoria para la imagen en escala de grises (1 byte por píxel)
    unsigned char *imagen_gris = malloc(ancho * alto);
    if (!imagen_gris) {
        printf("Error al asignar memoria.\n");
        stbi_image_free(imagen); // Libera la imagen original si hay error
        return 1;
    }

    // Recorre todos los píxeles de la imagen original
    for (int i = 0; i < ancho * alto; i++) {
        // Extrae los valores RGB de cada píxel (3 canales)
        unsigned char r = imagen[i * 3 + 0];
        unsigned char g = imagen[i * 3 + 1];
        unsigned char b = imagen[i * 3 + 2];

        // Convierte el píxel a gris y lo guarda en el nuevo buffer
        imagen_gris[i] = a_gris(r, g, b);
    }

    // Guarda la imagen en gris como un archivo PNG (1 canal = escala de grises)
    // El último argumento (stride) es el número de bytes por fila
    if (stbi_write_png("imagen_gris.png", ancho, alto, 1, imagen_gris, ancho)) {
        printf("Imagen en escala de grises guardada como imagen_gris.png\n");
    } else {
        printf("Error al guardar la imagen.\n");
    }

    // Libera la memoria reservada para las imágenes
    stbi_image_free(imagen);
    free(imagen_gris);

    return 0; // Fin del programa exitoso
}
