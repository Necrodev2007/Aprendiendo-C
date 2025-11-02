#include <stdio.h>
int main()
{
//operancion simple 
int num_a = 1, num_b = 4, operacion = num_a + num_b;

printf("Resultado de la operacion: %d\n", operacion);

//Operacioc con scanf 
int num_c, num_e;
printf("Ingrese el primer numero: ");
scanf("%d", &num_c);
printf("Ingrese el segundo numero: ");
scanf("%d", &num_e);
int opscan = num_c + num_e;
printf("Resultado = %d\n",opscan); // se puede cambiar el tipo de operacion

//operacion con Float y scanf

float num_f, num_f2;
printf("ingrese el primer numero float: ");
scanf("%f", &num_f);
printf("Ingrese el segundo numero float: ");
scanf("%f", &num_f2);
float opfloat = num_f + num_f2;
printf("Resultado float = %.3f\n", opfloat );

float resf = opfloat + operacion + opscan;
printf("Resultado final: %.3f\n", resf);

return 0;
}