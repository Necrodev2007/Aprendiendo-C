#include <stdio.h>
int main()
{
int n1, n2;
char op;
printf("\n=====Calculadora=====\n\n");
printf("Ingrese el primer numero: ");
scanf("%d",&n1);
while(getchar() != '\n');
printf("Ingrese el operador(+,-,*,/): ");
scanf("%c",&op);
printf("ingrese el segundo numero: ");
scanf("%d",&n2);

switch (op)
{
case '+':
printf("%d + %d = %d", n1,n2,n1+n2);
    break;
case '-':
printf("\n%d - %d = %d", n1,n2,n1-n2);
    break;
case '*':
printf("\n%d * %d = %d", n1,n2,n1*n2);
    break;

case '/':
printf("\n%d / %d = %d", n1,n2,n1/n2);
    break;
default: 
printf("Ingrese un operador valido (+,-,*,/)");
break;
}
}