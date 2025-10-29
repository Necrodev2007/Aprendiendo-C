#include <stdio.h>
#include <stdlib.h>
int main()
{
char re;
 do{
system("cls");
int integrantes = 0;
//Pide al usuario la cantidad de integrantes, valida la entrada y la almacena en int integrantes;
printf("\n%cCuantos integrantes tiene tu familia?\n\nRespuesta: ",168);
while(scanf("%d", &integrantes) != 1 || integrantes <= 0 ){
    printf("Ingrese un numero valido: ");
    while((getchar()) != '\n');
}
//Limpia el buffer y la pantalla
while((getchar()) != '\n');
system("cls"); 

//Captura el nombre de cada integrante con un blucle for
char nombres[integrantes][20];
printf("\nIngresa el nombre de cada integrante\n\n");

for(int i = 0; i < integrantes; i++){
    printf("Integrante %d: ", i + 1);
    scanf("%19s", nombres[i]); 
}
system("cls");
//Pregunta si se quiere ver la lista y valida la entrada
char op;
printf("\n%cMostrar lista de integrantes?(y/n):\n", 168);
while(scanf(" %c", &op) != 1 || (op != 'y' && op != 'Y' && op != 'n' && op != 'N')){
    while((getchar()) != '\n');
}
system("cls");
 //Recorre el array de nombres y muesta el de cada integrante
 if(op == 'y' || op == 'Y' ){
printf("\nIntegrantes de tu familia\n\n");
for(int i = 0; i < integrantes; i++){
printf("%d.%s\n", i + 1, nombres[i]);
}
}else
{
//si s desea registrar otra familia rinicia el programa mediant el bucle do while
system("cls");
printf("\n%cDesea registrar otra familia?(y/n):\n",168);
while(scanf(" %c", &re) != 1 || (re != 'y' && re != 'Y' && re != 'n' && re != 'N')){
while((getchar()) != '\n');
}


}
}while(re == 'y' || re == 'Y');

  return 0;
}