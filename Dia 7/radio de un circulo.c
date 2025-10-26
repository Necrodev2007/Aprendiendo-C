#include <stdio.h>
#include <math.h>

#define PI 3.14159
int main()
{
float radio, area, longitud;
printf("==========Calculadora de area y longitud de un circulo================");
printf("\n\nIngrese el radio del circulo: ");
scanf("%f", &radio);

area = PI * pow(radio,2);
longitud = 2 * PI * radio;

printf("\n\nArea: %f\nCircunfrencia: %f\n", area, longitud);



    
}