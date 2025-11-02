#include <stdio.h>
#include "calculadora.h"

int main() {
    int a, b;
    char o;
    
    printf("\n///////Calculadora///////\n");
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("\nIngrese el operador (+,-,*,/): ");
    scanf(" %c", &o);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    
    calculadora(a, b, o);
    return 0;
}