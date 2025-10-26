#include <stdio.h>

int main() {
    int salud = 100;
    int* puntero_salud = &salud;
    
    printf("Salud inicial: %d\n", salud);
    
    *puntero_salud = 80;
    printf("Salud secundaria: %d\n", salud);
*puntero_salud = 120;
printf("Ultima salud: %d\n", salud);
return 0;
}