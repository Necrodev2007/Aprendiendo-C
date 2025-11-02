#include <stdio.h>
#include "calculadora.h"
void calculadora(int n1, int n2, char op){
int r;
char *tx;
switch (op)
{
case '+': 
r = n1 + n2;
tx = "suma";
    break;
case '-':
r = n1 - n2;
tx = "resta";
    break;
    case '*':
r = n1 * n2;
tx = "multiplicacion";
    break;
    case '/':
    if(n2 != 0){
r = n1 / n2;
tx = "division";
    }else {
     printf("\nError: Division por cero!");
    return;
    }
    break;
default:
printf("Operador invalido");
return;
    break;
}
printf("\nResultado de la %s: %d", tx, r);
}