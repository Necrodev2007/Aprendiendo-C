#include <stdio.h>
#include <stdlib.h>

int main() {
    int op;
    float gr;
    
    printf("\n====== Conversor de temperatura ======\n\n");
    printf("1. Celsius a Farenheit\n2. Farenheit a Celsius\nSeleccione: ");
    scanf("%d", &op);
    
    if (op == 1 || op == 2) {
        system("cls");
        printf("Ingrese temperatura: ");
        scanf("%f", &gr);
        
        float resultado = (op == 1) ? (gr * 9/5) + 32 : (gr - 32) * 5/9;
        char *desde = (op == 1) ? "C" : "F";
        char *hacia = (op == 1) ? "F" : "C";
        
        system("cls");
        printf("\n%.1f %c%s = %.1f %c%s\n", gr, 248, desde, resultado, 248, hacia);
    } else {
        printf("Opción no válida\n");
    }
    
    return 0;
}