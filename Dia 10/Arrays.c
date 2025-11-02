#include <stdio.h>
int main()
{

char arreglo[5][20] = {"hola","Xd","sexo","gye","pene"};
printf("Contenido del array:");
for(int i = 0; i < 5; i++){
printf("%s", arreglo[i]);

if(i < 4){
    printf(", ");
}else{
    printf(".");
}

}
printf("\n");
return 0;
}