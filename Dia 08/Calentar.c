#include <stdio.h>
#include <string.h>
void calc(int n1,int n2,char p);
int main(){
int nu1,nu2;
char op;
printf("\n-------Calculadora Basica----------\n\n");
printf("Ingrese el primer numero: ");
scanf("%d", &nu1);
printf("Ingrese el operador (+,-,*,/): ");
scanf(" %c", &op);

printf("Ingrese el segundo numero: ");
scanf("%d", &nu2);
calc(nu1,nu2,op);
return 0;
}
void calc(int n1,int n2,char p){
int r;
char pa[15];
switch(p){

    case '+':
    r = n1 + n2;
strcpy(pa, "suma");
break;
   case '-':
    r = n1 - n2;
strcpy(pa, "resta");
break;
case '*':
r = n1*n2;
strcpy(pa, "multiplicacion");
break;
case '/':
if(n2 <= 0){
    printf("Error, no se puede dividir entre 0");
    break;
}else{
r = n1/n2;
strcpy(pa, "Division");
break;}
}
printf("\nEl resultado de la %s es: %d\n",pa,r);
}