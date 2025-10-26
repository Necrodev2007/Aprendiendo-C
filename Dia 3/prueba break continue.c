#include <stdio.h>
int main()
{
int a;
int num, suma = 0;
for(a = 1;a<=4;++a){
printf("Ingrese el numero %d:", a);
scanf("%d", &num);
if(num<0){
    break;
}
suma += num;
}
printf("La suma es: %d\n", suma);
return 0;
}