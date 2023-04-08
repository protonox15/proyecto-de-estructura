// proyecto de estructura de datos //
// integrantes //
// > ANGIE ALVARADO //
// > XAVIER CARRASCO //
// > JOAN VERA //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

void dibujar_marco(int filas, int columnas);
void gotoxy(int x, int y);

int main() {
    int vidas = 3;
    time_t tiempo_inicio, tiempo_actual;
    double segundos;

    tiempo_inicio = time(NULL);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int filas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    int columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Dibujar el marco por primera vez
    dibujar_marco(filas, columnas);

    while (1) {
        // Mostrar vidas
        gotoxy(2, 1);
        printf("Vidas: %d", vidas);

        tiempo_actual = time(NULL);
        segundos = difftime(tiempo_actual, tiempo_inicio);
        int minutos = (int)segundos / 60;
        int segs = (int)segundos % 60;
        gotoxy(columnas - 15, 1);
        printf("Tiempo: %02d:%02d", minutos, segs);

        if (segundos >= 60) break;

        Sleep(100);
    }

    return 0;
}

void dibujar_marco(int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
