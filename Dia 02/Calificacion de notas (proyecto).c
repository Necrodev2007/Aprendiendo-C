#include <stdio.h>
int main()
{
int mate = 8, cienc = 10, fisic = 9, chmsi = 5; // notas
int op_asing= 0;
//selector de opciones
while(op_asing != 5){
printf("Tus notas finales\n\n1.Matematicas\n2.Ciencia\n3.Fisica\n4.Quimica\n\n5.Cerrar programa\n\nElige una opcion.");    
  scanf("%d", &op_asing);  

//condicionales
if(op_asing == 1){
  printf("Tu nota final en Matematicas es: %d\n", mate);
}
else if(op_asing == 2){
    printf("Tu nota final Ciencias es: %d\n", cienc);
}
else if (op_asing == 3){
    printf("Tu nota final en Fisica es: %d\n", fisic);
}
else if(op_asing == 4){
    printf("Tu nota final en Quimica es: %d\n", chmsi);
}
else if(op_asing == 5){
    print("Exit");
}
else{
    printf("Opcion invalida");
}

}

}
