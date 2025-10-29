#include <stdio.h>
long Factorial(long numero);
int main()
{



int numero;
printf("Ingresa un numero\n");
scanf("%d", &numero);
for(int i = 0; i <= numero; i++){
    printf("%ld\n", Factorial(i));
}
}
long Factorial(long numero)
{

if(numero <= 1){
    return 1;
}else{

    return(numero * Factorial(numero-1));
}



}