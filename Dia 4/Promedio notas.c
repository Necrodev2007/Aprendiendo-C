#include <stdio.h>
void promedio(float notas,int materias);
int  main()
{
float nums[8],sum = 0;
int i,n;
printf("Cantidad De Materias: ");
scanf("%d", &n);

for(i = 0; i < n; i++)
{
printf("Nota de materia %d: ", i+1);
scanf("%f", &nums[i]);
sum += nums[i];
}
promedio(sum, n);
return 0;
}
void promedio(float notas, int materias){

float pro = notas / materias;
printf("Promedio de notas: %.2f\n", pro);
return;
}