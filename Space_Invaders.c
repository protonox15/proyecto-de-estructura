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
int Score = 500;
struct Jugador{
int PuntuacionFinal;
char Iniciales[10];
};

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

//{ Funciones del Sistema.
// > Funcion Gotoxy. Permite posicionar el cursos en cualquier parte de la pantalla.
void Gotoxy(int x,int y){
    // Sea X la columna, y Y la fila.
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

// > Funcion OcultarCursor, que hace el cursor [_] invisible.
void OcultarCursor(){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hcon, &cci);
}

//(Xavier Carrasco)
void MostrarTemporizador(int segundos_restantes) {
    Gotoxy(1, 1);//xavier carrasco
    int minutos = segundos_restantes / 60;
    int segundos = segundos_restantes % 60;
    printf(" Tiempo: %02d:%02d", minutos, segundos);
}



void MostrarScore(int Score) {//JOANVERA
    Gotoxy(55, 1);
    printf(" Score: %d", Score);
}//JOANVERA



// > Funcion Marco. Permite dibujar un recuadro con dimensiones especificas.
void Marco(int xSup, int ySup, int xInf, int yInf, int Vidas, int segundos_restantes){ //(xavier carrasco) segundos restantes
	// Impresionn de lineas horizontales.
	for(int Indice = xSup; Indice <= xInf; Indice++){
		Gotoxy(Indice, ySup); printf("%c", 196);
		Gotoxy(Indice, yInf); printf("%c", 196);
	}

	// Impresion de lineas verticales.
	for(int Indice = ySup; Indice <= yInf; Indice++){
		Gotoxy(xSup, Indice); printf("%c", 179);
		Gotoxy(xInf, Indice); printf("%c", 179);
	}

    // Impresion de la linea horizontal de titulo.
    for(int Indice = 1; Indice <= 79; Indice++){
        Gotoxy(Indice, 2); printf("%c", 196);
	}

	// Impresion de la linea vertical de titulo.
	Gotoxy(67, 1); printf("%c", 179);

	// Impresion de las esquinas del marco.
	Gotoxy(xSup, ySup); printf("%c", 218);
	Gotoxy(xInf, yInf); printf("%c", 217);
	Gotoxy(xInf, ySup); printf("%c", 191);
	Gotoxy(xSup, yInf); printf("%c", 192);
	Gotoxy(0, 2); printf("%c", 195);
	Gotoxy(80, 2); printf("%c", 180);
	Gotoxy(67, 0); printf("%c", 194);
	Gotoxy(67, 2); printf("%c", 193);

    MostrarTemporizador(segundos_restantes);//(xavier carrasco)
    MostrarScore(Score);//JOANVERA
    Gotoxy(69, 1); printf("Vidas:    ");
    switch(Vidas){
        case 3: Gotoxy(69, 1); printf("Vidas: %c%c%c", 3, 3, 3); break;
        case 2: Gotoxy(69, 1); printf("Vidas: %c%c", 3, 3); break;
        case 1: Gotoxy(69, 1); printf("Vidas: %c", 3); break;
    }
}

// > Funcion BorrarPantalla. Limpia la pantalla.
void BorrarPantalla(){
    for(int indiceFila = 3; indiceFila <= 24; indiceFila++){
        for(int indiceColumna = 1; indiceColumna <= 79; indiceColumna++){
			Gotoxy(indiceColumna, indiceFila);
			printf(" ");
		}
	}
}
//}

// > Funcion que imprime la nave del jugador (presentada de color verde en consola).
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

// > Funcion que imprime la nave enemiga (presentada de color rojo en consola).
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

// > Funcion que valida el disparo realizado por el usuario.
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

// > Funcion principal: Aqui se hace el llamado a las otras funciones y se genera el movimiento del jugador.
void SpaceInvaders(){
    int VelocidadNivel = 200;
    int VidasJugador = 3, PuntosJugador = 0, IndiceNaveEnemiga = 0, IndiceNaves = 0, ContadorNaves, CantidadNaves = 0;
    int Posicion_X_NaveJugador = 35, Posicion_Y_NaveJugador = 24;
    int MAXIMO_X_NAVE_ENEMIGA = 77 - 3; //Posicion_X_NaveEnemiga = rand() % MAXIMO_X_NAVE_ENEMIGA + 3, Posicion_Y_NaveEnemiga = 3;
    int Posicion_X_Misil, Posicion_Y_Misil;
    int tiempo_inicial = time(NULL);//xavier carrasco
    int tiempo_restante = 60;//xavier carrasco
    bool ContinuarJuego = true; char Tecla;
    time_t inicioTiempo = time(NULL);//xavier carrasco
    bool MisilActivo = false; //xavier carrasco
    int VelocidadJugador = 50; //xavier carrasco
    // > Carga de las naves enemigas que apareceran por consola.

    for(int Indice = 0; Indice < 60; Indice++){
        NavesEnemigas[Indice].Posicion_X = rand() % MAXIMO_X_NAVE_ENEMIGA + 3;
        NavesEnemigas[Indice].Posicion_Y = 3;
        NavesEnemigas[Indice].Nave_Muerta = false;
    }

    do{
        if(kbhit()) Tecla = getch();

        ContadorNaves = IndiceNaves;
        do{
            if(NavesEnemigas[ContadorNaves].Nave_Muerta != true){
                NaveEnemigos(NavesEnemigas[ContadorNaves].Posicion_X, NavesEnemigas[ContadorNaves].Posicion_Y, true);
            }
            ContadorNaves++;
        } while(ContadorNaves <= CantidadNaves);

        NaveJugador(Posicion_X_NaveJugador, Posicion_Y_NaveJugador, true);

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
                    MisilActivo = true;//xavier carrasco
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

         if (MisilActivo) { //xavier carrasco
        for (int Indice = 0; Indice < 60; Indice++) {//xavier carrasco
        if (!NavesEnemigas[Indice].Nave_Muerta &&//xavier carrasco
            Posicion_X_Misil >= NavesEnemigas[Indice].Posicion_X &&//xavier carrasco
            Posicion_X_Misil <= NavesEnemigas[Indice].Posicion_X + 3 &&//xavier carrasco
            Posicion_Y_Misil == NavesEnemigas[Indice].Posicion_Y) {//xavier carrasco
            NavesEnemigas[Indice].Nave_Muerta = true;//xavier carrasco
            BorrarPantalla();
            Score += 250;
            MisilActivo = false;//xavier carrasco
            Posicion_Y_Misil = -1; // Mueve el misil fuera del área de juego //xavier carrasco

            CantidadNaves++;
            break;//xavier carrasco
        }//xavier carrasco
    }//xavier carrasco
}//xavier carrasco

        MovimientoDisparo(Posicion_X_Misil, Posicion_Y_Misil, false);

         if (MisilActivo && Posicion_Y_Misil > 3) {//xavier carrasco
           Posicion_Y_Misil--;//xavier carrasco
        } else {//xavier carrasco
           MisilActivo = false;//xavier carrasco
        }//xavier carrasco

        ContadorNaves = IndiceNaves;
        do{
            if(NavesEnemigas[ContadorNaves].Nave_Muerta != true){
                NavesEnemigas[ContadorNaves].Posicion_Y++;
            }
            ContadorNaves++;
        } while(ContadorNaves <= CantidadNaves);

        IndiceNaveEnemiga++;

        ContadorNaves = IndiceNaves;
        do{
            if(NavesEnemigas[ContadorNaves].Nave_Muerta != true){
               NaveEnemigos(NavesEnemigas[ContadorNaves].Posicion_X, NavesEnemigas[ContadorNaves].Posicion_Y, false);
            }
            ContadorNaves++;
        } while(ContadorNaves <= CantidadNaves);

        NaveJugador(Posicion_X_NaveJugador, Posicion_Y_NaveJugador, false);
        MovimientoDisparo(Posicion_X_Misil, Posicion_Y_Misil, false);

        for(int Indice = 0; Indice < 60; Indice++){
            if(NavesEnemigas[Indice].Posicion_Y == 24){
                Gotoxy(2, 1); printf("El enemigo ha logrado aterrizar. Pierde una vida.");
                NavesEnemigas[Indice].Posicion_Y = 3;
                NavesEnemigas[Indice].Nave_Muerta = true;
                Sleep(1000);
                Gotoxy(2, 1); printf("                                                       ");
                VidasJugador--;
                int tiempoRestante = 60 - (int)difftime(time(NULL), inicioTiempo); //Xavier Carrasco
                Marco(0, 0, 80, 25, VidasJugador, tiempoRestante); //Xavier Carrasco
                BorrarPantalla();
                CantidadNaves++;
                break;
            }
        }


        if(VidasJugador == 0){
            Gotoxy(30, 1); printf("Juego finalizado.");
            ContinuarJuego = false;
            Sleep(1000);
        }

        int tiempo_actual = time(NULL); //Xavier Carrasco
        int segundos_transcurridos = tiempo_actual - tiempo_inicial; //Xavier Carrasco
        tiempo_restante = 60 - segundos_transcurridos; //Xavier Carrasco

        MostrarTemporizador(tiempo_restante); //Xavier Carrasco
        MostrarScore(Score); //JOANVERA
        if (tiempo_restante <= 0) { //Xavier Carrasco
            Gotoxy(30, 1);
            printf("Se ha agotado el tiempo.");
            ContinuarJuego = false;
            Sleep(VelocidadNivel);
        } //Xavier carrasco

        if (Tecla == 77 || Tecla == 'd' || Tecla == 75 || Tecla == 'a') {
    Sleep(VelocidadJugador);
} else {
    Sleep(VelocidadNivel);
}

        switch(ContadorNaves){
            case 10: VelocidadNivel = 100; break;
            case 20:VelocidadNivel = 50; break;
        }

    } while(ContinuarJuego == true);

}

int CreaArch(){ //JOANVERA
    struct Jugador jugador;
    int Error = 0;
    FILE *Punt_Arch;
    if((Punt_Arch = fopen("Jugadores.dat", "a+b")) != NULL){
        fflush(stdin);
        printf("Ingrese sus iniciales:");
        fgets(jugador.Iniciales, 10, stdin);
        jugador.PuntuacionFinal = Score;
        fwrite(&jugador, sizeof(jugador), 1, Punt_Arch);
        fclose(Punt_Arch);
    }//JOANVERA
    else
    {
    printf("Error durante la creación o apertura del Archivo.");
    Error = 1;
    }
    return Error;
}//JOANVERA

int LeerArch(){
    int Error = 0;
    FILE *Punt_Arch;
    struct Jugador jugador;
    if((Punt_Arch = fopen("Jugadores.dat", "rb")) != NULL){
        fread(&jugador, sizeof(jugador), 1, Punt_Arch);
        Gotoxy(29, 15); printf("JUGADORES\n");
        Gotoxy(20, 17); printf("INICIALES\t\t\tPUNTUACION\n");
        int ContadorGotoxy = 18;

        while(!feof(Punt_Arch)){
            Gotoxy(20, ContadorGotoxy); printf("%s", jugador.Iniciales);
                        Gotoxy(50, ContadorGotoxy); printf("%d", jugador.PuntuacionFinal);
            ContadorGotoxy++;
            fread(&jugador, sizeof(jugador), 1, Punt_Arch);
        }
        fclose(Punt_Arch);
    } else {
        printf("Error durante la creación o apertura del Archivo.");
        Error = 1;
    }
    return Error;
}//JOANVERA

// > Funcion InicioConsola. Establece las dimensiones, titulo y marco de la consola.
void InicioConsola(){
    OcultarCursor();
    SetConsoleTitle("Juego: Space Invaders");
    system("mode con: cols=81 lines=26");
	Marco(0, 0, 80, 25, 3, 60);//(xavier carrasco)(60)
}

// Funcion que muestra el menu de inicio y espera la entrada del usuario. //(Xavier Carrasco)
void MostrarMenuInicio(){
    Gotoxy(32, 10);
    printf("SPACE INVADERS");
    Gotoxy(26, 12);
    printf("Presione ENTER para comenzar");
    Gotoxy(28, 14);
    printf("Presione ESC para salir");

    while(1){
        int tecla = getch();
        if(tecla == 13) {
            break;
        }
        else if(tecla == 27) {
            exit(0);
        }
    }

    BorrarPantalla(); // Limpia la pantalla antes de que comience el juego
}

// > Funcion MAIN.
int main(){
    srand(time(NULL));
    InicioConsola();
    MostrarMenuInicio();
    SpaceInvaders();
    Gotoxy(26, 13);
    printf("--- Gracias por Jugar ---");
    Sleep(1000);//JOANVERA
    BorrarPantalla();//JOANVERA
    Gotoxy(26, 13);//JOANVERA
    getch();
    int Error = 0;//JOANVERA
    Error = CreaArch();//JOANVERA
    if(!Error){//JOANVERA
        LeerArch();//JOANVERA
    }//JOANVERA
    return 0;
}
