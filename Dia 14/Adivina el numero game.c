#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int generarAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {

    srand(time(NULL));

    int numeroA, op_m1, op_m2; 
    printf("\n ====== Adivina El Numero Game ======\n\n");
    printf(" 1.Jugar\n 2.Salir\n\n Selecciona una opcion: ");
    while(scanf("%d", &op_m1) != 1 || op_m1 > 2 || op_m1 < 1)
    {
        printf("\n Opcion invalida, ingrese una de las opciones enumeradas: ");
    
        while((getchar()) != '\n');
    }

    while((getchar()) != '\n');
    if(op_m1 == 1)
    {
        system("cls");

    printf("\n ====== Nivel De Dificultad ======\n\n 1.Facil (5 intentos)\n 2.Medio (7 intentos)\n 3.Dificil (10 intentos)\n\n Selecciona una opcion: ");

     while(scanf("%d", &op_m2) != 1 || op_m2 > 3 || op_m2 < 1)
    {
        printf(" Opcion invalida, ingrese una de las opciones enumeradas: ");
    
        while((getchar()) != '\n');
      }
     }else
     {
        system("cls");
         printf("\n Saliendo del programa...\n");
        return 0;
     }
    
    int xay, intent; 
    
  switch(op_m2)
  {
    case 1:
    intent = 5;
  numeroA = generarAleatorio(0, 20);
  xay = 20;
   break;

  case 2:
  intent = 7;
  numeroA = generarAleatorio(0, 50);
  xay = 50;
   break;

  case 3:
  intent = 10;
  numeroA = generarAleatorio(0, 100);
  xay = 100;
   break;
  }

   system("cls");

int num_adv, win = 0;

printf(" ====== Empezemos ======\n\n");

do
{
  
printf(" Adivina el numero del 0 al %d. \n (%d intentos): ", xay, intent);
while(scanf("%d", &num_adv) != 1  || num_adv < 0 || num_adv > xay)
{
    system("cls");
printf(" Error, ingresa un numero valido (0-%d): ", xay);
while((getchar()) != '\n');
}

intent--;

int intent_used = 0;

intent_used++;

int drf = abs(num_adv - numeroA);

if(num_adv == numeroA)
{
    system("cls");
printf("\n %cFelicidades! Adivinaste el numero %d en %d intentos.\n", 173,  numeroA , intent_used );
win = 1;
break;
}else if(drf <= 5)
{
printf("\n %cCALIENTE! Est%cs a 5 o menos del n%cmero secreto.", 173, 160, 163);
}else if(drf <= 10)
{
printf("\n Cerca, estas a 10 o menos del numero.");
}else
{
    printf("\n Lejos, estas a mas de 10 del numero");
}

}while(intent > 0);
 
if(win == 0)
{
    system("cls");
printf("\n %cPerdiste!, se te acabaron los intentos.\n", 173);
}
  return 0;
}