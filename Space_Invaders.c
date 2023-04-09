// Proyecto de estructura de datos //
// Integrantes //
// > ANGIE ALVARADO //
// > XAVIER CARRASCO //
// > JOAN VERA //


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

//{ Funciones del Sistema.
// > Funci�n Gotoxy. Permite posicionar el cursos en cualquier parte de la pantalla.
void Gotoxy(int x,int y){
    // Sea X la columna, y Y la fila.
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

// > Funci�n OcultarCursor, que hace el cursor [_] invisible.
void OcultarCursor(){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hcon, &cci);
}

// > Funci�n Marco. Permite dibujar un recuadro con dimensiones espec�ficas.
void Marco(int xSup, int ySup, int xInf, int yInf, int Vidas){
	// Impresi�n de l�neas horizontales.
	for(int Indice = xSup; Indice <= xInf; Indice++){
		Gotoxy(Indice, ySup); printf("%c", 196);
		Gotoxy(Indice, yInf); printf("%c", 196);
	}

	// Impresi�n de l�neas verticales.
	for(int Indice = ySup; Indice <= yInf; Indice++){
		Gotoxy(xSup, Indice); printf("%c", 179);
		Gotoxy(xInf, Indice); printf("%c", 179);
	}

    // Impresi�n de la l�nea horizontal de t�tulo.
    for(int Indice = 1; Indice <= 79; Indice++){
        Gotoxy(Indice, 2); printf("%c", 196);
	}

	// Impresi�n de la l�nea vertical de t�tulo.
	Gotoxy(67, 1); printf("%c", 179);

	// Impresi�n de las esquinas del marco.
	Gotoxy(xSup, ySup); printf("%c", 218);
	Gotoxy(xInf, yInf); printf("%c", 217);
	Gotoxy(xInf, ySup); printf("%c", 191);
	Gotoxy(xSup, yInf); printf("%c", 192);
	Gotoxy(0, 2); printf("%c", 195);
	Gotoxy(80, 2); printf("%c", 180);
	Gotoxy(67, 0); printf("%c", 194);
	Gotoxy(67, 2); printf("%c", 193);

    Gotoxy(69, 1); printf("Vidas:    ");
    switch(Vidas){
        case 3: Gotoxy(69, 1); printf("Vidas: %c%c%c", 3, 3, 3); break;
        case 2: Gotoxy(69, 1); printf("Vidas: %c%c", 3, 3); break;
        case 1: Gotoxy(69, 1); printf("Vidas: %c", 3); break;
    }
}

// > Funci�n BorrarPantalla. Limpia la pantalla.
void BorrarPantalla(){
    for(int indiceFila = 3; indiceFila <= 24; indiceFila++){
        for(int indiceColumna = 1; indiceColumna <= 79; indiceColumna++){
			Gotoxy(indiceColumna, indiceFila);
			printf(" ");
		}
	}
}
//}

// > Funci�n que imprime la nave del jugador (presentada de color verde en consola).
void NaveJugador(int Posicion_X, int Posicion_Y, bool LimpiarNave){
    if(LimpiarNave != true){
        // > Imprimir Nave.
        Gotoxy((Posicion_X + 1), (Posicion_Y - 1)); printf(COLOR_GREEN "%c" COLOR_RESET, 219);
        Gotoxy((Posicion_X + 2), (Posicion_Y - 1)); printf(COLOR_GREEN "%c" COLOR_RESET, 219);
        printf("\n");
        Gotoxy(Posicion_X, Posicion_Y); printf(COLOR_GREEN "%c" COLOR_RESET, 219);
        Gotoxy((Posicion_X + 1), Posicion_Y); printf(COLOR_GREEN "%c" COLOR_RESET, 219);
        Gotoxy((Posicion_X + 2), Posicion_Y); printf(COLOR_GREEN "%c" COLOR_RESET, 219);
        Gotoxy((Posicion_X + 3), Posicion_Y); printf(COLOR_GREEN "%c" COLOR_RESET , 219);
    } else {
        // > Limpiar Nave.
        Gotoxy((Posicion_X + 1), (Posicion_Y - 1)); printf(" ");
        Gotoxy((Posicion_X + 2), (Posicion_Y - 1)); printf(" ");
        printf("\n");
        Gotoxy(Posicion_X, Posicion_Y); printf(" ");
        Gotoxy((Posicion_X + 1), Posicion_Y); printf(" ");
        Gotoxy((Posicion_X + 2), Posicion_Y); printf(" ");
        Gotoxy((Posicion_X + 3), Posicion_Y); printf(" ");
    }
}

// > Funci�n que imprime la nave enemiga (presentada de color rojo en consola).
void NaveEnemigos(int Posicion_X, int Posicion_Y, bool LimpiarNave){
    if(LimpiarNave != true){
        // > Imprimir Nave.
        Gotoxy(Posicion_X, Posicion_Y); printf(COLOR_RED "%c" COLOR_RESET, 191);
        Gotoxy((Posicion_X + 1), Posicion_Y); printf(COLOR_RED "%c" COLOR_RESET, 220);
        Gotoxy((Posicion_X + 2), Posicion_Y); printf(COLOR_RED "%c" COLOR_RESET, 220);
        Gotoxy((Posicion_X + 3), Posicion_Y); printf(COLOR_RED "%c" COLOR_RESET, 218);
    } else {
        // > Limpiar Nave.
        Gotoxy(Posicion_X, Posicion_Y); printf(" ");
        Gotoxy((Posicion_X + 1), Posicion_Y); printf(" ");
        Gotoxy((Posicion_X + 2), Posicion_Y); printf(" ");
        Gotoxy((Posicion_X + 3), Posicion_Y); printf(" ");
    }

}

// > Funci�n que valida el disparo realizado por el usaurio.
void MovimientoDisparo(int Posicion_X, int Posicion_Y, bool LimpiarMisil){
    if(LimpiarMisil != true){
        Gotoxy(Posicion_X, Posicion_Y); printf("%c", 94);
    } else {
        Gotoxy(Posicion_X, (Posicion_Y + 1)); printf(" ");
    }

}

// > STRUCT que guarda los recorridos de las naves enemigas.
struct NaveEnemiga{
    int Posicion_X;
    int Posicion_Y;
    bool Nave_Muerta;
}NavesEnemigas[60];

// > Funci�n principal: Aqu� se hace el llamado a las otras funciones y se genera el movimiento del jugador.
void SpaceInvaders(){
    int VidasJugador = 3, PuntosJugador = 0, IndiceNaveEnemiga = 0;
    int Posicion_X_NaveJugador = 35, Posicion_Y_NaveJugador = 24;
    int MAXIMO_X_NAVE_ENEMIGA = 77 - 3, Posicion_X_NaveEnemiga = rand() % MAXIMO_X_NAVE_ENEMIGA + 3, Posicion_Y_NaveEnemiga = 3;
    int Posicion_X_Misil, Posicion_Y_Misil;
    bool ContinuarJuego = true; char Tecla;
    do{
        Tecla = getch();

        NaveEnemigos(Posicion_X_NaveEnemiga, Posicion_Y_NaveEnemiga, true);
        NaveJugador(Posicion_X_NaveJugador, Posicion_Y_NaveJugador, true);

        NavesEnemigas[IndiceNaveEnemiga].Posicion_X = Posicion_X_NaveEnemiga;
        NavesEnemigas[IndiceNaveEnemiga].Posicion_Y = Posicion_Y_NaveEnemiga;
        NavesEnemigas[IndiceNaveEnemiga].Nave_Muerta = false;

        if((Posicion_X_NaveJugador >= 2 && Posicion_X_NaveJugador <= 75)){
            switch(Tecla){
                // > Movimiento hacia la derecha:
                case 77:
                case 'd':{
                    Posicion_X_NaveJugador++;
                    break;
                }
                // > Movimiento hacia la izquierda:
                case 75:
                case 'a':{
                    Posicion_X_NaveJugador--;
                    break;
                }
                case 32:{
                    Posicion_X_Misil = Posicion_X_NaveJugador + 1;
                    Posicion_Y_Misil = Posicion_Y_NaveJugador - 2;
                    break;
                }
            }

        } else {
            if(Posicion_X_NaveJugador < 45){
                Posicion_X_NaveJugador = 2;
            } else {
                Posicion_X_NaveJugador = 75;
            }
        }

        MovimientoDisparo(Posicion_X_Misil, Posicion_Y_Misil, false);
        Posicion_Y_NaveEnemiga++;

        if(Posicion_Y_Misil > 3){
           Posicion_Y_Misil--;
        }

        IndiceNaveEnemiga++;

        NaveEnemigos(Posicion_X_NaveEnemiga, Posicion_Y_NaveEnemiga, false);
        NaveJugador(Posicion_X_NaveJugador, Posicion_Y_NaveJugador, false);
        MovimientoDisparo(Posicion_X_Misil, Posicion_Y_Misil, false);


        if(Posicion_Y_NaveEnemiga == 25){
            Gotoxy(2, 1); printf("Una nave enemiga ha logrado aterrizar. Pierde una vida.");
            Posicion_Y_NaveEnemiga = 3;
            Sleep(1000);
            Gotoxy(2, 1); printf("                                                       ");
            VidasJugador--;
            Marco(0, 0, 80, 25, VidasJugador);
            BorrarPantalla();
        }

        if(VidasJugador == 0){
            Gotoxy(2, 1); printf("Ha perdido todas sus vidas. Juego finalizado.");
            ContinuarJuego = false;
            Sleep(1000);
        }

    } while(ContinuarJuego == true);

}

// > Funci�n InicioConsola. Establece las dimensiones, t�tulo y marco de la consola.
void InicioConsola(){
    OcultarCursor();
    SetConsoleTitle("Juego: Space Invaders");
    system("mode con: cols=81 lines=26");
	Marco(0, 0, 80, 25, 3);
}

// > Funci�n MAIN.
int main(){
    srand(time(NULL));
    InicioConsola();
    SpaceInvaders();
    Gotoxy(26, 13);
    printf("--- Gracias por Jugar ---");
    Gotoxy(5, 22);
    getch();
    return 0;
}

