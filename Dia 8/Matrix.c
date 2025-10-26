#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ANCHO 80
#define ALTO 25

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ocultarCursor() {
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 100;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

int main() {
    system("cls");
    system("color 0A"); // Fondo negro, texto verde
    ocultarCursor();
    
    srand(time(NULL));
    
    int matrix[ANCHO][ALTO] = {0};
    int x, y;
    
    printf("MATRIX RAIN - Presiona CTRL+C para salir\n");
    printf("=========================================\n\n");
    
    clock_t inicio = clock();
    
    for(int frame = 0; frame < 100; frame++) { // 100 frames
        // Mover y actualizar gotas
        for(x = 0; x < ANCHO; x++) {
            for(y = ALTO-1; y > 0; y--) {
                matrix[x][y] = matrix[x][y-1];
            }
            matrix[x][0] = (rand() % 10); // Nuevo número arriba
        }
        
        // Dibujar matriz
        for(y = 0; y < ALTO; y++) {
            for(x = 0; x < ANCHO; x++) {
                gotoxy(x, y + 3); // +3 para bajar el dibujo
                if(matrix[x][y] > 0) {
                    printf("%d", matrix[x][y]);
                } else {
                    printf(" ");
                }
            }
        }
        
        // Añadir nuevas gotas aleatorias
        for(int i = 0; i < 5; i++) {
            x = rand() % ANCHO;
            matrix[x][0] = rand() % 10;
        }
        
        Sleep(100); // Velocidad de la lluvia
    }
    
    clock_t fin = clock();
    double tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    
    system("color 07"); // Volver a colores normales
    system("cls");
    
    printf("=== MATRIX RAIN COMPLETADO ===\n\n");
    printf("Tiempo de ejecucion: %.2f segundos\n", tiempo);
    printf("Frames procesados: 100\n");
    printf("Resolucion: %dx%d\n", ANCHO, ALTO); // CORREGIDO: faltaban paréntesis
    printf("\nPresiona Enter para salir...");
    getchar();
    
    return 0;
}