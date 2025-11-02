#include <stdio.h>
#include <stdlib.h>
int main()
{
int suposicion, diferencia, intentos = 0, numero_secreto = 43;

 printf("¡Bienvenido al juego de adivinanza!\n");
    
    do {
        printf("Ingresa tu suposici%cn: ", 162);
        while(scanf("%d", &suposicion) != 1 || suposicion < 0)
        {
            printf("\n Error, ingresa solo numeros positivos.");
            while((getchar()) != '\n');
        }
      continue;
      
        intentos++;
        
        diferencia = abs(suposicion - numero_secreto);
        
        if (suposicion == numero_secreto) {
            printf("¡Correcto! El número era %d. Intentos: %d\n", 
                   numero_secreto, intentos);
            break;
        }
        else if (diferencia <= 5) {
            printf("¡Muy caliente! Estás a 5 o menos del número\n");
        }
        else if (diferencia <= 10) {
            printf("Caliente. Estás dentro de 10 del número\n");
        }
        else {
            printf("Frío. Estás a más de 10 del número\n");
        }
        
    } while (1);
    
    return 0;
}