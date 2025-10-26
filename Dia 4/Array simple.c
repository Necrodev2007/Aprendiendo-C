#include <stdio.h>
void lista(int arr[]);

int main(){
char opcion;
int numeros[10];
printf("Ingrese 10 numeros: ");
for(int i = 0;i<10;i++){

scanf("%d",&numeros[i]);
}
while(getchar() != '\n');
printf("Mostrar lista?(s/n)");
scanf("%c", &opcion);

switch(opcion){
case 's':
case'S':
lista(numeros);
printf("\n");
break;
case 'n':
case'N':
printf("exit...\n");
break;
default:
printf("Error");
break;
}
return 0;
}
void lista(int arr[]){

printf("\nlista de numeros\n\n");
for(int i = 0;i<10;i++){
printf("%d%d\n", i, arr[i]);
}
}