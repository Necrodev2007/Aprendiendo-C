#include <stdio.h>
#include <stdlib.h>
int main(){
char g1, g2;
int op;
float gr, grf;
printf("\n======Conversor de temperatura======\n\nOpciones:\n\n1.Celsius a Fahrenheit\n2.Fahrenheit a Celsius\n\nSeleccione: ");
scanf("%d",&op);

system("cls");

if(op != 1 && op != 2){
    printf("Opcion no valida\n");
    return 1;
}
  printf("Ingrese la temperatura a convertir: ");
    scanf("%f", &gr);
    
    system("cls");

if(op == 1){
 
grf = (gr * 9/5) + 32;

g1 = 'C';
g2 = 'F';
}else{
grf = (gr - 32) * 5/9;

g1 = 'F';
g2 = 'C';
}
printf("%.1f %c%c equivalen a %.1f %c%c\n",gr,248,g1,grf,248,g2);
return 0;
}







