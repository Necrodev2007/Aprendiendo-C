#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
float n1,n2,result;
char op;
int op_v = 0;
printf("\n=======Calculadora=======\n\n");
printf("Ingrese primer numero: ");
while(scanf("%f", &n1) != 1){
printf("Eso no es un numero, ingrese un numero valido: ");
while ((getchar()) != '\n');
}
while((getchar()) != '\n');
system("cls");

do {
        printf("Ingrese el operador (+,-,*,/): ");
        scanf(" %c", &op);
        while((getchar()) != '\n');
        
        // Verificar si el operador es válido
        if (op == '+' || op == '-' || op == '*' || op == '/') {
            op_v = 1;  // Es válido
        } else {
            printf("Operador invalido '%c'! Usa +, -, *, o /\n", op);
            system("pause");  // Pausa para que vea el error
            system("cls");
        }
    } while (!op_v);  // Repetir hasta que sea válido
    
system("cls");
printf("\nIngrese el segundo numero: ");
while(scanf("%f", &n2) != 1){
printf("Eso no es un numero, ingrese un numero valido: ");
while ((getchar()) != '\n');
}
system("cls");
switch(op){

case '+':
result = n1 + n2;
break;
case '-':
result = n1 - n2;
break;
case '*':
result = n1 * n2;
break;
case '/':
if(n2 == 0){
    printf("Error, no puedes dividir entre 0");
 return 1;
}
result = n1 / n2;
break;  
}
printf("Resultado de la operacion: %.2f\n", result);
return 0;
}