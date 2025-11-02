#include <stdio.h>
int suma(int n);

int main(){

int num, res;
printf("Ingrese el numero: ");
scanf("%d", &num);


res = suma(num);

printf("La suma es: %d\n", res);
return 0;
}
int suma(int n){
if(n <= 0)
{
return n + suma(n-1);
}
else{

return n;
}
}