#include <stdio.h>

// Función corregida
void saludo(char *name, int time)
{
    char* don;  // Puntero a cadena
    
    if(time == 0){
        don = "dia";    // Asignar el puntero directamente
    }else{
        don = "noche";  //  Asignar el puntero directamente
    }
    printf("\nHola %s, como va tu %s?\n", name, don);
    return;
}

int main(){
    char nombre[20] = "Luis";
    int tiempo = 0;
    char s;
    
    printf("Quieres un saludo?(y/n): \n");
    while(scanf(" %c", &s) != 1 || (s != 'y' && s != 'Y' && s != 'n' && s != 'N'))
    {
        printf("Opcion invalida, usa y o n: ");
        while((getchar()) != '\n');
    }

    if(s == 'y' || s == 'Y'){
        saludo(nombre, tiempo);
    }
    
    return 0;  //  Return al final del main
}