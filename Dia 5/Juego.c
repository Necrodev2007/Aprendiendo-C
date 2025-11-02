#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

#define ANCHO 40
#define ALTO 20
#define MAX_VIDAS 3
#define MAX_RECURSOS 8

int nivel = 1;
int vidas = MAX_VIDAS;
int recursos_recogidos = 0;
int recursos_totales = MAX_RECURSOS;

typedef struct {
    int x, y;
} Posicion;

Posicion jugador;
Posicion enemigos[15];
Posicion recursos[MAX_RECURSOS];

// Función para configurar el terminal en modo no canónico
void configurarTerminal() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

// Función para restaurar la configuración del terminal
void restaurarTerminal() {
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    oldt.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// Función para leer una tecla sin esperar Enter
int leerTecla() {
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    
    if (FD_ISSET(STDIN_FILENO, &fds)) {
        return getchar();
    }
    return -1;
}

void inicializarJuego() {
    // Posición inicial del jugador
    jugador.x = ANCHO / 2;
    jugador.y = ALTO / 2;
    
    // Inicializar enemigos
    for(int i = 0; i < 8 + nivel; i++) {
        enemigos[i].x = rand() % (ANCHO - 4) + 2;
        enemigos[i].y = rand() % (ALTO - 4) + 2;
    }
    
    // Inicializar recursos
    recursos_recogidos = 0;
    recursos_totales = MAX_RECURSOS + nivel;
    
    for(int i = 0; i < recursos_totales; i++) {
        int posicionValida = 0;
        int intentos = 0;
        
        while(!posicionValida && intentos < 100) {
            recursos[i].x = rand() % (ANCHO - 4) + 2;
            recursos[i].y = rand() % (ALTO - 4) + 2;
            
            posicionValida = 1;
            
            // Verificar que no esté en la posición del jugador
            if(recursos[i].x == jugador.x && recursos[i].y == jugador.y) {
                posicionValida = 0;
            }
            
            // Verificar que no esté en posición de enemigos
            for(int j = 0; j < 8 + nivel; j++) {
                if(recursos[i].x == enemigos[j].x && recursos[i].y == enemigos[j].y) {
                    posicionValida = 0;
                    break;
                }
            }
            
            // Verificar que no esté muy cerca de otros recursos
            for(int j = 0; j < i; j++) {
                int distX = abs(recursos[i].x - recursos[j].x);
                int distY = abs(recursos[i].y - recursos[j].y);
                if(distX < 3 && distY < 3) {
                    posicionValida = 0;
                    break;
                }
            }
            
            intentos++;
        }
    }
}

void dibujarTablero() {
    system("clear");
    
    printf("=== JUEGO DE EVASION ===\n");
    printf("Nivel: %d | Vidas: %d | Recursos: %d/%d\n\n", nivel, vidas, recursos_recogidos, recursos_totales);
    
    // Dibujar tablero
    for(int y = 0; y < ALTO; y++) {
        for(int x = 0; x < ANCHO; x++) {
            // Bordes
            if(x == 0 || x == ANCHO - 1 || y == 0 || y == ALTO - 1) {
                printf("█");
            }
            // Jugador
            else if(x == jugador.x && y == jugador.y) {
                // Personaje humano con caracteres
                if(y == jugador.y) {
                    printf(" O ");  // Cabeza
                    x += 2;
                }
            }
            // Enemigos
            else {
                int esEnemigo = 0;
                int esRecurso = 0;
                
                // Verificar enemigos
                for(int i = 0; i < 8 + nivel; i++) {
                    if(x == enemigos[i].x && y == enemigos[i].y) {
                        printf("𓂀");  // Enemigo egipcio
                        x += 2; // Avanzar porque el carácter ocupa más espacio
                        esEnemigo = 1;
                        break;
                    }
                }
                
                if(!esEnemigo) {
                    // Verificar recursos
                    for(int i = 0; i < recursos_totales; i++) {
                        if(recursos[i].x != -1 && x == recursos[i].x && y == recursos[i].y) {
                            printf("•");  // Recurso
                            esRecurso = 1;
                            break;
                        }
                    }
                    
                    if(!esRecurso && !esEnemigo) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    
    printf("\nControles: WASD para mover | Q para salir\n");
    printf("Objetivo: Recolecta todos los • evitando los 𓂀\n");
}

void dibujarPersonajeCompleto(int x, int y) {
    // Esta función dibuja un personaje más detallado
    printf("\033[%d;%dH O ", y, x);     // Cabeza
    printf("\033[%d;%dH|", y+1, x+1);   // Torso
    printf("\033[%d;%dH/ \\", y+2, x);  // Piernas
}

void moverEnemigos() {
    for(int i = 0; i < 8 + nivel; i++) {
        // Movimiento más inteligente: 70% aleatorio, 30% hacia el jugador
        int direccion;
        if(rand() % 100 < 70) {
            direccion = rand() % 4;  // Movimiento aleatorio
        } else {
            // Movimiento hacia el jugador
            if(abs(jugador.x - enemigos[i].x) > abs(jugador.y - enemigos[i].y)) {
                direccion = (jugador.x > enemigos[i].x) ? 1 : 0;
            } else {
                direccion = (jugador.y > enemigos[i].y) ? 3 : 2;
            }
        }
        
        int nuevoX = enemigos[i].x;
        int nuevoY = enemigos[i].y;
        
        switch(direccion) {
            case 0: if(enemigos[i].x > 1) nuevoX--; break;  // Izquierda
            case 1: if(enemigos[i].x < ANCHO - 2) nuevoX++; break;  // Derecha
            case 2: if(enemigos[i].y > 1) nuevoY--; break;  // Arriba
            case 3: if(enemigos[i].y < ALTO - 2) nuevoY++; break;  // Abajo
        }
        
        // Verificar que no se salga de los bordes
        if(nuevoX >= 1 && nuevoX < ANCHO - 1 && nuevoY >= 1 && nuevoY < ALTO - 1) {
            enemigos[i].x = nuevoX;
            enemigos[i].y = nuevoY;
        }
    }
}

int verificarColisiones() {
    // Verificar colisión con enemigos
    for(int i = 0; i < 8 + nivel; i++) {
        if(jugador.x == enemigos[i].x && jugador.y == enemigos[i].y) {
            return 1; // Colisión con enemigo
        }
    }
    
    // Verificar recolección de recursos
    for(int i = 0; i < recursos_totales; i++) {
        if(recursos[i].x != -1 && jugador.x == recursos[i].x && jugador.y == recursos[i].y) {
            recursos[i].x = -1; // Marcar como recogido
            recursos_recogidos++;
            return 2; // Recurso recogido
        }
    }
    
    return 0; // Sin colisiones
}

void siguienteNivel() {
    nivel++;
    printf("\n¡NIVEL %d COMPLETADO!\n", nivel - 1);
    printf("¡Felicidades! Pasando al nivel %d\n", nivel);
    printf("Presiona Enter para continuar...");
    
    // Limpiar buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
    
    inicializarJuego();
}

int main() {
    srand(time(NULL));
    
    // Configurar terminal para lectura directa de teclas
    configurarTerminal();
    
    printf("=== JUEGO DE EVASION MEJORADO ===\n");
    printf("Objetivo: Recoge todos los recursos (•)\n");
    printf("Evita a los enemigos (𓂀)\n");
    printf("Personaje: O (cabeza humana)\n");
    printf("Controles: W=Arriba, S=Abajo, A=Izquierda, D=Derecha\n");
    printf("Presiona Enter para comenzar...");
    getchar();
    
    inicializarJuego();
    
    while(vidas > 0) {
        dibujarTablero();
        
        // Leer movimiento
        int tecla = leerTecla();
        if(tecla != -1) {
            char movimiento = tolower(tecla);
            
            if(movimiento == 'q') break;
            
            // Mover jugador
            int nuevoX = jugador.x;
            int nuevoY = jugador.y;
            
            switch(movimiento) {
                case 'w': if(jugador.y > 1) nuevoY--; break;
                case 's': if(jugador.y < ALTO - 2) nuevoY++; break;
                case 'a': if(jugador.x > 1) nuevoX--; break;
                case 'd': if(jugador.x < ANCHO - 2) nuevoX++; break;
            }
            
            // Verificar que la nueva posición sea válida
            if(nuevoX >= 1 && nuevoX < ANCHO - 1 && nuevoY >= 1 && nuevoY < ALTO - 1) {
                jugador.x = nuevoX;
                jugador.y = nuevoY;
            }
            
            // Mover enemigos
            moverEnemigos();
            
            // Verificar colisiones
            int resultado = verificarColisiones();
            
            if(resultado == 1) {
                // Colisión con enemigo
                vidas--;
                if(vidas > 0) {
                    printf("\n¡COLISION! Pierdes una vida. Vidas restantes: %d\n", vidas);
                    sleep(2);
                    // Reiniciar posición del jugador
                    jugador.x = ANCHO / 2;
                    jugador.y = ALTO / 2;
                }
            }
            
            // Verificar si completó el nivel
            if(recursos_recogidos >= recursos_totales) {
                siguienteNivel();
            }
        }
        
        usleep(100000); // 100ms de pausa
    }
    
    // Restaurar configuración del terminal
    restaurarTerminal();
    
    if(vidas <= 0) {
        system("clear");
        printf("=== GAME OVER ===\n");
        printf("¡Te quedaste sin vidas!\n");
        printf("Nivel alcanzado: %d\n", nivel);
    }
    
    printf("Gracias por jugar!\n");
    return 0;
}