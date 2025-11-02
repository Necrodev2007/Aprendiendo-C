#include <stdio.h>

int main() {
    // Sistema de inventario con punteros
    int inventario[3] = {5, 3, 8};  // Cantidad de 3 ítems
    int *punteros[3];                // Array de punteros
    
    printf("🎮 INVENTARIO INICIAL WII 🎮\n");
    printf("Item 1: %d\n", inventario[0]);
    printf("Item 2: %d\n", inventario[1]); 
    printf("Item 3: %d\n", inventario[2]);
    
    punteros[0] = &inventario[0];
   *punteros[0] += 2;
   punteros[1] = &inventario[1];
   *punteros[1] -= 1;
   punteros[2] = &inventario[2];
   *punteros[2] *= 2; 
    
    printf("\n🎮 INVENTARIO FINAL WII 🎮\n");

printf("Item 1: %d\n", *punteros[0]);
printf("Item 2: %d\n", *punteros[1]);
printf("Item 3: %d\n", *punteros[2]);


 printf("\n🔍 INFORMACIÓN DE MEMORIA:\n");
    printf("Direcciones de ITEMS: 0:%p 1:%p 2:%p\n", punteros[0], punteros[1], punteros[2]);
    printf("Direcciones de PUNTEROS: 0:%p 1:%p 2:%p\n", &punteros[0], &punteros[1], &punteros[2]);
    
}