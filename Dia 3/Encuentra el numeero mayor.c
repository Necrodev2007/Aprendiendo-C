#include <stdio.h>
int main()
{

    float n1,n2,n3, mayor;//Variables
    printf("\nEncontrar el numero mayor\n\n");
 printf("Ingrese el primer numero:");
    scanf("%f", &n1);
 printf("Ingrese el segundo numero: ");
    scanf("%f", &n2);
 printf("Ingrese el tercer numero: ");
    scanf("%f", &n3);

if(n1>n2&&n1>n3){
 mayor=n1;
}else if(n2>=n1&&n2>=n3)
{
    mayor=n2;
}else{
    mayor=n3;
}
printf("El mayor es: %.3f\n", mayor);
return 0;
}









