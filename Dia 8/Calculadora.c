#include <stdio.h>
int main()
{
float n1,n2,result;
char op;
printf("\n=======Calculadora=======\n\n");
printf("Ingrese primer numero: ");
scanf("%f", &n1);
while ((getchar()) != '\n');
printf("Ingrese el operador (+,-,*,/): ");
scanf("%c", &op);
printf("Ingrese el segundo numero: ");
scanf("%f", &n2);

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
result = n1 / n2;
break;
}
printf("Resultado de la operacion: %.2f", result);
return 0;
}