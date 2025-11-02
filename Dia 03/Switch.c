#include <stdio.h>
int main()
{

char calc;
double n1,n2;
printf("Ingrese un operador(+,-,*,/) ");
scanf("%c",&calc);
printf("Ingrese un numero: ");
scanf("%lf", &n1);
printf("Ingrese otro numero: ");
scanf("%lf", &n2);


switch(calc){
case '+':
printf("%.2lf + %.2lf = %.2lf",n1,n2,n1+n2);
break;
case '-':
printf("%.2lf - %.2lf = %.2lf",n1,n2,n1-n2);
break;
case '*':
printf("%.2lf * %.2lf = %.2lf",n1,n2,n1*n2);
break;
case '/':
printf("%.2lf / %.2lf = %.2lf",n1,n2,n1/n2);
break;

default:
printf("Syntax Error");
}
return 0;
}