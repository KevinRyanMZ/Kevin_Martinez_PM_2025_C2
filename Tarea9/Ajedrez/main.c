#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void MoverPieza(char (*tablero[8])[3]);

int main()
{
    char A[8][3] = {"TW", "HW", "BW", "KW", "QW", "BW", "HW", "TW"};
    char B[8][3] = {"PW", "PW", "PW", "PW", "PW", "PW", "PW", "PW"};
    char C[8][3] = {0};
    char D[8][3] = {0};
    char E[8][3] = {0};
    char F[8][3] = {0};
    char G[8][3] = {"PB", "PB", "PB", "PB", "PB", "PB", "PB", "PB"};
    char H[8][3] = {"TB", "HB", "BB", "KB", "QB", "BB", "HB", "TB"};

    char (*tablero[8])[3] = {H, G, F, E, D, C, B, A};

    while (1)
    {
        printf("\n    A    B    C    D    E    F    G    H\n");
        printf("  +----+----+----+----+----+----+----+---+\n");

        for (int i = 0; i < 8; i++)
        {
            printf("%d |", 8 - i);  // Número de fila al inicio
            for (int j = 0; j < 8; j++)
            {
                if (tablero[i][j][0] == 0)
                    printf("    |");
                else
                    printf(" %s |", tablero[i][j]);
            }
            printf(" %d\n", 8 - i);  // Número de fila al final
            printf("  +----+----+----+----+----+----+----+---+\n");
        }

        printf("    A    B    C    D    E    F    G    H\n");

        MoverPieza(tablero);
    }

    return 0;
}

void MoverPieza(char (*tablero[8])[3])
{
    char origen[3], destino[3];
    int fila_o, col_o, fila_d, col_d;

    printf("\nIngresa la casilla de origen (ej. E2): ");
    scanf("%2s", origen);
    printf("Ingresa la casilla de destino (ej. E4): ");
    scanf("%2s", destino);

    // Convertir letras a enteros
    col_o = toupper(origen[0]) - 'A'; //toupper funciona para colocar mayusculas
    fila_o = 8 - (origen[1] - '0');

    col_d = toupper(destino[0]) - 'A';
    fila_d = 8 - (destino[1] - '0');

    // Validaciones de valores en formato entero
    if (fila_o < 0 || fila_o > 7 || col_o < 0 || col_o > 7 || fila_d < 0 || fila_d > 7 || col_d < 0 || col_d > 7)
    {
        printf("Coordenadas invalidas!\n");
        return;
    }

    if (tablero[fila_o][col_o][0] == 0)
    {
        printf("No hay pieza en la casilla de origen!\n");
        return;
    }

    //---------------------------------------------------------------------------------------------

    //Comparar cada pieza para ver si puede hacer el movimiento

    //Peòn ----------------------------------------------------------------------------------------
    if (strcmp(tablero[fila_o][col_o], "PB") == 0)
    {
        // Peón negro se mueve hacia abajo (de fila menor a mayor)
        if (fila_d != fila_o + 1 || col_d != col_o)
        {
            printf("\nMovimiento invalido para el peon negro.\n");
            return;
        }
    }

    if (strcmp(tablero[fila_o][col_o], "PW") == 0)
    {
        // Peón blanco se mueve hacia arriba (de fila mayor a menor)
        if (fila_d != fila_o - 1 || col_d != col_o)
        {
            printf("\nMovimiento invalido para el peon blanco.\n");
            return;
        }
    }

    //Torre -------------------------------------------------------------------------------------
    if (strcmp(tablero[fila_o][col_o], "TB") == 0 || strcmp(tablero[fila_o][col_o], "TW") == 0)
    {

        // Verifica si es movimiento horizontal o vertical
        if (fila_o != fila_d && col_o != col_d)
        {
            printf("\nMovimiento invalido para la torre.\n");
            return;
        }

        // Revisión de obstáculos (horizontal)
        if (fila_o == fila_d)
        {
            int inicio = (col_o < col_d) ? col_o + 1 : col_d + 1;
            int fin = (col_o < col_d) ? col_d : col_o;

            for (int i = inicio; i < fin; i++)
            {
                if (tablero[fila_o][i][0] != 0)
                {
                    printf("\nMovimiento bloqueado: hay una pieza en el camino.\n");
                    return;
                }
            }
        }

        // Revisión de obstáculos (vertical)
        if (col_o == col_d)
        {
            int inicio = (fila_o < fila_d) ? fila_o + 1 : fila_d + 1;
            int fin = (fila_o < fila_d) ? fila_d : fila_o;

            for (int i = inicio; i < fin; i++)
            {
                if (tablero[i][col_o][0] != 0)
                {
                    printf("\nMovimiento bloqueado: hay una pieza en el camino.\n");
                    return;
                }
            }
        }

    }

    //Alfil ----------------------------------------------------------------------

    if (strcmp(tablero[fila_o][col_o], "BB") == 0 || strcmp(tablero[fila_o][col_o], "BW") == 0)
    {
        if (abs(fila_d - fila_o) != abs(col_d - col_o))
        {
            printf("\nMovimiento inválido: el alfil solo se mueve en diagonales.\n");
            return;
        }

        int paso_fila = (fila_d > fila_o) ? 1 : -1;
        int paso_col = (col_d > col_o) ? 1 : -1;

        int i = fila_o + paso_fila;
        int j = col_o + paso_col;

        while (i != fila_d && j != col_d)
        {
            if (tablero[i][j][0] != 0)
            {
                printf("\nMovimiento bloqueado: hay una pieza en la diagonal.\n");
                return;
            }
            i += paso_fila;
            j += paso_col;
        }
    }

    //Caballo ----------------------------------------------------------------------

    if (strcmp(tablero[fila_o][col_o], "HB") == 0 || strcmp(tablero[fila_o][col_o], "HW") == 0)
    {
        int df = abs(fila_d - fila_o);
        int dc = abs(col_d - col_o);
        if (!((df == 2 && dc == 1) || (df == 1 && dc == 2)))
        {
            printf("\nMovimiento inválido: el caballo se mueve en L.\n");
            return;
        }
    }

    //Reina ----------------------------------------------------------------------

    if (strcmp(tablero[fila_o][col_o], "QB") == 0 || strcmp(tablero[fila_o][col_o], "QW") == 0)
    {
        int df = abs(fila_d - fila_o);
        int dc = abs(col_d - col_o);

        if (df == dc)
        {
            // Movimiento diagonal (como alfil)
            int paso_fila = (fila_d > fila_o) ? 1 : -1;
            int paso_col = (col_d > col_o) ? 1 : -1;
            int i = fila_o + paso_fila;
            int j = col_o + paso_col;
            while (i != fila_d && j != col_d)
            {
                if (tablero[i][j][0] != 0)
                {
                    printf("\nMovimiento bloqueado: hay una pieza en la diagonal.\n");
                    return;
                }
                i += paso_fila;
                j += paso_col;
            }

        }
        else if (fila_o == fila_d || col_o == col_d)
        {
            // Movimiento recto (como torre)
            if (fila_o == fila_d)
            {
                int inicio = (col_o < col_d) ? col_o + 1 : col_d + 1;
                int fin = (col_o < col_d) ? col_d : col_o;
                for (int i = inicio; i < fin; i++)
                {
                    if (tablero[fila_o][i][0] != 0)
                    {
                        printf("\nMovimiento bloqueado: hay una pieza en el camino.\n");
                        return;
                    }
                }
            }
            else
            {
                int inicio = (fila_o < fila_d) ? fila_o + 1 : fila_d + 1;
                int fin = (fila_o < fila_d) ? fila_d : fila_o;
                for (int i = inicio; i < fin; i++)
                {
                    if (tablero[i][col_o][0] != 0)
                    {
                        printf("\nMovimiento bloqueado: hay una pieza en el camino.\n");
                        return;
                    }
                }
            }

        }
        else
        {
            printf("\nMovimiento inválido: la reina se mueve solo en líneas rectas o diagonales.\n");
            return;
        }
    }

    //Rey -----------------------------------------------------------------------------------------

    if (strcmp(tablero[fila_o][col_o], "KB") == 0 || strcmp(tablero[fila_o][col_o], "KW") == 0) {
    int df = abs(fila_d - fila_o);
    int dc = abs(col_d - col_o);
    if (df > 1 || dc > 1) {
        printf("\nMovimiento inválido: el rey solo se mueve una casilla.\n");
        return;
    }
}

    strcpy(tablero[fila_d][col_d], tablero[fila_o][col_o]);  // Copia el valor de origen en la direcciòn
    tablero[fila_o][col_o][0] = 0;                            // Vacía Origen colocado
}







