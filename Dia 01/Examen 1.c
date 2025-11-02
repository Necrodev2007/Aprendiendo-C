#include <unistd.h>
#include <stdio.h>
int main()
{
    //Variables
int hijos = 4;
char apellidos[] = "Pineda Sanchez";
char nombres[] = "Luis, Danna, Wilmer, Damaris, Daymar, Daylimar.";
int mascotas = 2;
float dinero = 10.4f;
char letra_fav = 'X';
//Variables scanf
char color_fav[10];
int horas_sueno;
char cancion[20];

sleep(3);

//Imprimir datos
printf("Familia\n\n");
printf("Apellidos: %s\n", apellidos);
printf("Numero de hijos: %d\n", hijos);
printf("Integrantes: %s\n", nombres);
printf("Mascotas: %d\n", mascotas);
printf("Letra favorita: %c\n", letra_fav);
printf("Dinero en la cuenta: %.3f$\n", dinero);

sleep(2);
//Inputs
printf("Color favorito: ");
scanf("%s", color_fav);
printf("Cancion favorita: ");
scanf("%s", cancion);
printf("¿Cuántas horas dormiste anoche?: ");
scanf("%d", &horas_sueno);

sleep(2);

printf("\n\nOtros datos\n\n");
printf("Color favorito: %s\n", color_fav);
printf("Cancion favorita: %s\n", cancion);
printf("Dormiste %d horas\n", horas_sueno);
return 0;
}