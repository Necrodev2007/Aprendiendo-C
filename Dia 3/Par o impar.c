// ¿Puedes hacer un programa que determine si un número es?
// - Positivo, Negativo o Cero
// - Par o Impar
#include <string.h>
#include <stdio.h>

int main() {
int num;
printf("Ingresa un número: ");
scanf("%d", &num);
int poi = num % 2;
char pei[7];
if(poi == 0){
    strcpy(pei,"par");
}else{
    strcpy(pei,"impar");
}
if(num > 0){
    printf("El numero es positivo %s\n", pei);
}else if(num < 0){
    printf("El numero es negativo %s\n", pei);
}else{
    printf("El numero es 0");
}
return 0;
}