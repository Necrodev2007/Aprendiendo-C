#include <stdio.h>
void operaciones(int num1,int num2);
int main()
{
// Declara las variables necesarias y pide los 2 numeros.
int n1,n2;
printf("Ingrese 2 numeros separados por espacios: ");
if(scanf("%d %d",&n1,&n2)!= 2){
    printf("Debe ingresar 2 numeros validos\n");
    return 1;
}
// llama a la funcion operaciones y le da los dos parametros a usar.
operaciones(n1,n2);
}
// Funcion que realiza las operaciones.
void operaciones(int num1,int num2)
{
//Declara las variables y realiza las operaciones.
int suma = num1+num2;
int resta = num1-num2;
int multi = num1*num2;
int div = 0;
//imprime los resultados de forma ordenada.

  if(num2 != 0) {
        int div = num1 / num2;
        printf("Division: %d\n", div);
    } else {
        printf("Division: No definida\n");
    }
    printf("\n=====Resultados=====\n\n");
printf("Suma: %d\nResta: %d\nMultiplicacion: %d\nDivision: %d\n", suma,resta,multi,div);
}
